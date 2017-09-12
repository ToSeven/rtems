/**
 * @file
 *
 * @brief Initialize POSIX API
 *
 * @ingroup ClassicRTEMS
 */

/*
 *  COPYRIGHT (c) 1989-2014.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.org/license/LICENSE.
 */

#if HAVE_CONFIG_H
#include "config.h"
#endif

#include <rtems/posix/posixapi.h>
#include <rtems/posix/semaphoreimpl.h>
#include <rtems/score/heap.h>

#ifdef HEAP_PROTECTION
RTEMS_STATIC_ASSERT(
  POSIX_SEMAPHORE_MAGIC != HEAP_BEGIN_PROTECTOR_0,
  POSIX_SEMAPHORE_MAGIC_0
);
RTEMS_STATIC_ASSERT(
  POSIX_SEMAPHORE_MAGIC != HEAP_BEGIN_PROTECTOR_1,
  POSIX_SEMAPHORE_MAGIC_1
);
RTEMS_STATIC_ASSERT(
  POSIX_SEMAPHORE_MAGIC != HEAP_END_PROTECTOR_0,
  POSIX_SEMAPHORE_MAGIC_2
);
RTEMS_STATIC_ASSERT(
  POSIX_SEMAPHORE_MAGIC != HEAP_END_PROTECTOR_1,
  POSIX_SEMAPHORE_MAGIC_3
);
RTEMS_STATIC_ASSERT(
  POSIX_SEMAPHORE_MAGIC != HEAP_FREE_PATTERN,
  POSIX_SEMAPHORE_MAGIC_4
);
#endif

void _POSIX_Fatal_error( POSIX_Fatal_domain domain, int eno )
{
  uint32_t code = ( domain << 8 ) | ( ( uint32_t ) eno & 0xffU );

  _Terminate( INTERNAL_ERROR_POSIX_API, code );
}
