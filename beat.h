/* 
 * File:   beat.h
 * Author: jonathansherman
 *
 * Created on April 24, 2019, 2:07 AM
 */
#include <stdbool.h>

#ifndef BEAT_H
#define	BEAT_H

void BEAT_init(void);
void BEAT_task(void);
bool BEAT_detected(void);

#endif	/* BEAT_H */

