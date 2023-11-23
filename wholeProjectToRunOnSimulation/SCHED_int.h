/********************************************/
/*  author: Mohamed Walid               	*/
/*  version: V02                            */
/*  Date: 18 NOV 2023	   					*/
/*  SWC : SCHEDULER                			*/
/********************************************/


#ifndef		SCHED_INT_H
#define 	SCHED_INT_H

typedef	enum {
	
	taskAdded, taskNotAdded
	
} TaskAdditionState_t;


void SCHED_voidInit(void);

/*
 * Created Tasks should have a parameter of type pointer to void
 */

TaskAdditionState_t SCHED_enumAddTask(void (*copy_pvTaskFunc)(void*), uint16 copy_uint16Periodicity, uint16 copy_uint16FirstDelay, uint8 copy_uint8Priority, uint8 copy_uint8TaskID);

void SCHED_voidDeleteTask(uint8 copy_uint8TaskID);

void SCHED_voidSuspendTask(uint8 copy_uint8TaskID);

void SCHED_voidResumeTask(uint8 copy_uint8TaskID);

void SCHED_voidStart(void);

// disable scheduler >> disables tasks being executed without affecting timer operation


#endif
