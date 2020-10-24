#ifndef __SYS_LOCK_H__
#define __SYS_LOCK_H__

/*
 * The structure below mimics the layout of pthread_mutex_t as defined in
 * pthread.h (native_client/tools/nc_threads/pthread.h). Including pthread.h
 * from here causes include conflicts. When changing any the definition in
 * pthreads.h, make sure to change this file too.
 */

typedef struct __local_pthread_mutex_t {
  int spinlock;
  int mutex_type;
  int owner_thread_id;
  int recursion_counter;
  int mutex_handle;
} _LOCK_T;
typedef _LOCK_T _LOCK_RECURSIVE_T;

#define __LOCAL_PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP \
    {0, 1, (0xffffffff), 0, -1}
#define __LOCAL_PTHREAD_MUTEX_INITIALIZER {0, 0, (0xffffffff), 0, -1}


/*
 * The locking functions are declared as weak symbols in libnacl
 * and as strong symbols in libpthread
 */
extern void __local_lock_init(_LOCK_T* lock);
extern void __local_lock_init_recursive(_LOCK_T* lock);
extern void __local_lock_close(_LOCK_T* lock);
extern void __local_lock_close_recursive(_LOCK_T* lock);
extern void __local_lock_acquire(_LOCK_T* lock);
extern void __local_lock_acquire_recursive(_LOCK_T* lock);
extern int __local_lock_try_acquire(_LOCK_T* lock);
extern int __local_lock_try_acquire_recursive(_LOCK_T* lock);
extern void __local_lock_release(_LOCK_T* lock);
extern void __local_lock_release_recursive(_LOCK_T* lock);

#define __LOCK_INIT(CLASS,NAME) \
    CLASS _LOCK_T NAME = __LOCAL_PTHREAD_MUTEX_INITIALIZER;
#define __LOCK_INIT_RECURSIVE(CLASS,NAME) \
    CLASS _LOCK_RECURSIVE_T NAME= \
    __LOCAL_PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;

#define __lock_init(NAME) __local_lock_init(&(NAME))
#define __lock_init_recursive(NAME) __local_lock_init_recursive(&(NAME))
#define __lock_close(NAME) __local_lock_close(&(NAME))
#define __lock_close_recursive(NAME) __local_lock_close_recursive(&(NAME))
#define __lock_acquire(NAME) __local_lock_acquire(&(NAME))
#define __lock_acquire_recursive(NAME) __local_lock_acquire_recursive(&(NAME))
#define __lock_try_acquire(NAME) __local_lock_try_acquire(&(NAME))
#define __lock_try_acquire_recursive(NAME) \
    __local_lock_try_acquire_recursive(&(NAME))
#define __lock_release(NAME) __local_lock_release(&(NAME))
#define __lock_release_recursive(NAME) __local_lock_release_recursive(&(NAME))

#endif /* __SYS_LOCK_H__ */
