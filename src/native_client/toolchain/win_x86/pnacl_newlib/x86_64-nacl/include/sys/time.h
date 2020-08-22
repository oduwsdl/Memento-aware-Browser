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
 
 #if !(1 /* NACL_IN_TOOLCHAIN_HEADERS */)
 #include "native_client/src/include/build_config.h"
 #endif
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
 
 /*
  * Without this 8-byte alignment, it is possible that the timeval
  * struct is 12 bytes. However, the equivalent untrusted version of timeval
  * is aligned to 16 bytes. For the utimes function, where an array of
  * "struct timeval" is turned into an array of "struct timeval",
  * this misalignment can cause an untrusted 32 byte array to be interpreted
  * as a 24 byte trusted array, which is incorrect. This alignment causes
  * the trusted array to be correctly considered 32 bytes in length.
  */
 #if defined(NACL_WINDOWS) && NACL_WINDOWS != 0
 __declspec(align(8))
 #endif
 struct timeval {
   time_t      tv_sec;
   suseconds_t tv_usec;
 #if defined(NACL_WINDOWS) && NACL_WINDOWS != 0
 };
 #else
 } __attribute__((aligned(8)));
 #endif
 
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
 