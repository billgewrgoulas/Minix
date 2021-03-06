#ifndef _MINIX_SCHED_H
#define _MINIX_SCHED_H

#include <minix/ipc.h>

_PROTOTYPE(int sched_stop, (endpoint_t scheduler_e, endpoint_t schedulee_e));
_PROTOTYPE(int sched_start, (endpoint_t scheduler_e, endpoint_t schedulee_e, 
	endpoint_t parent_e, int maxprio, int quantum, int cpu,
	endpoint_t *newscheduler_e));
_PROTOTYPE(int sched_inherit, (endpoint_t scheduler_e, 
	endpoint_t schedulee_e, endpoint_t parent_e, unsigned maxprio, 
	endpoint_t *newscheduler_e, pid_t procUsage));

#endif /* _MINIX_SCHED_H */
