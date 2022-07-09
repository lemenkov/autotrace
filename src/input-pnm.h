// SPDX-FileCopyrightText: 1999-2001 Erik Nygren <nygren@mit.edu>
//
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef INPUT_PNM_H
#define INPUT_PNM_H

#include "input.h"

at_bitmap input_pnm_reader(gchar * filename, at_input_opts_type * opts, at_msg_func msg_func, gpointer msg_data, gpointer user_data);

#endif /* not INPUT_PNM_H */
