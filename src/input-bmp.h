// SPDX-FileCopyrightText: 1999-2001 Martin Weber <martweb@gmx.net>
//
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef INPUT_BMP_H
#define INPUT_BMP_H

#include "input.h"

at_bitmap input_bmp_reader(gchar * filename, at_input_opts_type * opts, at_msg_func msg_func, gpointer msg_data, gpointer user_data);

#endif /* not INPUT_BMP_H */
