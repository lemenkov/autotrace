// SPDX-FileCopyrightText: 2003 Serge Vakulenko <vak@cronyx.ru>
//
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef INPUT_GF_H
#define INPUT_GF_H

#include "input.h"

at_bitmap input_gf_reader(gchar * filename, at_input_opts_type * opts, at_msg_func msg_func, gpointer msg_data, gpointer user_data);

#endif /* not INPUT_GF_H */
