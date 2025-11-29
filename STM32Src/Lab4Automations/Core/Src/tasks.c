#include "tasks.h"
#include "main.h"


/* TASK FSM */
void taskFSM() {
	fsm_man_run();
}

void taskTimerRun() {
	timerRun();
}

void taskButtonRead() {
	buttonReading();
}

void taskBlinkLED() {
	HAL_GPIO_TogglePin(LED_BLINKY_05_GPIO_Port, LED_BLINKY_05_Pin);
}

void taskInitFSM(void) {
	SCH_Add_Task(taskBlinkLED, 0, 200);
	SCH_Add_Task(taskTimerRun, 0, 1);
	SCH_Add_Task(taskButtonRead, 0, 1);
	SCH_Add_Task(taskFSM, 0, FSM_PERIOD);
}

/* TASK BLINK LED */

void task1() {
	HAL_GPIO_TogglePin(LED_BLINKY_05_GPIO_Port, LED_BLINKY_05_Pin);
	display_leds_nums(4, 1, 0);
}

void task2() {
	HAL_GPIO_TogglePin(LED_BLINKY_10_GPIO_Port, LED_BLINKY_10_Pin);
	display_leds_nums(4, 2, 0);
}

void task3() {
	HAL_GPIO_TogglePin(LED_BLINKY_15_GPIO_Port, LED_BLINKY_15_Pin);
	display_leds_nums(4, 3, 0);
}

void task4() {
	HAL_GPIO_TogglePin(LED_BLINKY_20_GPIO_Port, LED_BLINKY_20_Pin);
	display_leds_nums(4, 4, 0);
}

void task5() {
	HAL_GPIO_TogglePin(LED_BLINKY_25_GPIO_Port, LED_BLINKY_25_Pin);
	display_leds_nums(4, 5, 0);
}

/* TASK ONE-SHOT */
void task_one_shot0() {
	HAL_GPIO_TogglePin(LED_BLINKY_05_GPIO_Port, LED_BLINKY_05_Pin);
	display_leds_nums(4, 6, 0);
}

void task_one_shot1() {
	HAL_GPIO_TogglePin(LED_BLINKY_10_GPIO_Port, LED_BLINKY_05_Pin);
	display_leds_nums(4, 7, 0);
}

void task_one_shot2() {
	HAL_GPIO_TogglePin(LED_BLINKY_15_GPIO_Port, LED_BLINKY_15_Pin);
	display_leds_nums(4, 8, 0);
}

