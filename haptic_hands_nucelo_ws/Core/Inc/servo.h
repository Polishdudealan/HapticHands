/*
 * servo.h
 *
 *  Created on: Sep 29, 2022
 *      Author: atondryk
 */
#include <stdint.h>

#ifndef INC_SERVO_H_
#define INC_SERVO_H_

// Attaches servo to certain pin
void servoInit(uint8_t finger, uint8_t pin);

// Sets position of the servo
// Takes in degrees
void servoSetPos(uint8_t finger, uint8_t deg);

// Sets a start/zero position of the servo
// Does not move the servo
void servoSetStart(uint8_t finger, uint8_t deg);


// Moves servo to previously set start position
void servoReset(uint8_t finger);

#endif /* INC_SERVO_H_ */
