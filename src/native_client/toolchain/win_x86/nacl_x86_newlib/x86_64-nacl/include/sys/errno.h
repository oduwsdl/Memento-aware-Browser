/*
 * Copyright 2008 The Native Client Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/*
 * NaCl Service Runtime API.
 */

#ifndef EXPORT_SRC_TRUSTED_SERVICE_RUNTIME_INCLUDE_SYS_ERRNO_H_
#define EXPORT_SRC_TRUSTED_SERVICE_RUNTIME_INCLUDE_SYS_ERRNO_H_

#if (1 /* NACL_IN_TOOLCHAIN_HEADERS */)
#include <sys/reent.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _REENT_ONLY
#define errno (*__errno())
  extern int *__errno _PARAMS ((void));
#endif

/* Please don't use these variables directly.
 *    Use strerror instead. */
extern __IMPORT _CONST char * _CONST _sys_errlist[];
extern __IMPORT int _sys_nerr;

#define __errno_r(ptr) ((ptr)->_errno)

#ifdef __cplusplus
}
#endif

#endif  /* (1 /* NACL_IN_TOOLCHAIN_HEADERS */) */

/*
 * NOTE: when adding new errnos here, check
 * service_runtime/nacl_host_desc_common.c and
 * service_runtime/win/xlate_system_error.c.
 */

/*
 * The errno values below 2048 here are the same as Linux's errno
 * values.  See Linux's asm-generic/errno-base.h and
 * asm-generic/errno.h.
 */

#define EPERM     1  /* Operation not permitted */
#define ENOENT    2  /* No such file or directory */
#define ESRCH     3  /* No such process */
#define EINTR     4  /* Interrupted system call */
#define EIO       5  /* I/O error */
#define ENXIO     6  /* No such device or address */
#define E2BIG     7  /* Argument list too long */
#define ENOEXEC   8  /* Exec format error */
#define EBADF     9  /* Bad file number */
#define ECHILD   10  /* No child processes */
#define EAGAIN   11  /* Try again */
#define ENOMEM   12  /* Out of memory */
#define EACCES   13  /* Permission denied */
#define EFAULT   14  /* Bad address */

#define EBUSY    16  /* Device or resource busy */
#define EEXIST   17  /* File exists */
#define EXDEV    18  /* Cross-device link */
#define ENODEV   19  /* No such device */
#define ENOTDIR  20  /* Not a directory */
#define EISDIR   21  /* Is a directory */
#define EINVAL   22  /* Invalid argument */
#define ENFILE   23  /* File table overflow */
#define EMFILE   24  /* Too many open files */
#define ENOTTY   25  /* Not a typewriter */

#define EFBIG    27  /* File too large */
#define ENOSPC   28  /* No space left on device */
#define ESPIPE   29  /* Illegal seek */
#define EROFS    30  /* Read-only file system */
#define EMLINK   31  /* Too many links */
#define EPIPE    32  /* Broken pipe */

#define ENAMETOOLONG 36  /* File name too long */

#define ENOSYS   38  /* Function not implemented */

#define EDQUOT   122 /* Quota exceeded */

/*
 * Other definitions not needed for NaCl, but needed for newlib build.
 */
