/*
 * Copyright (c) 2012 The Native Client Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/*
 * NaCl Service Runtime API.  Time types.
 */

#ifndef EXPORT_SRC_TRUSTED_SERVICE_RUNTIME_INCLUDE_SYS_TIME_H_
#define EXPORT_SRC_TRUSTED_SERVICE_RUNTIME_INCLUDE_SYS_TIME_H_

#include <machine/_types.h>


#ifdef __cplusplus
extern "C" {
#endif

#if (1 /* NACL_IN_TOOLCHAIN_HEADERS */)
#ifndef __susecond_t_defined
#define __susecond_t_defined
typedef long int  suseconds_t;
#endif
#else
typedef int32_t   suseconds_t;
#endif

#ifndef __clock_t_defined
#define __clock_t_defined
typedef long int  clock_t;  /* to be deprecated */
#endif

struct timeval {
  time_t      tv_sec;
  suseconds_t tv_usec;
};

/* obsolete.  should not be used */
struct timezone {
  int tz_minuteswest;
  int tz_dsttime;
};

/*
 * In some places (e.g., the linux man page) the second parameter is defined
 * as a struct timezone *.  The header file says this struct type should
 * never be used, and defines it by default as void *.  The Mac man page says
 * it is void *.
 */
extern int gettimeofday(struct timeval *tv, void *tz);

/*
 * POSIX defined clock id values for clock_getres andn clock_gettime.
 */

#define CLOCK_REALTIME           (0)
#define CLOCK_MONOTONIC          (1)
#define CLOCK_PROCESS_CPUTIME_ID (2)
#define CLOCK_THREAD_CPUTIME_ID  (3)

#ifdef __cplusplus
}
#endif

#endif
