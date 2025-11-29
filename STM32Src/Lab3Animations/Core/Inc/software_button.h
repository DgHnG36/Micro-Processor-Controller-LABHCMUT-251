#ifndef INC_SOFTWARE_BUTTON_H_
#define INC_SOFTWARE_BUTTON_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

#define BUTTON_CAPACITY       3
#define LONG_PRESSED_TIME     100

#define RELEASED              1
#define PRESSED               0

typedef enum {
    BUTTON_RELEASED = 0,
    BUTTON_PRESSED,
    BUTTON_LONG_PRESSED
} Button_state_t;

void buttonInit(void);
void buttonReading(void);
uint8_t isButtonPressed(uint8_t index);
uint8_t isButtonReleased(uint8_t index);
uint8_t isButtonLongPressed(uint8_t index);

#ifdef __cplusplus
}
#endif

#endif /* INC_SOFTWARE_BUTTON_H_ */