#define EDOM 33   /* Math arg out of domain of func */
#define ERANGE 34 /* Math result not representable */
#define EDEADLK 35  /* Deadlock condition */
#define ENOLCK 37 /* No record locks available */
#define ENOTEMPTY 39  /* Directory not empty */
#define ELOOP 40  /* Too many symbolic links */
#define ENOMSG 42 /* No message of desired type */
#define EIDRM 43  /* Identifier removed */
#define ECHRNG 44 /* Channel number out of range */
#define EL2NSYNC 45 /* Level 2 not synchronized */
#define EL3HLT 46 /* Level 3 halted */
#define EL3RST 47 /* Level 3 reset */
#define ELNRNG 48 /* Link number out of range */
#define EUNATCH 49  /* Protocol driver not attached */
#define ENOCSI 50 /* No CSI structure available */
#define EL2HLT 51 /* Level 2 halted */
#define EBADE 52  /* Invalid exchange */
#define EBADR 53  /* Invalid request descriptor */
#define EXFULL 54 /* Exchange full */
#define ENOANO 55 /* No anode */
#define EBADRQC 56  /* Invalid request code */
#define EBADSLT 57  /* Invalid slot */
#define EDEADLOCK EDEADLK  /* File locking deadlock error */
#define EBFONT 59 /* Bad font file fmt */
#define ENOSTR 60 /* Device not a stream */
#define ENODATA 61  /* No data (for no delay io) */
#define ETIME 62  /* Timer expired */
#define ENOSR 63  /* Out of streams resources */
#define ENONET 64 /* Machine is not on the network */
#define ENOPKG 65 /* Package not installed */
#define EREMOTE 66  /* The object is remote */
#define ENOLINK 67  /* The link has been severed */
#define EADV 68   /* Advertise error */
#define ESRMNT 69 /* Srmount error */
#define ECOMM 70  /* Communication error on send */
#define EPROTO 71 /* Protocol error */
#define EMULTIHOP 72  /* Multihop attempted */
#define EDOTDOT 73  /* Cross mount point (not really error) */
#define EBADMSG 74  /* Trying to read unreadable message */
#define EOVERFLOW 75 /* Value too large for defined data type */
#define ENOTUNIQ 76 /* Given log. name not unique */
#define EBADFD 77 /* f.d. invalid for this operation */
#define EREMCHG 78  /* Remote address changed */
#define ELIBACC 79  /* Can't access a needed shared lib */
#define ELIBBAD 80  /* Accessing a corrupted shared lib */
#define ELIBSCN 81  /* .lib section in a.out corrupted */
#define ELIBMAX 82  /* Attempting to link in too many libs */
#define ELIBEXEC 83 /* Attempting to exec a shared library */
#define EILSEQ 84
#define EUSERS 87
#define ENOTSOCK 88  /* Socket operation on non-socket */
#define EDESTADDRREQ 89  /* Destination address required */
#define EMSGSIZE 90    /* Message too long */
#define EPROTOTYPE 91  /* Protocol wrong type for socket */
#define ENOPROTOOPT 92 /* Protocol not available */
#define EPROTONOSUPPORT 93 /* Unknown protocol */
#define ESOCKTNOSUPPORT 94 /* Socket type not supported */
#define EOPNOTSUPP 95 /* Operation not supported on transport endpoint */
#define EPFNOSUPPORT 96 /* Protocol family not supported */
#define EAFNOSUPPORT 97 /* Address family not supported by protocol family */
#define EADDRINUSE 98    /* Address already in use */
#define EADDRNOTAVAIL 99 /* Address not available */
#define ENETDOWN 100    /* Network interface is not configured */
#define ENETUNREACH 101   /* Network is unreachable */
#define ENETRESET 102
#define ECONNABORTED 103  /* Connection aborted */
#define ECONNRESET 104  /* Connection reset by peer */
#define ENOBUFS 105 /* No buffer space available */
#define EISCONN 106   /* Socket is already connected */
#define ENOTCONN 107    /* Socket is not connected */
#define ESHUTDOWN 108 /* Can't send after socket shutdown */
#define ETOOMANYREFS 109
#define ETIMEDOUT 110   /* Connection timed out */
#define ECONNREFUSED 111  /* Connection refused */
#define EHOSTDOWN 112   /* Host is down */
#define EHOSTUNREACH 113  /* Host is unreachable */
#define EALREADY 114    /* Socket already connected */
#define EINPROGRESS 115   /* Connection already in progress */
#define ESTALE 116
#define ENOTSUP EOPNOTSUPP   /* Not supported */
#define ENOMEDIUM 123   /* No medium (in tape drive) */
#define ECANCELED 125 /* Operation canceled. */
#define EOWNERDEAD 130 /* Owner died */
#define ENOTRECOVERABLE 131 /* State not recoverable */


/*
 * Below are non-standard errno values which are not defined on Linux.
 * Any new non-standard or NaCl-specific errno values should go here
 * and have high (>=2048) values, so as not to conflict with errno
 * values that Linux might add in the future.
 */
#define ELBIN       2048  /* Inode is remote (not really error) */
#define EFTYPE      2049  /* Inappropriate file type or format */
#define ENMFILE     2050  /* No more files */
#define EPROCLIM    2051
#define ENOSHARE    2052  /* No such host or network path */
#define ECASECLASH  2053  /* Filename exists with different case */


/* From cygwin32.  */
#define EWOULDBLOCK EAGAIN      /* Operation would block */

#endif
