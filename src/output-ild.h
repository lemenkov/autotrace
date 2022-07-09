// SPDX-FileCopyrightText: 2004 Steven P. Hirshman
// SPDX-FileCopyrightText: 2005 Robin Adams <radams@linux-laser.org>
//
// SPDX-License-Identifier: LGPL-2.1-or-later

/* output-ild.h --- output in ILDA (ild) format */

#ifndef __OUTPUT_ILD_H
#define __OUTPUT_ILD_H

#include "output.h"

int output_ild_writer(FILE * file, gchar * name, int llx, int lly, int urx, int ury, at_output_opts_type * opts, at_spline_list_array_type shape, at_msg_func msg_func, gpointer msg_data, gpointer user_data);

#endif /* __OUTPUT_ILD_H */
