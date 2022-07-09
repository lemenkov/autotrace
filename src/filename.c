// SPDX-FileCopyrightText: 1999 Free Software Foundation, Inc.
//
// SPDX-License-Identifier: GPL-2.0-or-later

/* filename.c: Function manipulate file names. Was: find-suffix, remove-suffix */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif /* Def: HAVE_CONFIG_H */

#include "filename.h"
#include <string.h>
#include <glib.h>

gchar *find_suffix(gchar * name)
{
  gchar *dot_pos = strrchr(name, '.');
  gchar *slash_pos = strrchr(name, G_DIR_SEPARATOR);

  /* If the name is `foo' or `/foo.bar/baz', we have no extension.  */
  return dot_pos == NULL || dot_pos < slash_pos ? NULL : dot_pos + 1;
}

gchar *remove_suffix(gchar * s)
{
  gchar *suffix = find_suffix(s);

  return suffix == NULL ? s : suffix - 2 - s < 0 ? NULL : g_strndup(s, (unsigned)(suffix - 2 - s));
}
