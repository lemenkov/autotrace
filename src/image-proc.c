/*
 * SPDX-FileCopyrightText: © 2002-2003 Masatake YAMATO
 * SPDX-FileCopyrightText: © 2017-2025 Peter Lemenkov
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

/* image-proc.c: image processing routines */

#include <assert.h>
#include <glib.h>
#include "logreport.h"
#include "image-proc.h"

#ifndef M_SQRT2
#define M_SQRT2 1.41421356237
#endif

/* RGB to grayscale */
#define LUMINANCE(r, g, b) ((r) * 0.30 + (g) * 0.59 + (b) * 0.11 + 0.5)

/* The part of a pixel that is ink, as far as one of its channels with
   value V tells, on a background whose channel is BG: how far V lies from
   BG, as a fraction of how far it could lie on that side of it, but of no
   less than a quarter of the range: on a background whose channel is near
   0 or 255, a step of noise there would otherwise count as much ink, and
   -preserve-width measured JPEG noise on such a background as wide lines
   (#457).  A channel at the end of the range, as in a black or white
   line, is all the ink there can be on that side, so it counts as whole
   whatever the background.  */

#define MIN_INK_RANGE 64

static float channel_ink(int v, int bg)
{
  if (v < bg)
    return v == 0 ? 1.0F : (float)(bg - v) / (float)MAX(bg, MIN_INK_RANGE);
  if (v > bg)
    return v == 255 ? 1.0F : (float)(v - bg) / (float)MAX(255 - bg, MIN_INK_RANGE);
  return 0.0F;
}

/* Allocate storage for a new distance map with the same dimensions
   as BITMAP and initialize it so that pixels in BITMAP of the colour
   BACKGROUND, or white if it is NULL, are at distance zero and all other
   pixels are at distance infinity.  Then compute the gray-weighted
   distance from every non-target point to the nearest target point. */

