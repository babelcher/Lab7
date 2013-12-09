#include "robot_sensors.h"
/*
 * robot_sensors.c
 *
 *  Created on: Dec 5, 2013
 *      Author: C15Brandon.Belcher
 */

void InitializeADC10() {
	ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
	ADC10CTL1 |= ADC10SSEL1 | ADC10SSEL0;                // Select SMCLK
}

void InitializeLEDPins(){
	P1DIR |= BIT0;
	P1DIR |= BIT6;
}

