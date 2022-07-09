// SPDX-FileCopyrightText: 2000 MenTaLguY <mental@rydia.net>
//
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef INPUT_PNG_H
#define INPUT_PNG_H

#include "input.h"

at_bitmap input_png_reader(gchar * filename, at_input_opts_type * opts, at_msg_func msg_func, gpointer msg_data, gpointer user_data);

#endif /* not INPUT_PNG_H */
