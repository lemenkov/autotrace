// SPDX-FileCopyrightText: 1999 Free Software Foundation, Inc.
//
// SPDX-License-Identifier: GPL-2.0-or-later

/* filename.h: Function manipulate file names. Was: find-suffix, remove-suffix */

#ifndef FILENAME_H
#define FILENAME_H
#include <glib.h>

/* If NAME has a suffix, return a pointer to its first character (i.e.,
   the one after the `.'); otherwise, return NULL.  */
extern gchar *find_suffix(gchar * name);

/* Return NAME with any suffix removed.  */
extern gchar *remove_suffix(gchar * name);

#endif /* Not def: FILENAME_H */
