/* Definitions for Native Client systems.
   Copyright (C) 2013-2015 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/* TODO:
   glibc vs newlib options
 */

#define GNU_USER_TARGET_OS_CPP_BUILTINS()               \
  do {                                                  \
    builtin_define ("__native_client__");               \
    builtin_assert ("system=nacl");                     \
    builtin_assert ("system=posix");                    \
    builtin_define (BYTES_BIG_ENDIAN ? "__BIG_ENDIAN__" \
		    : "__LITTLE_ENDIAN__");             \
  } while (0)

/* This is the value for %(subtarget_cpp_spec).  It goes with gnu-user.opt.  */
#undef  SUBTARGET_CPP_SPEC
#define SUBTARGET_CPP_SPEC  "%{posix:-D_POSIX_SOURCE} %{pthread:-D_REENTRANT}"

/* The assembler is always a GNU one, which understands a - argument.
   Since CPU/nacl.h defines SUBTARGET_EXTRA_ASM_SPEC to pass an extra
   input file to the assembler, we need an explicit - to make it also
   read the actual input when it's from stdin.  */
#define AS_NEEDS_DASH_FOR_PIPED_INPUT

/* Since non-instructions can never go into code sections,
   this is always false for Native Client targets.  */
#undef  JUMP_TABLES_IN_TEXT_SECTION
#define JUMP_TABLES_IN_TEXT_SECTION     0

#define NACL_MIN_ALIGN(condition, bundle_size)                          \
  do {                                                                  \
    if (condition)                                                      \
      {                                                                 \
	/* All functions and branch targets are aligned to at least the \
	   bundle size in native client. */                             \
	if (align_functions < bundle_size)                              \
	  align_functions = bundle_size;                                \
	if (align_jumps < bundle_size)                                  \
	  align_jumps = bundle_size;                                    \
	if (align_labels < bundle_size)                                 \
	  align_labels = bundle_size;                                   \
	if (align_loops < bundle_size)                                  \
	  align_loops = bundle_size;                                    \
      }                                                                 \
  } while (0)

/* Every Native Client platform has a 'long double' type that is just
   'double', which is always the IEEE754 64-bit type.  */
#undef LONG_DOUBLE_TYPE_SIZE
#define LONG_DOUBLE_TYPE_SIZE		DOUBLE_TYPE_SIZE
#undef LIBGCC2_HAS_TF_MODE

/* For dynamic linking an ET_EXEC, we need to place the text segment
   far enough above the normal 0x20000 default that there is enough
   space for the untrusted ELF loader.  */
#define NACL_LINK_SPEC \
  "%{!static:%{!shared:%{!pie:-Ttext-segment=0x100000}}}" \
  LINUX_TARGET_LINK_SPEC
