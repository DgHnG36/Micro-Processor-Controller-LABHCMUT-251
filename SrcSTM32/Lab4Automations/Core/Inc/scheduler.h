#ifndef __SCHEDULER_H
#define __SCHEDULER_H

#include <stdint.h>

/* DEFINE COUNT_TASK AND ERROR_CODE_G */
#define MAX_TASKS 40


typedef enum {
	STATUS_NORMAL = 0,
	STATUS_ERROR,
	ERROR_SCH_TOO_MANY_TASKS,
	ERROR_SCH_CANNOT_DELETE_TASK,
	ERROR_SCH_WAITING_FOR_SLAVE_TO_ACK,
	ERROR_SCH_WAITING_FOR_START_COMMAND_FROM_MASTER,
	ERROR_SCH_ONE_OR_MORE_SLAVES_DID_NOT_START,
	ERROR_SCH_LOST_SLAVE,
	ERROR_SCH_CAN_BUS_ERROR,
	ERROR_I2C_WRITE_BYTE_AT24C64
} sch_error_t;


/* DECLARE VARIABLE ERROR */
extern sch_error_t error_code_g;

/* Task structure */
typedef struct {
    void (*task_func)(void);     // Pointer to task function
    uint32_t delay;              // Delay (ticks) until the task runs
    uint32_t period;             // Period (ticks) for repeated tasks
    uint8_t run_me;              // Flag to indicate task should run
    uint8_t task_id;
} task_t;

/* Scheduler API */
void SCH_Init(void);
void SCH_Update(void);
void SCH_Report_Status(void);
void SCH_Dispatch_Tasks(void);
uint8_t SCH_Add_Task(void (*task_func)(void), uint32_t delay, uint32_t period);
sch_error_t SCH_Delete_Task(uint8_t task_id);

#endif /* __SCHEDULER_H */


