/*
 * periph.h
 *
 *  Created on: 8 sty 2019
 *      Author: rafal
 */
#include <msp430.h>

#ifndef PERIPH_H_
#define PERIPH_H_


void clock_Initalize(void);

void adc_Initalize(void);
void adc_startConversion(void);

void pwm_Initalize(void);

void timerA_Initalize(void);
inline void timerA_Stop(void);
inline void timerA_Start(void);

#endif /* PERIPH_H_ */
