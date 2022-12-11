/*
 * vibration.h
 *
 *  Created on: Sep 29, 2022
 *      Author: atondryk
 */
#include "main.h"

#ifndef INC_VIBRATION_H_
#define INC_VIBRATION_H_

// Count down the state of the vibration motor, if it reaches end state, vibration motor is turned off
void checkVibration();

// Set the vibration state to certain value based on the time it needed to be turn on, vibration motor is turned on
void vibrationOnForDuration(uint8_t finger, uint8_t time);

// Reset the vibration state to stop counting down and vibration immediately
void resetVibration(uint8_t finger);

// Turns on vibration motor
void vibrationOn(uint8_t finger);

// Turns off vibration motor
void vibrationOff(uint8_t finger);


#endif /* INC_VIBRATION_H_ */