at_distance_map new_distance_map(at_bitmap *bitmap, const at_color *background, gboolean padded,
                                 cancel_hook *cancel, at_exception_type *exp)
{
  signed x, y;
  float d, min;
  at_distance_map dist;
  unsigned char *b = AT_BITMAP_BITS(bitmap);
  unsigned w = AT_BITMAP_WIDTH(bitmap);
  unsigned h = AT_BITMAP_HEIGHT(bitmap);
  unsigned spp = AT_BITMAP_PLANES(bitmap);
  unsigned check_rows = rows_per_cancel_check(w);
  gboolean white =
      !background || (background->r == 255 && background->g == 255 && background->b == 255);

  /* Before the two maps, which hold a float per pixel each.  An
     empty map is still safe to free.  */
  if (cancel_requested(cancel))
    return (at_distance_map){0, 0, NULL, NULL};

  dist.height = h;
  dist.width = w;
  dist.d = g_new(float *, h);
  dist.weight = g_new(float *, h);
  for (y = 0; y < (signed)h; y++) {
    dist.d[y] = g_new0(float, w);
    dist.weight[y] = g_new(float, w);
  }

  if (!white) {
    /* On another background, a pixel is ink as far as its channel that
       lies furthest from the background's says, so that black and white
       lines are wholly ink on any background, and a line differing from
       the background only in hue is ink too.  Weighing every pixel by
       its distance from white counted a grey background as part ink, and
       a line on it came out too wide (#475).  */
    int bg_gray = (int)LUMINANCE(background->r, background->g, background->b);
    for (y = 0; y < (signed)h; y++) {
      if (y % check_rows == 0 && cancel_requested(cancel))
        return dist;
      for (x = 0; x < (signed)w; x++, b += spp) {
        if (spp == 3) {
          float r = channel_ink(b[0], background->r);
          float g = channel_ink(b[1], background->g);
          float bl = channel_ink(b[2], background->b);
          gboolean bg = b[0] == background->r && b[1] == background->g && b[2] == background->b;
          dist.d[y][x] = bg ? 0.0F : 1.0e10F;
          dist.weight[y][x] = MAX(r, MAX(g, bl));
        } else {
          dist.d[y][x] = b[0] == bg_gray ? 0.0F : 1.0e10F;
          dist.weight[y][x] = channel_ink(b[0], bg_gray);
        }
      }
    }
  } else if (spp == 3) {
    for (y = 0; y < (signed)h; y++) {
      if (y % check_rows == 0 && cancel_requested(cancel))
        return dist;
      for (x = 0; x < (signed)w; x++, b += spp) {
        int gray;
        float fgray;
        gray = (int)LUMINANCE(b[0], b[1], b[2]);
        dist.d[y][x] = (gray == 255 ? 0.0F : 1.0e10F);
        fgray = gray * 0.0039215686F; /* = gray / 255.0F */
        dist.weight[y][x] = 1.0F - fgray;
      }
    }
  } else {
    for (y = 0; y < (signed)h; y++) {
      if (y % check_rows == 0 && cancel_requested(cancel))
        return dist;
      for (x = 0; x < (signed)w; x++, b += spp) {
        int gray;
        float fgray;
        gray = b[0];
        dist.d[y][x] = (gray == 255 ? 0.0F : 1.0e10F);
        fgray = gray * 0.0039215686F; /* = gray / 255.0F */
        dist.weight[y][x] = 1.0F - fgray;
      }
    }
  }

  /* If the image is padded then border points are all at most
     one unit away from the nearest target point. */
  if (padded) {
    for (y = 0; y < (signed)h; y++) {
      if (dist.d[y][0] > dist.weight[y][0])
        dist.d[y][0] = dist.weight[y][0];
      if (dist.d[y][w - 1] > dist.weight[y][w - 1])
        dist.d[y][w - 1] = dist.weight[y][w - 1];
    }
    for (x = 0; x < (signed)w; x++) {
      if (dist.d[0][x] > dist.weight[0][x])
        dist.d[0][x] = dist.weight[0][x];
      if (dist.d[h - 1][x] > dist.weight[h - 1][x])
        dist.d[h - 1][x] = dist.weight[h - 1][x];
    }
  }

  /* Scan the image from left to right, top to bottom.
     Examine the already-visited neighbors of each point (those
     situated above or to the left of it).  Each neighbor knows
     the distance to its nearest target point; add to this distance
     the distance from the central point to the neighbor (either
     sqrt(2) or one) multiplied by the central point's weight
     (derived from its gray level).  Replace the distance already
     stored at the central point if the new distance is smaller. */
  for (y = 1; y < (signed)h; y++) {
    if (y % check_rows == 0 && cancel_requested(cancel))
      return dist;
    for (x = 1; x < (signed)w; x++) {
      if (dist.d[y][x] == 0.0F)
        continue;

      min = dist.d[y][x];

      /* upper-left neighbor */
      d = dist.d[y - 1][x - 1] + (float)M_SQRT2 * dist.weight[y][x];
      if (d < min)
        min = dist.d[y][x] = d;

      /* upper neighbor */
      d = dist.d[y - 1][x] + dist.weight[y][x];
      if (d < min)
        min = dist.d[y][x] = d;

      /* left neighbor */
      d = dist.d[y][x - 1] + dist.weight[y][x];
      if (d < min)
        min = dist.d[y][x] = d;

      /* upper-right neighbor (except at the last column) */
      if (x + 1 < (signed)w) {
        d = dist.d[y - 1][x + 1] + (float)M_SQRT2 * dist.weight[y][x];
        if (d < min)
          min = dist.d[y][x] = d;
      }
    }
  }

  /* Same as above, but now scanning right to left, bottom to top. */
  for (y = h - 2; y >= 0; y--) {
    if (y % check_rows == 0 && cancel_requested(cancel))
      return dist;
    for (x = w - 2; x >= 0; x--) {
      min = dist.d[y][x];

      /* lower-right neighbor */
      d = dist.d[y + 1][x + 1] + (float)M_SQRT2 * dist.weight[y][x];
      if (d < min)
        min = dist.d[y][x] = d;

      /* lower neighbor */
      d = dist.d[y + 1][x] + dist.weight[y][x];
      if (d < min)
        min = dist.d[y][x] = d;

      /* right neighbor */
      d = dist.d[y][x + 1] + dist.weight[y][x];
      if (d < min)
        min = dist.d[y][x] = d;

      /* lower-left neighbor (except at the first column) */
      if (x - 1 >= 0) {
        d = dist.d[y + 1][x - 1] + (float)M_SQRT2 * dist.weight[y][x];
        if (d < min)
          min = dist.d[y][x] = d;
      }
    }
  }
  return dist;
}

/* Free the dynamically-allocated storage associated with a distance map. */

void free_distance_map(at_distance_map *dist)
{
  unsigned y, h;

  if (!dist)
    return;

  h = dist->height;

  if (dist->d != NULL) {
    for (y = 0; y < h; y++)
      g_free((gpointer *)dist->d[y]);
    g_free((gpointer *)dist->d);
  }
  if (dist->weight != NULL) {
    for (y = 0; y < h; y++)
      g_free((gpointer *)dist->weight[y]);
    g_free((gpointer *)dist->weight);
  }
}
