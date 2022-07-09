// SPDX-FileCopyrightText: 1999-2001 Kevin O' Gorman <spidey@maths.tcd.ie>
//
// SPDX-License-Identifier: LGPL-2.1-or-later

/* Uses the Ming SWF library from http://www.opaque.net/ming/ */

#ifndef OUTPUTSWF_H
#define OUTPUTSWF_H

#include "output.h"

int output_swf_writer(FILE * file, gchar * name, int llx, int lly, int urx, int ury, at_output_opts_type * opts, at_spline_list_array_type shape, at_msg_func msg_func, gpointer msg_data, gpointer user_data);

#endif /* Not def: OUTPUTSWF_H */
