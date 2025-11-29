#include "global.h"


/* DECLARE GLOBAL VARIABLE */
uint8_t idx_mode = 0;
uint8_t idx_auto_mode = 0;

uint8_t auto_status_ew = 0;
uint8_t auto_status_ns = 0;
uint8_t mode_status = 0;

uint8_t time_red = RED_DEFAULT;
uint8_t time_amber = AMBER_DEFAULT;
uint8_t time_green = GREEN_DEFAULT;

uint8_t time_red_count = RED_DEFAULT;
uint8_t time_amber_count = AMBER_DEFAULT;
uint8_t time_green_count = GREEN_DEFAULT;


/* IMPLEMENT GENETIC API
 * @status_idx 0, 1 for fsm_auto
 * @status_idx else for fsm_man
 */
void turn_off_all_leds(uint8_t status_idx) {
	if (status_idx == 0) {
		HAL_GPIO_WritePin(GPIOA, LED_RED_EW_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED_AMBER_EW_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_EW_Pin, GPIO_PIN_RESET);
	}
	else if (status_idx == 1){
		HAL_GPIO_WritePin(GPIOA, LED_RED_NS_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED_AMBER_NS_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_NS_Pin, GPIO_PIN_RESET);
	}
	else {
		HAL_GPIO_WritePin(GPIOA, LED_RED_EW_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED_AMBER_EW_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_EW_Pin, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(GPIOA, LED_RED_NS_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED_AMBER_NS_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_NS_Pin, GPIO_PIN_RESET);
	}
}
