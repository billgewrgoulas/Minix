#include "kernel/system.h"
#include <minix/endpoint.h>
#include "kernel/clock.h"

/*===========================================================================*
 *				do_schedule				     *
 *===========================================================================*/
PUBLIC int do_schedule(struct proc * caller, message * m_ptr)
{
	struct proc *p;
	int proc_nr;
	int priority, quantum, cpu, fss_priority;

	if (!isokendpt(m_ptr->SCHEDULING_ENDPOINT, &proc_nr))
		return EINVAL;

	p = proc_addr(_ENDPOINT_P(m_ptr->SCHEDULING_ENDPOINT));

	/* Only this process' scheduler can schedule it */
	if (caller != p->p_scheduler)
		return(EPERM);

	/* Try to schedule the process. */
	priority = (int) m_ptr->SCHEDULING_PRIORITY;
	quantum = (int) m_ptr->SCHEDULING_QUANTUM;
	cpu = (int) m_ptr->SCHEDULING_CPU;
	
	//p->fss_priority = (int) m_ptr->m9_l5; 
	fss_priority = (int) m_ptr->m9_l5; 

	return sched_proc(p, priority, quantum, cpu,fss_priority);
}
