#include "display_seven_SEG.h"

/* LED_7SEG */
static const uint8_t number_fonts[NUMBER_COUNT] ={
		0b1000000, // 0
		0b1111001, // 1
		0b0100100, // 2
		0b0110000, // 3
		0b0011001, // 4
		0b0010010, // 5
		0b0000010, // 6
		0b1111000, // 7
		0b0000000, // 8
		0b0010000  // 9
};

static const uint16_t led_7SEG_pins[LED_SEGMENT_COUNT] ={
		LED_7SEG_a_Pin,
		LED_7SEG_b_Pin,
		LED_7SEG_c_Pin,
		LED_7SEG_d_Pin,
		LED_7SEG_e_Pin,
		LED_7SEG_f_Pin,
		LED_7SEG_g_Pin
};


/* API FOR LED_7SEG */
void clear_all_leds(void) {
	HAL_GPIO_WritePin(GPIOB, EN_LED0_Pin|EN_LED1_Pin|EN_LED2_Pin|EN_LED3_Pin, GPIO_PIN_SET);
}

void display_seven_SEG(uint8_t number) {
	for (int idx = 0; idx < LED_SEGMENT_COUNT; ++idx) {
		HAL_GPIO_WritePin(GPIOB,
						  led_7SEG_pins[idx],
						  (number_fonts[number] & (1 << idx) ? GPIO_PIN_SET : GPIO_PIN_RESET));
	}
}

void update_seven_SEG(uint8_t index, uint8_t number) {
	clear_all_leds();
	display_seven_SEG(number);

	switch (index) {
		case 0: HAL_GPIO_WritePin(GPIOB, EN_LED0_Pin, GPIO_PIN_RESET); break;
	    case 1: HAL_GPIO_WritePin(GPIOB, EN_LED1_Pin, GPIO_PIN_RESET); break;
	    case 2: HAL_GPIO_WritePin(GPIOB, EN_LED2_Pin, GPIO_PIN_RESET); break;
	    case 3: HAL_GPIO_WritePin(GPIOB, EN_LED3_Pin, GPIO_PIN_RESET); break;
	    default: break;
	}
}

void display_leds_nums(uint8_t idx, uint8_t num1, uint8_t num2) {
	switch (idx) {
		case 0: update_seven_SEG(idx, num1 / 10); break;
		case 1: update_seven_SEG(idx, num1 % 10); break;
		case 2: update_seven_SEG(idx, num2 / 10); break;
		case 3: update_seven_SEG(idx, num2 % 10); break;
		default: break;
	}
}
