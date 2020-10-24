/* Definitions for ARM running Native Client
   Copyright (C) 2012-2015 Free Software Foundation, Inc.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published
   by the Free Software Foundation; either version 3, or (at your
   option) any later version.

   GCC is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with GCC; see the file COPYING3.  If not see
   <http://www.gnu.org/licenses/>.  */

/* linux-elf.h and linux-eabi.h should have already been included.  Now
   just override any conflicting definitions and add any extras.  */

#undef  TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS()                \
  do                                            \
    {                                           \
      TARGET_BPABI_CPP_BUILTINS();              \
      GNU_USER_TARGET_OS_CPP_BUILTINS();        \
    }                                           \
  while (0)

#undef  TARGET_DEFAULT_FLOAT_ABI
#define TARGET_DEFAULT_FLOAT_ABI ARM_FLOAT_ABI_HARD

#undef  FPUTYPE_DEFAULT
#define FPUTYPE_DEFAULT "neon"

#undef  TARGET_DEFAULT
#define TARGET_DEFAULT (TARGET_ENDIAN_DEFAULT | MASK_SFI_NACL1)

#undef  SUBTARGET_CPU_DEFAULT
#define SUBTARGET_CPU_DEFAULT TARGET_CPU_genericv7a

/* Nacl specific constants. */
/* Instruction bundles have this size and at least this alignment. */
#define NACL_ARM_BUNDLE_ALIGN   16

#define FUNCTION_BOUNDARY       (NACL_ARM_BUNDLE_ALIGN * BITS_PER_UNIT)

/* Do nacl-specific parts of TARGET_OPTION_OVERRIDE.  */
#undef SUBTARGET_OVERRIDE_OPTIONS
#define SUBTARGET_OVERRIDE_OPTIONS                                    \
  NACL_MIN_ALIGN (TARGET_SFI_NACL1, NACL_ARM_BUNDLE_ALIGN)

/* r9 is reserved for the thread pointer.  */
#undef  SUBTARGET_CONDITIONAL_REGISTER_USAGE
#define SUBTARGET_CONDITIONAL_REGISTER_USAGE \
  fixed_regs[9] = 1; \
  call_used_regs[9] = 1;

/* The NaCl ABI says the stack shall be aligned to a 16-byte boundary.  */
#undef  PREFERRED_STACK_BOUNDARY
#define PREFERRED_STACK_BOUNDARY        128

/* TARGET_BIG_ENDIAN_DEFAULT is set in
   config.gcc for big endian configurations.  */
#undef TARGET_LINKER_EMULATION
#if TARGET_BIG_ENDIAN_DEFAULT
#define TARGET_LINKER_EMULATION  "armelfb_nacl"
#else
#define TARGET_LINKER_EMULATION  "armelf_nacl"
#endif

/* TODO: thumb */
#undef  GNU_USER_DYNAMIC_LINKER
#define GNU_USER_DYNAMIC_LINKER "/lib/ld-nacl-arm.so.1"

#undef  LINK_SPEC
#define LINK_SPEC EABI_LINK_SPEC NACL_LINK_SPEC

#undef  CC1_SPEC
#define CC1_SPEC GNU_USER_TARGET_CC1_SPEC

#undef  CC1PLUS_SPEC

#undef  LIB_SPEC
#define LIB_SPEC GNU_USER_TARGET_LIB_SPEC

#undef  STARTFILE_SPEC
#define STARTFILE_SPEC GNU_USER_TARGET_STARTFILE_SPEC

#undef  ENDFILE_SPEC
#define ENDFILE_SPEC GNU_USER_TARGET_ENDFILE_SPEC

/* We feed the file of standard assembler macros as an extra input file
   before the actual assembly code.  This file will be installed in some
   place like ${tool_prefix}/lib/.  */
#undef SUBTARGET_EXTRA_ASM_SPEC
#define SUBTARGET_EXTRA_ASM_SPEC        \
  "nacl-arm-macros.s%s"

/* Clear the instruction cache from BEG to END.  This is used only
   for trampolines on an executable stack, which NaCl cannot support
   anyway.  */
#undef  CLEAR_INSN_CACHE
#define CLEAR_INSN_CACHE(BEG, END) abort ()
