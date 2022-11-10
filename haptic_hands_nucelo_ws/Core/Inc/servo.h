/*
 * servo.h
 *
 *  Created on: Sep 29, 2022
 *      Author: atondryk
 */
#include "main.h"

#ifndef INC_SERVO_H_
#define INC_SERVO_H_

// Initialize timers for all servos
void servoInit();

// Sets position of the servo
// Takes in degrees 0-180
void servoSetPos(uint8_t finger, uint8_t deg);

// Sets position of the servo
// Takes in degrees 0-4096
void servoSetPosRaw(uint8_t finger, uint16_t deg);

#endif /* INC_SERVO_H_ */
