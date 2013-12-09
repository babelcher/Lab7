#include <msp430.h> 
#include "robot_sensors.h"

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	
    InitializeLEDPins();
	return 0;
}
