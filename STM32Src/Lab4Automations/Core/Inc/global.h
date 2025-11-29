#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_button.h"
#include "software_timer.h"
#include "main.h"

#define FSM_PERIOD 10

/* DEFINE VARIABLE */
#define INIT_STATUS 0
#define AUTO_RED 1
#define AUTO_GREEN 2
#define AUTO_AMBER 3

#define MODE_COUNT 4
#define AUTO_MODE 10
#define RED_INC_MODE 20
#define AMBER_INC_MODE 30
#define GREEN_INC_MODE 40
#define SAVE_MODE 50

#define EN_COUNT 4
#define RED_DEFAULT 5
#define AMBER_DEFAULT 2
#define GREEN_DEFAULT 3

/* INDEX FSM_MAN AND FSM_AUTO */
extern uint8_t idx_mode;
extern uint8_t idx_auto_mode;

/* STATUS FSM_MAN AND FSM_AUTO */
extern uint8_t auto_status_ew;
extern uint8_t auto_status_ns;
extern uint8_t mode_status;

/* TIME LED TRAFFIC FOR FSM_AUTO*/
extern uint8_t time_red;
extern uint8_t time_amber;
extern uint8_t time_green;

/* TIME LED TRAFFIC COUNT FOR FSM_MAN */
extern uint8_t time_red_count;
extern uint8_t time_amber_count;
extern uint8_t time_green_count;

/* GENERIC API */
void turn_off_all_leds(uint8_t status_idx);


#endif /* INC_GLOBAL_H_ */
