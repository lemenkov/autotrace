// SPDX-FileCopyrightText: 1999-2001 Ian MacPhedran
//
// SPDX-License-Identifier: LGPL-2.1-or-later

/* output-fig.h - output autotrace splines in FIG 3.2 format */

#ifndef OUTPUT_FIG_H
#define OUTPUT_FIG_H

#include "output.h"

int output_fig_writer(FILE * file, gchar * name, int llx, int lly, int urx, int ury, at_output_opts_type * opts, at_spline_list_array_type shape, at_msg_func msg_func, gpointer msg_data, gpointer user_data);

#endif /* not OUTPUT_FIG_H */
