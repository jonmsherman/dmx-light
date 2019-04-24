/* 
 * File:   buttons.h
 * Author: jonathansherman
 *
 * Created on April 23, 2019, 6:45 PM
 */
#include <stdint.h>
#include <stdbool.h>
#include "clock.h"

#ifndef BUTTONS_H
#define	BUTTONS_H



typedef enum {
    EVENT_IDLE,
    EVENT_PRESSED,
    EVENT_HELD
} event_t;

typedef enum {
    STATE_UNPRESSED,
    STATE_PRESSED
} btnState_t;

typedef struct {
    volatile uint8_t* port;
    uint8_t pin;
    btnState_t state;
    btnState_t lastState;
    event_t event;
    time_t holdTime;
} button_t;

extern button_t *up, *down, *enter, *menu;

void BUTTONS_task(void);
void BUTTONS_init(void);
bool BUTTONS_isClicked(button_t* button);
bool BUTTONS_isHeld(button_t* button);

#endif	/* BUTTONS_H */

