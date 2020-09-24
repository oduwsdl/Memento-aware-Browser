/*
 * Copyright (c) 2012 The Native Client Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/*
 * NaCl kernel / service run-time system call ABI.
 * This file defines nacl target machine dependent types.
 */

#ifndef EXPORT_SRC_TRUSTED_SERVICE_RUNTIME_INCLUDE_MACHINE__TYPES_H_
#define EXPORT_SRC_TRUSTED_SERVICE_RUNTIME_INCLUDE_MACHINE__TYPES_H_

#if (1 /* NACL_IN_TOOLCHAIN_HEADERS */)
# include <stdint.h>
# include <machine/_default_types.h>
#else
# include "native_client/src/include/portability.h"
#endif

#define __need_size_t
#include <stddef.h>

#ifndef NULL
#define NULL 0
#endif

#ifndef __dev_t_defined
#define __dev_t_defined
typedef int64_t __dev_t;
#if !(1 /* NACL_IN_TOOLCHAIN_HEADERS */)
typedef __dev_t dev_t;
#endif
#endif

#ifndef __ino_t_defined
#define __ino_t_defined
typedef uint64_t __ino_t;
#if !(1 /* NACL_IN_TOOLCHAIN_HEADERS */)
typedef __ino_t ino_t;
#endif
#endif

#ifndef __mode_t_defined
#define __mode_t_defined
typedef uint32_t __mode_t;
#if !(1 /* NACL_IN_TOOLCHAIN_HEADERS */)
typedef __mode_t mode_t;
#endif
#endif

#ifndef __nlink_t_defined
#define __nlink_t_defined
typedef uint32_t __nlink_t;
#if !(1 /* NACL_IN_TOOLCHAIN_HEADERS */)
typedef __nlink_t nlink_t;
#endif
#endif

#ifndef __uid_t_defined
#define __uid_t_defined
typedef uint32_t __uid_t;
#if !(1 /* NACL_IN_TOOLCHAIN_HEADERS */)
typedef __uid_t uid_t;
#endif
#endif

#ifndef __gid_t_defined
#define __gid_t_defined
typedef uint32_t __gid_t;
#if !(1 /* NACL_IN_TOOLCHAIN_HEADERS */)
typedef __gid_t gid_t;
#endif
#endif

#ifndef __off_t_defined
#define __off_t_defined
typedef int64_t _off_t;
#if !(1 /* NACL_IN_TOOLCHAIN_HEADERS */)
typedef _off_t off_t;
#endif
#endif

#ifndef __off64_t_defined
#define __off64_t_defined
typedef int64_t _off64_t;
#if !(1 /* NACL_IN_TOOLCHAIN_HEADERS */)
typedef _off64_t off64_t;
#endif
#endif


#if !(defined(__GLIBC__) && (1 /* NACL_IN_TOOLCHAIN_HEADERS */))

#ifndef __blksize_t_defined
#define __blksize_t_defined
typedef int32_t __blksize_t;
typedef __blksize_t blksize_t;
#endif

#endif


#ifndef __blkcnt_t_defined
#define __blkcnt_t_defined
typedef int32_t __blkcnt_t;
typedef __blkcnt_t blkcnt_t;
#endif

#ifndef __time_t_defined
#define __time_t_defined
typedef int64_t       __time_t;
typedef __time_t time_t;
#endif

#ifndef __timespec_defined
#define __timespec_defined
struct timespec {
  time_t tv_sec;
#if (1 /* NACL_IN_TOOLCHAIN_HEADERS */)
  long int        tv_nsec;
#else
  int32_t         tv_nsec;
#endif
};
#endif

#endif
