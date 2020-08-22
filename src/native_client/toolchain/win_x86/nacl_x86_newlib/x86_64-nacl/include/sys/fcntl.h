/*
 * Copyright (c) 2011 The Native Client Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/*
 * NaCl Service Runtime API.
 */

#ifndef EXPORT_SRC_TRUSTED_SERVICE_RUNTIME_INCLUDE_SYS_FCNTL_H_
#define EXPORT_SRC_TRUSTED_SERVICE_RUNTIME_INCLUDE_SYS_FCNTL_H_

#if (1 /* NACL_IN_TOOLCHAIN_HEADERS */)
#include <sys/types.h>
#endif

/* from bits/fcntl.h */
#define O_ACCMODE       0003
#define O_RDONLY          00
#define O_WRONLY          01
#define O_RDWR            02

#define O_CREAT         0100 /* not fcntl */
#define O_TRUNC        01000 /* not fcntl */
#define O_APPEND       02000

/*
 * Features not implemented by NaCl, but required by the newlib build.
 */
#define O_EXCL          0200
#define O_NONBLOCK     04000
#define O_NDELAY      O_NONBLOCK
#define O_SYNC        010000
#define O_FSYNC       O_SYNC
#define O_ASYNC       020000

/*
 * Features not implemented by NaCl, but required by nacl_helper_nonsfi.
 */
#define O_DIRECTORY  0200000
#define O_CLOEXEC   02000000

/* XXX close on exec request; must match UF_EXCLOSE in user.h */
#define FD_CLOEXEC  1 /* posix */

/* fcntl(2) requests */
#define F_DUPFD   0 /* Duplicate fildes */
#define F_GETFD   1 /* Get fildes flags (close on exec) */
#define F_SETFD   2 /* Set fildes flags (close on exec) */
#define F_GETFL   3 /* Get file flags */
#define F_SETFL   4 /* Set file flags */
#ifndef _POSIX_SOURCE
#define F_GETOWN  5 /* Get owner - for ASYNC */
#define F_SETOWN  6 /* Set owner - for ASYNC */
#endif  /* !_POSIX_SOURCE */
#define F_GETLK   7 /* Get record-locking information */
#define F_SETLK   8 /* Set or Clear a record-lock (Non-Blocking) */
#define F_SETLKW  9 /* Set or Clear a record-lock (Blocking) */
#ifndef _POSIX_SOURCE
#define F_RGETLK  10  /* Test a remote lock to see if it is blocked */
#define F_RSETLK  11  /* Set or unlock a remote lock */
#define F_CNVT    12  /* Convert a fhandle to an open fd */
#define F_RSETLKW   13  /* Set or Clear remote record-lock(Blocking) */
#endif  /* !_POSIX_SOURCE */

/* fcntl(2) flags (l_type field of flock structure) */
#define F_RDLCK   1 /* read lock */
#define F_WRLCK   2 /* write lock */
#define F_UNLCK   3 /* remove lock(s) */
#ifndef _POSIX_SOURCE
#define F_UNLKSYS 4 /* remove remote locks for a given system */
#endif  /* !_POSIX_SOURCE */

/* For openat(2) used by nacl_helper_nonsfi. */
#define AT_FDCWD (-2)

#if (1 /* NACL_IN_TOOLCHAIN_HEADERS */)
/* file segment locking set data type - information passed to system by user */
struct flock {
  short l_type;
  short l_whence;
  off_t l_start;
  off_t l_len;
  pid_t l_pid;
};

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

extern int open(const char *file, int oflag, ...);
extern int creat(const char *file, mode_t mode);
extern int fcntl(int, int, ...);
extern int openat(int dirfd, const char *pathname, int oflag, ...);

#ifdef __cplusplus
}  /* extern "C" */
#endif  /* __cplusplus */
#endif  /* (1 /* NACL_IN_TOOLCHAIN_HEADERS */) */

#endif
