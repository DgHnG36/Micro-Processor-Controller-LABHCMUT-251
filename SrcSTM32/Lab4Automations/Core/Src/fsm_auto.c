#include "fsm_auto.h"

/* DECLARE VARIABLE COUNTER */
uint8_t counter_ew = 0;
uint8_t counter_ns = 0;

/* STUPID FUNCTION */
static void control_led_traffic(uint8_t status_idx, uint8_t led_color) {
	switch (status_idx) {
	    case 0: // E-W direction
	        switch (led_color) {
	            case AUTO_RED: HAL_GPIO_WritePin(GPIOA, LED_RED_EW_Pin, GPIO_PIN_SET); break;
	            case AUTO_GREEN: HAL_GPIO_WritePin(GPIOA, LED_GREEN_EW_Pin, GPIO_PIN_SET); break;
	            case AUTO_AMBER: HAL_GPIO_WritePin(GPIOA, LED_AMBER_EW_Pin, GPIO_PIN_SET); break;
	            default: HAL_GPIO_WritePin(GPIOA, LED_RED_EW_Pin, GPIO_PIN_SET); break;
	        }
	        break;

	    case 1: //N-S direction
	        switch (led_color) {
	            case AUTO_RED: HAL_GPIO_WritePin(GPIOA, LED_RED_NS_Pin, GPIO_PIN_SET); break;
	            case AUTO_GREEN: HAL_GPIO_WritePin(GPIOA, LED_GREEN_NS_Pin, GPIO_PIN_SET); break;
	            case AUTO_AMBER: HAL_GPIO_WritePin(GPIOA, LED_AMBER_NS_Pin, GPIO_PIN_SET); break;
	            default: HAL_GPIO_WritePin(GPIOA, LED_RED_NS_Pin, GPIO_PIN_SET); break;
	        }
	        break;

	    default: break;
	}
}

/* FSM AUTO MODE */
void fsm_auto_run(void) {
	/* DISPLAY SEVEN SEG */
	if (isTimerExpired(2)) {
		setTimer(2, FSM_PERIOD);
		display_leds_nums(idx_auto_mode, counter_ew, counter_ns);
		idx_auto_mode = (idx_auto_mode + 1) % EN_COUNT;
	}
	/* SWITCH STATUS */
	switch(auto_status_ew) {
		case INIT_STATUS:
			auto_status_ew = AUTO_RED;
			counter_ew = time_red;
			setTimer(0, FSM_PERIOD * 4);
			break;
		case AUTO_RED:
			if (isTimerExpired(0)) {
				setTimer(0, FSM_PERIOD * 4);
				control_led_traffic(STATUS_EW, AUTO_RED);
				--counter_ew;
				if (counter_ew == 0) {
					auto_status_ew = AUTO_GREEN;
					counter_ew = time_green;
					turn_off_all_leds(STATUS_EW);
					control_led_traffic(STATUS_EW, AUTO_GREEN);
				}
			}
			break;
		case AUTO_GREEN:
			if (isTimerExpired(0)) {
				setTimer(0, FSM_PERIOD * 4);
				control_led_traffic(STATUS_EW, AUTO_GREEN);
				--counter_ew;
				if (counter_ew == 0) {
					auto_status_ew = AUTO_AMBER;
					counter_ew = time_amber;
					turn_off_all_leds(STATUS_EW);
					control_led_traffic(STATUS_EW, AUTO_AMBER);
				}
			}
			break;
		case AUTO_AMBER:
			if (isTimerExpired(0)) {
				setTimer(0, FSM_PERIOD * 4);
				control_led_traffic(STATUS_EW, AUTO_AMBER);
				--counter_ew;
				if (!counter_ew) {
					auto_status_ew = AUTO_RED;
					counter_ew = time_red;
					turn_off_all_leds(STATUS_EW);
					control_led_traffic(STATUS_EW, AUTO_RED);
				}
			}
			break;
		default:
			break;
	}
	switch(auto_status_ns) {
		case INIT_STATUS:
			auto_status_ns = AUTO_GREEN;
			counter_ns = time_green;
			setTimer(1, FSM_PERIOD * 4);
			break;
		case AUTO_RED:
			if (isTimerExpired(1)) {
				setTimer(1, FSM_PERIOD * 4);
				control_led_traffic(STATUS_NS, AUTO_RED);
				--counter_ns;
				if (!counter_ns) {
					auto_status_ns = AUTO_GREEN;
					counter_ns = time_green;
					turn_off_all_leds(STATUS_NS);
					control_led_traffic(STATUS_NS, AUTO_GREEN);
				}
			}
			break;
		case AUTO_GREEN:
			if (isTimerExpired(1)) {
				setTimer(1, FSM_PERIOD * 4);
				control_led_traffic(STATUS_NS, AUTO_GREEN);
				--counter_ns;
				if (!counter_ns) {
					auto_status_ns = AUTO_AMBER;
					counter_ns = time_amber;
					turn_off_all_leds(STATUS_NS);
					control_led_traffic(STATUS_NS, AUTO_AMBER);
				}
			}
			break;
		case AUTO_AMBER:
			if (isTimerExpired(1)) {
				setTimer(1, FSM_PERIOD * 4);
				control_led_traffic(STATUS_NS, AUTO_AMBER);
				--counter_ns;
				if (!counter_ns) {
					auto_status_ns = AUTO_RED;
					counter_ns = time_red;
					turn_off_all_leds(STATUS_NS);
					control_led_traffic(STATUS_NS, AUTO_RED);
				}
			}
			break;
		default:
			break;
		}
}
