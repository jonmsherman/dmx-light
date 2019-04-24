#ifndef LED_H
#define	LED_H

#include <stdint.h>

typedef enum
{
    MODE_AUTO,
    MODE_DMX,
    MODE_SOUND
} mode_t;

typedef struct
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t white;
} color_t;

void LED_init();
void LED_setMode(mode_t mode);
void LED_task();

#endif	/* LED_H */