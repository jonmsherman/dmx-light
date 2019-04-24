/* 
 * File:   tm1650.h
 * Author: jonathansherman
 *
 * Created on March 26, 2019, 12:53 AM
 */

#ifndef TM1650_H
#define	TM1650_H

void TM1650_setDigit(uint8_t digit, uint8_t data, uint8_t DP);
void TM1650_init(void);
void TM1650_fastPrintNum(uint16_t num);
void TM1650_enable(bool enable);
bool TM1650_isEnabled(void);
#endif	/* TM1650_H */

