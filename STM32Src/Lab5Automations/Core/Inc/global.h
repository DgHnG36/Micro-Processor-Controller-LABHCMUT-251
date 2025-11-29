#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "string.h"
#include <stdio.h>

#define UART_IDLE 61
#define UART_TRANS 62

#define COM_IDLE 50
#define COM_RST1 51
#define COM_RST2 52
#define COM_RST3 53
#define COM_RST4 54
#define COM_RST5 55
#define COM_RST6 56
#define COM_WAIT 57
#define COM_OK1 58
#define COM_OK2 59
#define COM_OK3 60

#define MAX_BUFFER_SIZE 30

extern char buffer_chr[MAX_BUFFER_SIZE];
extern uint8_t idx_buffer;
extern uint8_t buffer_flag;
extern uint8_t command_flag;
extern uint8_t adc_flag;
extern uint8_t start_flag;
extern uint32_t ADC_val;

extern char saved_previous[50];
extern uint8_t status_uart;
extern uint8_t status_com;


#endif /* INC_GLOBAL_H_ */
