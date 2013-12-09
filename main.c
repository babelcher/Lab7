#include <msp430.h> 
#include "robot_sensors.h"

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	
    P1DIR |= BIT0;
    P1DIR |= BIT6;

	return 0;
}
