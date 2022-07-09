// SPDX-FileCopyrightText: 2003 Martin Weber <martweb@gmx.net>
//
// SPDX-License-Identifier: LGPL-2.1-or-later

/* output-pov.h: utility routines for Povray output */

#ifndef OUTPUT_POV_H
#define OUTPUT_POV_H

#include "output.h"

int output_pov_writer(FILE * file, gchar * name, int llx, int lly, int urx, int ury, at_output_opts_type * opts, at_spline_list_array_type shape, at_msg_func msg_func, gpointer msg_data, gpointer uesr_data);

#endif /* not OUTPUT_POV_H */
