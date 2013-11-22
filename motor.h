/*
 * motor.h
 *
 *  Created on: Nov 19, 2013
 *      Author: C15Stefan.BaronvonVi
 */

#include <msp430.h>

#ifndef MOTOR_H_
#define MOTOR_H_


void MoveRightMotorForward();

void MoveLeftMotorForward();

void MoveRightMotorBackward();

void MoveLeftMotorBackward();

void MoveLeft();

void MoveRight();

void InitPinsOut();

void MoveForward();

void MoveBackward();

void ConfigTimer();

void MoveTimer();

void StopTimer();



#endif /* MOTOR_H_ */

