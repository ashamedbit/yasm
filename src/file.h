/* $IdPath$
 * Little-endian file functions header file.
 *
 *  Copyright (C) 2001  Peter Johnson
 *
 *  This file is part of YASM.
 *
 *  YASM is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  YASM is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#ifndef YASM_FILE_H
#define YASM_FILE_H

/* These functions only work properly if p is an (unsigned char *) */

#define WRITE_BYTE(ptr, val)			\
	*((ptr)++) = (val) & 0xFF

#define WRITE_SHORT(ptr, val)			\
	do {					\
	    *((ptr)++) = (val) & 0xFF;		\
	    *((ptr)++) = ((val) >> 8) & 0xFF;	\
	} while (0)

#define WRITE_LONG(ptr, val)			\
	do {					\
	    *((ptr)++) = (val) & 0xFF;		\
	    *((ptr)++) = ((val) >> 8) & 0xFF;	\
	    *((ptr)++) = ((val) >> 16) & 0xFF;	\
	    *((ptr)++) = ((val) >> 24) & 0xFF;	\
	} while (0)

/* Direct-to-file versions of the above.  Using the above macros and a single
 * fwrite() will probably be faster than calling these functions many times.
 * These functions return 1 if the write was successful, 0 if not (so their
 * return values can be used like the return value from fwrite()).
 */

size_t fwrite_short(unsigned short val, FILE *f);
size_t fwrite_long(unsigned long val, FILE *f);

#endif