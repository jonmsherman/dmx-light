#include <xc.h>
#include "clock.h"
#include "beat.h"

#define DELAY 100

static time_t lastTime = 0;

void LEDBlink_init()
{
    TRISCbits.TRISC5 = 0;
}

void LEDBlink_task()
{

    time_t time = CLOCK_getTime();
    
    // only run every 10 ms
    if (time - lastTime < DELAY)
        return;
    
    lastTime = time;
    
    if (BEAT_detected())
    {
        LATCbits.LATC5 = 1;
    } else
    {
        LATCbits.LATC5 = 0;
    }
    

}

