/*
 * motor.c
 *
 *  Created on: Nov 19, 2013
 *      Author: C15Stefan.BaronvonVi
 */

#include <msp430.h>
#include "motor.h"

void InitPinsOut() {

        P1DIR |= BIT1;        //P1.1
        P1SEL |= BIT1;
        P1DIR |= BIT2;        //P1.2
        P1SEL |= BIT2;

        P2DIR |= BIT0;        //P2.0
        P2SEL |= BIT0;
        P2DIR |= BIT1;        //P2.1
        P2SEL |= BIT1;
}

//void MoveTimer() {

//        TACTL &= ~MC1 | MC0;            // stop timer A0

//        TACTL |= TACLR;                // clear timer A0

//        TACTL |= TASSEL1;           // configure for SMCLK

//        TACCR0 = 100;   // set signal period to 100 clock cycles (~100 microseconds)
//        TACCR1 = 10;                // set duty cycle to 30/100 (30%)

//        TACCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode

//        TACTL |= MC0;                // count up

//}

//void StopTimer() {

//        TACTL &= ~MC1 | MC0;            // stop timer A0

//        TACTL |= TACLR;                // clear timer A0

//        TACTL |= TASSEL1;           // configure for SMCLK

//        TACCR0 = 100;   // set signal period to 100 clock cycles (~100 microseconds)
//        TACCR1 = 0;                // set duty cycle to 0/100 (0%)

//        TACCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode

//        TACTL |= MC0;                // count up

//}

void ConfigTimer(){

    TA0CTL &= ~MC1|MC0;
    TA1CTL &= ~MC1|MC0;
    TA0CTL |= TACLR;
    TA1CTL |= TACLR;
    TA0CTL |= TASSEL1;
    TA1CTL |= TASSEL1;

    TA1CCR0 = 100; //
    TA0CCR0 = 100; //
    TA0CCR1 = 0;  //
    TA1CCR1 = 0;  //

    TA0CCTL1 |= OUTMOD_7;
    TA0CCTL0 |= OUTMOD_5;
    TA1CCTL1 |= OUTMOD_7;
    TA1CCTL0 |= OUTMOD_5;
    TA0CTL |= MC0;
    TA1CTL |= MC0;

   }

void MoveRightMotorForward() {

//        P2DIR |= BIT1;        //P2.1
//        P2SEL |= BIT1;
//        MoveTimer();
//        TA1CCTL0 = OUTMOD_5;
        TA1CCTL0 = OUTMOD_5;
        _delay_cycles(10000);
        TA1CCR1 = 60;
//        TA1CCR0 = 0;
}

void MoveRightMotorBackward() {

//        P2DIR |= BIT0;        //P2.0
//        P2SEL |= BIT0;
//        MoveTimer();
//        TA1CCTL0 = OUTMOD_4;

        TA1CCR1 = 0;
        _delay_cycles(10000);
        TA1CCTL0 = OUTMOD_4;
//        TA1CCR0 = 30;
}

void MoveLeftMotorForward() {

//        P1DIR |= BIT2;        //P1.2
//        P1SEL |= BIT2;
//        MoveTimer();
//        TA0CCTL0 = OUTMOD_5;

        TA0CCTL0 = OUTMOD_5;
        _delay_cycles(10000);
        TA0CCR1 = 60;
//        TA0CCR0 = 0;
}

void MoveLeftMotorBackward() {

//        P1DIR |= BIT1;        //P1.1
//        P1SEL |= BIT1;
//        MoveTimer();
//        TA0CCTL0 = OUTMOD_4;

        TA0CCR1 = 0;
        _delay_cycles(10000);
        TA0CCTL0 = OUTMOD_4;
//        TA0CCR0 = 30;
}

void MoveRight() {

        MoveLeftMotorForward();
        MoveRightMotorBackward();
}

void MoveLeft() {

        MoveLeftMotorBackward();
        MoveRightMotorForward();
}

void MoveForward() {

        MoveRightMotorForward();
        MoveLeftMotorForward();
}

void MoveBackward() {

        MoveRightMotorBackward();
        MoveLeftMotorBackward();
}

