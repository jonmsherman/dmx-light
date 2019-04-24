#include "controller.h"
#include "buttons.h"
#include "clock.h"
#include "tm1650.h"

uint16_t address = 1;
static time_t lastTime = 0;
static uint8_t delayTime = 0;
void CONTROLLER_init() {
    TM1650_fastPrintNum(address);
}

/**
 * Increments the address and updates the display
 */
void address_inc()
{
    if(address == 512)
        address = 1;
    else
        address++;
    
    // update the display
    TM1650_fastPrintNum(address);
}

/**
 * Decrements the address and updates the display
 */
void address_dec() 
{
    if(address == 1)
        address = 512;
    else
        address--;  
    
    // update the display
    TM1650_fastPrintNum(address);
}

void CONTROLLER_task() {
    time_t time = CLOCK_getTime();

    // only run every 10 ms
    if (time - lastTime < delayTime)
        return;

    lastTime = time;
    
    if (BUTTONS_isClicked(up)) 
    {
        address_inc();
    } 
    else if (BUTTONS_isClicked(down)) 
    {
        address_dec();
    } 
    else if ( BUTTONS_isHeld(up))
    {
       address_inc();
        if (delayTime == 0)
            delayTime = 100;

        if(delayTime > 10)
            delayTime--;
    } 
    else if ( BUTTONS_isHeld(down))
    {
       address_dec();
        if (delayTime == 0)
            delayTime = 100;

        if(delayTime > 10)
            delayTime--;
    } 
    else 
    {
        delayTime = 0;
    }
}