#ifndef INC_DISPLAY_SEVEN_SEG_H_
#define INC_DISPLAY_SEVEN_SEG_H_

#ifdef __cplusplus
 extern "C" {
#endif


#include "main.h"
#include <stdbool.h>
#include <string.h>

#define NUMBER_COUNT 10
#define LED_SEGMENT_COUNT 7

void clear_all_leds(void);
void display_seven_SEG(uint8_t number);
void update_seven_SEG(uint8_t index, uint8_t number);

void display_leds_nums(uint8_t idx, uint8_t num1, uint8_t num2);



#endif /* INC_DISPLAY_SEVEN_SEG_H_ */
