/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
#ifndef _UAPI_LINUX_IOPRIO_H
#define _UAPI_LINUX_IOPRIO_H

/*
 * Gives us 8 prio classes with 13-bits of data for each class
 */
#define IOPRIO_CLASS_SHIFT	13
#define IOPRIO_CLASS_MASK	0x07
#define IOPRIO_PRIO_MASK	((1UL << IOPRIO_CLASS_SHIFT) - 1)

#define IOPRIO_PRIO_CLASS(ioprio)	\
	(((ioprio) >> IOPRIO_CLASS_SHIFT) & IOPRIO_CLASS_MASK)
#define IOPRIO_PRIO_DATA(ioprio)	((ioprio) & IOPRIO_PRIO_MASK)
#define IOPRIO_PRIO_VALUE(class, data)	\
	(((class) << IOPRIO_CLASS_SHIFT) | ((data) & IOPRIO_PRIO_MASK))

/*
 * These are the io priority groups as implemented by CFQ. RT is the realtime
 * class, it always gets premium service. BE is the best-effort scheduling
 * class, the default for any process. IDLE is the idle scheduling class, it
 * is only served when no one else is using the disk.
 */
enum {
	IOPRIO_CLASS_NONE,
	IOPRIO_CLASS_RT,
	IOPRIO_CLASS_BE,
	IOPRIO_CLASS_IDLE,

	IOPRIO_CLASS_MAX,
};

/*
 * The RT and BE priority classes both support up to 8 priority levels.
 */
#define IOPRIO_NR_LEVELS	8

enum {
	IOPRIO_WHO_PROCESS = 1,
	IOPRIO_WHO_PGRP,
	IOPRIO_WHO_USER,
};

/*
 * Fallback BE priority level.
 */
#define IOPRIO_BE_NORM	4

#endif /* _UAPI_LINUX_IOPRIO_H */
