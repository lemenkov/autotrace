/* types.h: general types
   Copyright (C) 2000, 2001 Martin Weber

   The author can be contacted at <martweb@gmx.net>

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA. */

#ifndef TYPES_H
#define TYPES_H

#ifndef __cplusplus
/* Booleans.  */
#ifndef bool
typedef enum { false = 0, true = 1 } at_bool;
#else
#define at_bool bool
#endif
#else
#define at_bool bool
#endif

/* The usual null-terminated string.  */
typedef char *at_string;

/* A generic pointer in ANSI C.  */
typedef void *at_address;

/* We use `real' for our floating-point variables.  */
typedef float at_real;

/* Cartesian points.  */
typedef struct
{
  short x, y;
} at_coordinate_type;

typedef struct
{
  at_real x, y;
} at_real_coordinate_type;

#endif /* not TYPES_H */
