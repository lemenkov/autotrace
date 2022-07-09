// SPDX-FileCopyrightText: 2001 Per Grahn
//
// SPDX-License-Identifier: LGPL-2.1-or-later

/* output-mif.h: utility routines for FrameMaker MIF output */

#ifndef OUTPUT_MIF_H
#define OUTPUT_MIF_H

#include "output.h"

int output_mif_writer(FILE * file, gchar * name, int llx, int lly, int urx, int ury, at_output_opts_type * opts, at_spline_list_array_type shape, at_msg_func msg_func, gpointer msg_data, gpointer user_data);

#endif /* not OUTPUT_MIF_H */
