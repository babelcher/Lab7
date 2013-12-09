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

unsigned int LeftSensorReading() {
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 = INCH_3;                       // input A3
	ADC10AE0 |= BIT3;                         // PA.1 ADC option select
	ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	__bis_SR_register(CPUOFF + GIE);
	// LPM0, ADC10_ISR will force exit

	return ADC10MEM;
}

unsigned int RightSensorReading() {
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 = INCH_4;                       // input A3
	ADC10AE0 |= BIT4;                         // PA.1 ADC option select
	ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	__bis_SR_register(CPUOFF + GIE);		// LPM0, ADC10_ISR will force exit

	return ADC10MEM;
}

// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void) {
	__bic_SR_register_on_exit(CPUOFF);
	// Clear CPUOFF bit from 0(SR)
}

