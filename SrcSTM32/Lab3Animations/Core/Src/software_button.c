#include "software_button.h"

/* DEMO FOR LAB3 */

/* DECLARE VARIABLE AND FLAG */
const uint16_t button_pins[BUTTON_CAPACITY] = {
    BUTTON_ONE_Pin,   // Button 1
    BUTTON_TWO_Pin,   // Button 2
    BUTTON_THREE_Pin  // Button 3
};

GPIO_TypeDef* button_ports[BUTTON_CAPACITY] = {
	BUTTON_ONE_GPIO_Port,
	BUTTON_TWO_GPIO_Port,
    BUTTON_THREE_GPIO_Port
};


static uint8_t key_reg0[BUTTON_CAPACITY];
static uint8_t key_reg1[BUTTON_CAPACITY];
static uint8_t key_reg2[BUTTON_CAPACITY];
static uint8_t key_reg3[BUTTON_CAPACITY];

static uint8_t button_flag_released[BUTTON_CAPACITY];
static uint8_t button_flag_pressed[BUTTON_CAPACITY];
static uint8_t button_flag_long_pressed[BUTTON_CAPACITY];

static uint8_t long_pressed_counter[BUTTON_CAPACITY];

/* API FOR SOFTWARE_BUTTON */

void buttonInit(void) {
	for (int i = 0; i < BUTTON_CAPACITY; ++i) {
		key_reg3[i] = RELEASED;
		key_reg2[i] = key_reg3[i];
		key_reg1[i] = key_reg2[i];
		key_reg0[i] = key_reg1[i];

		button_flag_pressed[i] = 0;
		button_flag_released[i] = 0;
		button_flag_long_pressed[i] = 0;

		long_pressed_counter[i] = 0;
	}
}

void buttonReading(void) {
	for (int i = 0; i < BUTTON_CAPACITY; ++i) {
		key_reg0[i] = key_reg1[i];
		key_reg1[i] = key_reg2[i];
		key_reg2[i] = HAL_GPIO_ReadPin(button_ports[i], button_pins[i]);

		if ((key_reg0[i] == key_reg1[i]) && (key_reg2[i] == key_reg1[i])) {
			if  (key_reg3[i] != key_reg2[i]) {
				key_reg3[i] = key_reg2[i];

				if (key_reg3[i] == PRESSED) {
					button_flag_pressed[i] = 1;
					button_flag_released[i] = 0;
					long_pressed_counter[i] = 0;
				}
				else {
					button_flag_pressed[i] = 0;
					button_flag_released[i] = 1;
					long_pressed_counter[i] = 0;
				}
			}
			else {
				if (key_reg3[i] == PRESSED) {
					if (long_pressed_counter[i] < LONG_PRESSED_TIME) {
						++long_pressed_counter[i];
					}
					else {
						button_flag_long_pressed[i] = 1;
					}
				}
			}
		}
	}
}

uint8_t isButtonPressed(uint8_t index) {
	if (index < BUTTON_CAPACITY && button_flag_pressed[index] == 1) {
		button_flag_pressed[index] = 0;
		return 1;
	}
	return 0;
}

uint8_t isButtonReleased(uint8_t index) {
	if (index < BUTTON_CAPACITY && button_flag_released[index] == 1) {
		button_flag_released[index] = 0;
		return 1;
	}
	return 0;
}

uint8_t isButtonLongPressed(uint8_t index) {
	if (index < BUTTON_CAPACITY && button_flag_long_pressed[index] == 1) {
		button_flag_long_pressed[index] = 0;
		return 1;
	}
	return 0;
}
