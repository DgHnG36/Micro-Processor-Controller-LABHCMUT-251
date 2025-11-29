#include "fsm_man.h"


void fsm_man_run(void) {
	switch(mode_status) {
		case INIT_STATUS:
			mode_status = AUTO_MODE;
			turn_off_all_leds(3);
			auto_status_ew = INIT_STATUS;
			auto_status_ns = INIT_STATUS;
			setTimer(2, FSM_PERIOD);
			break;
		case AUTO_MODE:
			fsm_auto_run();
			if (isButtonPressed(0) == 1 || isButtonLongPressed(0) == 1) {
				mode_status = RED_INC_MODE;
				turn_off_all_leds(3);
			}
			break;
		case RED_INC_MODE:
			HAL_GPIO_TogglePin(LED_RED_EW_GPIO_Port, LED_RED_EW_Pin);
			HAL_GPIO_TogglePin(LED_RED_NS_GPIO_Port, LED_RED_NS_Pin);

			display_leds_nums(idx_mode, time_red_count, RED_INC_MODE);
			idx_mode = (idx_mode + 1) % EN_COUNT;
			if (isButtonPressed(1) == 1 || isButtonLongPressed(1) == 1) {
				++time_red_count;
				if (time_red_count > 99) {
					time_red_count = RED_DEFAULT;
				}
			}
			if (isButtonPressed(0) == 1 || isButtonLongPressed(0) == 1) {
				mode_status = AMBER_INC_MODE;
				turn_off_all_leds(3);
			}
			if (isButtonPressed(2) == 1 || isButtonLongPressed(2) == 1) {
				mode_status = SAVE_MODE;
			}
			break;
		case AMBER_INC_MODE:
			HAL_GPIO_TogglePin(LED_AMBER_EW_GPIO_Port, LED_AMBER_EW_Pin);
			HAL_GPIO_TogglePin(LED_AMBER_NS_GPIO_Port, LED_AMBER_NS_Pin);

			display_leds_nums(idx_mode, time_amber_count, AMBER_INC_MODE);
			idx_mode = (idx_mode + 1) % EN_COUNT;

			if (isButtonPressed(1) == 1 || isButtonLongPressed(1) == 1) {
				++time_amber_count;
				if (time_amber_count > 99) {
					time_amber_count = AMBER_DEFAULT;
				}
			}
			if (isButtonPressed(0) == 1 || isButtonLongPressed(0) == 1) {
				mode_status = GREEN_INC_MODE;
				turn_off_all_leds(3);
			}
			if (isButtonPressed(2) == 1 || isButtonLongPressed(2) == 1) {
				mode_status = SAVE_MODE;
			}
			break;
		case GREEN_INC_MODE:
			HAL_GPIO_TogglePin(LED_GREEN_EW_GPIO_Port, LED_GREEN_EW_Pin);
			HAL_GPIO_TogglePin(LED_GREEN_NS_GPIO_Port, LED_GREEN_NS_Pin);

			display_leds_nums(idx_mode, time_green_count, GREEN_INC_MODE);
			idx_mode = (idx_mode + 1) % EN_COUNT;
			if (isButtonPressed(1) == 1 || isButtonLongPressed(1) == 1) {
				++time_green_count;
				if (time_green_count > 99) {
					time_green_count = GREEN_DEFAULT;
				}
			}
			if (isButtonPressed(0) == 1 || isButtonLongPressed(0) == 1) {
				mode_status = AUTO_MODE;
				turn_off_all_leds(3);
			}
			if (isButtonPressed(2) == 1 || isButtonLongPressed(2) == 1) {
				mode_status = SAVE_MODE;
			}
			break;
		case SAVE_MODE:
			turn_off_all_leds(3);
			clear_all_leds();

			time_red = time_red_count;
			time_amber = time_amber_count;
			time_green = time_green_count;

			mode_status = INIT_STATUS;
			break;
		default:
			break;
	}
}
