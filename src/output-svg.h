// SPDX-FileCopyrightText: 1999-2001 Bernhard Herzog <bh@intevation.de>
//
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef OUTPUT_SVG_H
#define OUTPUT_SVG_H

#include "output.h"

int output_svg_writer(FILE * file, gchar * name, int llx, int lly, int urx, int ury, at_output_opts_type * opts, at_spline_list_array_type shape, at_msg_func msg_func, gpointer msg_data, gpointer user_data);

#endif /* not OUTPUT_SVG_H */
