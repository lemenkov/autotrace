// SPDX-FileCopyrightText: 2004 Steven P. Hirshman
//
// SPDX-License-Identifier: LGPL-2.1-or-later

/* output-plt.h --- output in HPGL (plt) format */

#ifndef __OUTPUT_PLT_H
#define __OUTPUT_PLT_H

#include "output.h"

int output_plt_writer(FILE * file, gchar * name, int llx, int lly, int urx, int ury, at_output_opts_type * opts, at_spline_list_array_type shape, at_msg_func msg_func, gpointer msg_data, gpointer user_data);

#endif /* __OUTPUT_PLT_H */
