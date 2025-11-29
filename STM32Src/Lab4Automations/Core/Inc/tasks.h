#ifndef INC_TASK_H_
#define INC_TASK_H_

#include "fsm_man.h"
#include <stdio.h>
#include "software_timer.h"
#include "display_seven_SEG.h"

void taskInitFSM(void);

void task1(void);
void task2(void);
void task3(void);
void task4(void);
void task5(void);

void task_one_shot0(void);
void task_one_shot1(void);
void task_one_shot2(void);


#endif /* INC_TASK_H_ */
