#include <msp430g2553.h>

/*
 * main.c
 */
int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	P1DIR |= BIT0;
	P1DIR |= BIT6;

	InitializeADC10();

	for (;;) {

		if (LeftSensorReading() < 0x250) {					//above threshold it should light
			P1OUT &= ~BIT0;
		} else {
			P1OUT |= BIT0;                        // Set P1.0 LED on
		}

		if (RightSensorReading() < 0x250) {
			P1OUT &= ~BIT6;
		} else {
			P1OUT |= BIT6;                        // Set P1.6 LED on
		}
	}

	return 0;
}
