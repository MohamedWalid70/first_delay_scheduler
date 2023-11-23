/********************************************/
/*  author: Mohamed Walid               	*/
/*  version: V02                            */
/*  Date: 18 NOV 2023	   					*/
/*  SWC : SCHEDULER                			*/
/********************************************/


#ifndef		SCHED_PRIV_H
#define 	SCHED_PRIV_H

typedef	enum {

	waiting, running, ready, suspended

} TaskState_t;

typedef struct {

	void (*taskFunc)(void*);
	uint16 periodicity;
	uint16 firstDelay;
	uint8 taskID;
	TaskState_t taskState;

} Task_t;


static void SCHED_voidOrganize(void);


#endif
