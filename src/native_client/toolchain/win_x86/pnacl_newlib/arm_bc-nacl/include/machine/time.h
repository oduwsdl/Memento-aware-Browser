#ifndef	_MACHTIME_H_
#define	_MACHTIME_H_

#if defined(__rtems__)
#define _CLOCKS_PER_SEC_  sysconf(_SC_CLK_TCK)
#else  /* !__rtems__ */
#if defined(__native_client__)
#define _CLOCKS_PER_SEC_ 1000000
#else  /* !__rtems__ && !__native_client__ */
#if defined(__aarch64__) || defined(__arm__) || defined(__thumb__)
#define _CLOCKS_PER_SEC_ 100
#endif
#endif
#endif /* !__rtems__ */

#ifdef __SPU__
#include <sys/types.h>
int nanosleep (const struct timespec *, struct timespec *);
#endif

#endif	/* _MACHTIME_H_ */


