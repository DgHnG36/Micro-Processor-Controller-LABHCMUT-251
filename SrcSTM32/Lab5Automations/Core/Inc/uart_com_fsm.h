#ifndef INC_UART_COM_FSM_H_
#define INC_UART_COM_FSM_H_

#include "global.h"
#include "software_timer.h"

extern char str[50];
extern char saved_packet[50];

void uart_communication_fsm(void);

#endif /* INC_UART_COM_FSM_H_ */
