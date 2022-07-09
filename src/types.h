// SPDX-FileCopyrightText: 2000,2001 Martin Weber <martweb@gmx.net>
//
// SPDX-License-Identifier: GPL-2.0-or-later

#ifndef AT_TYPES_H
#define AT_TYPES_H

#include <stdint.h>
#include <glib.h>

#ifdef __cplusplus
extern "C" {
#endif                          /* __cplusplus */

/* Cartesian points.  */
  typedef struct _at_coord {
    gushort x, y;
  } at_coord;

  typedef struct _at_real_coord {
    gfloat x, y, z;
  } at_real_coord;

#ifdef __cplusplus
}
#endif                          /* __cplusplus */
#endif                          /* not AT_TYPES_H */
