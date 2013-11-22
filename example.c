/*
 * main.c
 */

#include <msp430.h>
#include "motor.h"

int main(void) {
        WDTCTL = WDTPW | WDTHOLD;        // Stop watchdog timer

        InitPinsOut();
        ConfigTimer();


//        MoveTimer();
//        StopTimer();

        while (1) {

                MoveForward();
                _delay_cycles(1000000);
//                StopTimer();

                MoveBackward();
                _delay_cycles(1000000);

                MoveLeft();
                _delay_cycles(500000);                        // <45 degree turn

//                StopTimer();

                MoveRight();
                _delay_cycles(500000);                        // <45 degree turn

                MoveLeft();
                _delay_cycles(1000000);                        // >45 degree turn

                MoveRight();
                _delay_cycles(1000000);                        // >45 degree turn

        }

        return 0;
}

