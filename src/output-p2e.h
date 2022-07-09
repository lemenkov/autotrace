// SPDX-FileCopyrightText: 2000,2001 Wolfgang Glunz <wglunz@pstoedit.net>
// SPDX-FileCopyrightText: 2000,2001 Martin Weber <martweb@gmx.net>
//
// SPDX-License-Identifier: LGPL-2.1-or-later

/* output-p2e.h: utility routines for pstoedit intermediate output */

#ifndef OUTPUT_P2E_H
#define OUTPUT_P2E_H

#include "output.h"

int output_p2e_writer(FILE * file, gchar * name, int llx, int lly, int urx, int ury, at_output_opts_type * opts, at_spline_list_array_type shape, at_msg_func msg_func, gpointer msg_data, gpointer user_data);

#endif /* not OUTPUT_P2E_H */
