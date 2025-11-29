#ifndef INC_FSM_AUTOM_H_
#define INC_FSM_AUTO_H_

#include "global.h"
#include "main.h"
#include "display_seven_SEG.h"

#define STATUS_EW 0
#define STATUS_NS 1

extern uint8_t counter_ew;
extern uint8_t counter_ns;

void fsm_auto_run();

#endif /* INC_FSM_AUTO_H_ */
