/*
 * Copyright 2008 The Native Client Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/*
 * NaCl kernel / service run-time system call ABI.  stat/fstat.
 */

#ifndef EXPORT_SRC_TRUSTED_SERVICE_RUNTIME_INCLUDE_SYS_STAT_H_
#define EXPORT_SRC_TRUSTED_SERVICE_RUNTIME_INCLUDE_SYS_STAT_H_

#include <bits/stat.h>


#if (1 /* NACL_IN_TOOLCHAIN_HEADERS */)

#ifdef __cplusplus
extern "C" {
#endif

extern int stat(char const *path, struct stat *stbuf);
extern int fstat(int d, struct stat *stbuf);
extern int lstat(const char *path, struct stat *stbuf);
extern int fstatat(int dirfd, const char *pathname,
                   struct stat *stbuf, int flags);
extern int mkdir(const char *path, mode_t mode);

#ifdef __cplusplus
}
#endif

#endif

#endif
