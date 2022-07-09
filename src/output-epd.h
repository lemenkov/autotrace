// SPDX-FileCopyrightText: 1999-2001 Martin Weber <martweb@gmx.net>
//
// SPDX-License-Identifier: LGPL-2.1-or-later

/* output-epd.h: routines for EPD output (http://epd.sourceforge.net) */

#ifndef OUTPUT_EPD_H
#define OUTPUT_EPD_H

#include "output.h"

int output_epd_writer(FILE * file, gchar * name, int llx, int lly, int urx, int ury, at_output_opts_type * opts, at_spline_list_array_type shape, at_msg_func msg_func, gpointer msg_data, gpointer user_data);

#endif /* not OUTPUT_EPD_H */
