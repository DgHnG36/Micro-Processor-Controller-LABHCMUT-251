#include "scheduler.h"
#include "software_timer.h"
#include <string.h>

/* DECLARE VAR GLOBAL */
sch_error_t error_code_g;

static task_t task_array[MAX_TASKS];
static uint8_t num_tasks = 0;
static uint16_t next_task_id = 0;




/* Extra functions Utilities for scheduler
 * rm0_task : Remove task at first
 */
static void rm0_task(void) {
	for (int i = 0; i < num_tasks - 1; i++) {
		task_array[i] = task_array[i +1];
	}
	--num_tasks;

	task_array[num_tasks].task_func = 0;
	task_array[num_tasks].delay = 0;
	task_array[num_tasks].period = 0;
	task_array[num_tasks].run_me = 0;
	task_array[num_tasks].task_id = 0x1F;
}



/*
 * Initialize the scheduler
 * Call this function before using the scheduler
 */
void SCH_Init(void) {
    uint8_t i;
    if (num_tasks != 0) {
    	for (i = 0; i < MAX_TASKS; i++) {
    		SCH_Delete_Task(i);
    	}
    }
    error_code_g = 0;

    //TimerInit
    setTimer(3, 100);
    setTimer(4, 50);
    setTimer(5, 100);
    setTimer(6, 150);
    setTimer(7, 200);
    setTimer(8, 250);
}

/*
 * Update scheduler - should be called every tick (e.g., in timer ISR)
 * This function updates the delay counters and sets run flags
 */
void SCH_Update(void) {
   if (num_tasks > 0)  {
	   if (task_array[0].delay > 0) {
		   task_array[0].delay--;
	   }
	   else {
		   task_array[0].run_me ++;
	   }
   }
}

/*
 * Add a task to the scheduler
 * Add by insertion-sorte explanation
 * Tasks are added using an insertion-sort approach. Instead of appending to the end,
 * the new task is inserted into the list based on its (delay + accumulate delay) value. This keeps the
 * task list ordered by execution time without requiring a full list sort.
 * @param task_func: Pointer to the task function
 * @param delay: Initial delay in ticks before first run
 * @param period: Period in ticks (0 = run once)
 * @return: Task ID (0-MAX_TASKS-1) or MAX_TASKS if failed
 */

uint8_t SCH_Add_Task_with_ID(void (*task_func)(void), uint32_t delay, uint32_t period, uint16_t task_id) {
    uint8_t idx = 0;
    uint8_t accumulated_delay = 0;

    if (num_tasks >= MAX_TASKS) {
    	error_code_g = ERROR_SCH_TOO_MANY_TASKS;
    	return MAX_TASKS;
    }
    /* Check error
     * if(){}
     */
    while (idx < num_tasks) {
    	if (delay < accumulated_delay + task_array[idx].delay) {
    		break;
    	}
    	accumulated_delay += task_array[idx].delay;
    	++idx;
    }

    for (int j = num_tasks; j > idx; --j) {
    	task_array[j] = task_array[j - 1];
    }

    task_array[idx].task_func = task_func;
    task_array[idx].delay = delay - accumulated_delay;
    task_array[idx].period = period;
    task_array[idx].run_me = 0;
    task_array[idx].task_id = task_id;

    if (idx < num_tasks) {
    	task_array[idx + 1].delay -= task_array[idx].delay;
    }

    ++num_tasks;
    error_code_g = STATUS_NORMAL;
    return idx;
}

uint8_t SCH_Add_Task(void (*task_func)(void), uint32_t delay, uint32_t period) {
    return SCH_Add_Task_with_ID(task_func, delay, period, next_task_id++);
}

/*
 * Dispatch (run) tasks that are due
 * Call this function in the main loop
 */
void SCH_Dispatch_Tasks(void) {
	if (num_tasks == 0) return;

	if (task_array[0].run_me > 0) {
		(*task_array[0].task_func)();
		task_array[0].run_me--;

		if (task_array[0].period > 0) {
			uint32_t new_delay = task_array[0].period;
			void (*new_task_func)(void) = task_array[0].task_func;
			uint32_t new_period = task_array[0].period;
			uint16_t new_ID = task_array[0].task_id;

			rm0_task();

			SCH_Add_Task_with_ID(new_task_func, new_delay, new_period, new_ID);
		}
		else {
			rm0_task();
		}
	}
}

/*
 * Delete a task from the scheduler
 * @param task_id: ID of the task to delete
 * @return: 1 if successful, 0 if failed
 */
sch_error_t SCH_Delete_Task(uint8_t task_id) {
	int pos = -1;
	for (uint8_t i = 0; i < num_tasks; i++) {
		if (task_array[i].task_id == task_id) {
			pos = i;
			break;
		}
	}

	if (pos == -1) {
    	error_code_g = ERROR_SCH_CANNOT_DELETE_TASK;
    	return 1;
    }

	for (uint8_t j = pos; j < num_tasks - 1; j++) {
		task_array[j] = task_array[j + 1];
	}

	--num_tasks;
	task_array[num_tasks].task_func = 0;
	task_array[num_tasks].delay = 0;
	task_array[num_tasks].period = 0;
	task_array[num_tasks].run_me = 0;
	task_array[num_tasks].task_id = 0x1F;

	return 0;
}

/*
 * Report system status
 * Display error code if any error occurred
 */
void SCH_Report_Status(void) {
#ifdef SCH_REPORT_ERRORS
    // Only report if this is a new error
    static uint8_t last_error_code_g = 0;

    if (error_code_g != last_error_code_g) {
        // Report error
        // Can be implemented with UART, LED, etc.
        // Example: Send error code via UART
        // printf("Error code: %d\n", error_code_g);

        last_error_code_g = error_code_g;

        if (error_code_g != 0) {
            // Handle error - could flash LED, send to UART, etc.
            // Error_Port = error_code_g;
        }
    }
#endif
}



