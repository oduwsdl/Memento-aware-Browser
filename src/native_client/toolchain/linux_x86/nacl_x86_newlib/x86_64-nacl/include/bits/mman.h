/*
 * Copyright (c) 2011 The Native Client Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/*
 * NaCl Service Runtime API.
 */

#ifndef EXPORT_SRC_TRUSTED_SERVICE_RUNTIME_INCLUDE_BITS_MMAN_H_
#define EXPORT_SRC_TRUSTED_SERVICE_RUNTIME_INCLUDE_BITS_MMAN_H_

#define PROT_READ        0x1   /* Page can be read.  */
#define PROT_WRITE       0x2   /* Page can be written.  */
#define PROT_EXEC        0x4   /* Page can be executed.  */
#define PROT_NONE        0x0   /* Page can not be accessed.  */

#define PROT_MASK        0x7

#define MAP_SHARED       0x01  /* Share changes.  */
#define MAP_PRIVATE      0x02  /* Changes are private.  */

#define MAP_SHARING_MASK 0x03

#define MAP_FIXED        0x10  /* Interpret addr exactly.  */
#define MAP_ANON         0x20  /* Don't use a file.  */
#define MAP_ANONYMOUS    MAP_ANON  /* Linux alias.  */

#define MAP_FAILED       ((void *) -1)

#endif /* NATIVE_CLIENT_SRC_TRUSTED_SERVICE_RUNTIME_INCLUDE_BITS_MMAN_H_ */
