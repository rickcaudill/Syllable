/* Copyright (C) 1996-2000,2003,2004,2007 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

/*
 * ISO/IEC 9945-1:1996 6.7: Asynchronous Input and Output
 */

#ifndef _AIO_H
#define _AIO_H	1

#include <features.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>
#include <sys/types.h>

/* This is identical to the standard rt/aio.h file with the exception that we
   need the offset member toward the top of the struct to allow the kernel to
   mirror the interesting members with it's own version of the aiocb */

__BEGIN_DECLS

#include <posix/aio.h>

#ifdef __USE_GNU
/* To customize the implementation one can use the following struct.
   This implementation follows the one in Irix.  */
struct aioinit
  {
    int aio_threads;		/* Maximal number of threads.  */
    int aio_num;		/* Number of expected simultanious requests. */
    int aio_locks;		/* Not used.  */
    int aio_usedba;		/* Not used.  */
    int aio_debug;		/* Not used.  */
    int aio_numusers;		/* Not used.  */
    int aio_idle_time;		/* Number of seconds before idle thread
				   terminates.  */
    int aio_reserved;
  };
#endif


/* Return values of cancelation function.  */
enum
{
  AIO_CANCELED,
#define AIO_CANCELED AIO_CANCELED
  AIO_NOTCANCELED,
#define AIO_NOTCANCELED AIO_NOTCANCELED
  AIO_ALLDONE
#define AIO_ALLDONE AIO_ALLDONE
};


/* Synchronization options for `lio_listio' function.  */
enum
{
  LIO_WAIT,
#define LIO_WAIT LIO_WAIT
  LIO_NOWAIT
#define LIO_NOWAIT LIO_NOWAIT
};


/* Allow user to specify optimization.  */
#ifdef __USE_GNU
extern void aio_init (__const struct aioinit *__init) __THROW __nonnull ((1));
#endif


#ifndef __USE_FILE_OFFSET64
/* Enqueue read request for given number of bytes and the given priority.  */
extern int aio_read (struct aiocb *__aiocbp) __THROW __nonnull ((1));
/* Enqueue write request for given number of bytes and the given priority.  */
extern int aio_write (struct aiocb *__aiocbp) __THROW __nonnull ((1));

/* Initiate list of I/O requests.  */
extern int lio_listio (int __mode,
		       struct aiocb *__const __list[__restrict_arr],
		       int __nent, struct sigevent *__restrict __sig)
  __THROW __nonnull ((2));

/* Retrieve error status associated with AIOCBP.  */
extern int aio_error (__const struct aiocb *__aiocbp) __THROW __nonnull ((1));
/* Return status associated with AIOCBP.  */
extern __ssize_t aio_return (struct aiocb *__aiocbp) __THROW __nonnull ((1));

/* Try to cancel asynchronous I/O requests outstanding against file
   descriptor FILDES.  */
extern int aio_cancel (int __fildes, struct aiocb *__aiocbp) __THROW;

/* Suspend calling thread until at least one of the asynchronous I/O
   operations referenced by LIST has completed.

   This function is a cancellation point and therefore not marked with
   __THROW.  */
extern int aio_suspend (__const struct aiocb *__const __list[], int __nent,
			__const struct timespec *__restrict __timeout)
  __nonnull ((1));

/* Force all operations associated with file desriptor described by
   `aio_fildes' member of AIOCBP.  */
extern int aio_fsync (int __operation, struct aiocb *__aiocbp)
  __THROW __nonnull ((2));
#else
# ifdef __REDIRECT_NTH
extern int __REDIRECT_NTH (aio_read, (struct aiocb *__aiocbp), aio_read64)
  __nonnull ((1));
extern int __REDIRECT_NTH (aio_write, (struct aiocb *__aiocbp), aio_write64)
  __nonnull ((1));

extern int __REDIRECT_NTH (lio_listio,
			   (int __mode,
			    struct aiocb *__const __list[__restrict_arr],
			    int __nent, struct sigevent *__restrict __sig),
			   lio_listio64) __nonnull ((2));

extern int __REDIRECT_NTH (aio_error, (__const struct aiocb *__aiocbp),
			   aio_error64) __nonnull ((1));
extern __ssize_t __REDIRECT_NTH (aio_return, (struct aiocb *__aiocbp),
				 aio_return64) __nonnull ((1));

extern int __REDIRECT_NTH (aio_cancel,
			   (int __fildes, struct aiocb *__aiocbp),
			   aio_cancel64);

extern int __REDIRECT_NTH (aio_suspend,
			   (__const struct aiocb *__const __list[], int __nent,
			    __const struct timespec *__restrict __timeout),
			   aio_suspend64) __nonnull ((1));

extern int __REDIRECT_NTH (aio_fsync,
			   (int __operation, struct aiocb *__aiocbp),
			   aio_fsync64) __nonnull ((2));

# else
#  define aio_read aio_read64
#  define aio_write aio_write64
#  define lio_listio lio_listio64
#  define aio_error aio_error64
#  define aio_return aio_return64
#  define aio_cancel aio_cancel64
#  define aio_suspend aio_suspend64
#  define aio_fsync aio_fsync64
# endif
#endif

#ifdef __USE_LARGEFILE64
extern int aio_read64 (struct aiocb64 *__aiocbp) __THROW __nonnull ((1));
extern int aio_write64 (struct aiocb64 *__aiocbp) __THROW __nonnull ((1));

extern int lio_listio64 (int __mode,
			 struct aiocb64 *__const __list[__restrict_arr],
			 int __nent, struct sigevent *__restrict __sig)
  __THROW __nonnull ((2));

extern int aio_error64 (__const struct aiocb64 *__aiocbp)
  __THROW __nonnull ((1));
extern __ssize_t aio_return64 (struct aiocb64 *__aiocbp)
  __THROW __nonnull ((1));

extern int aio_cancel64 (int __fildes, struct aiocb64 *__aiocbp) __THROW;

extern int aio_suspend64 (__const struct aiocb64 *__const __list[], int __nent,
			  __const struct timespec *__restrict __timeout)
  __THROW __nonnull ((1));

extern int aio_fsync64 (int __operation, struct aiocb64 *__aiocbp)
  __THROW __nonnull ((2));
#endif

__END_DECLS

#endif /* aio.h */
