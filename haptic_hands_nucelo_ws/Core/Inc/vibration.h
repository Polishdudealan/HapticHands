/*
 * vibration.h
 *
 *  Created on: Sep 29, 2022
 *      Author: atondryk
 */
#include "main.h"

#ifndef INC_VIBRATION_H_
#define INC_VIBRATION_H_

uint16_t vibration_pin[5];
uint8_t vibration_state[5];

void checkVibration();

void vibrationOnForDuration(uint8_t finger, uint8_t time);

void resetVibration(uint8_t finger);

// Turns on vibration motor
void vibrationOn(uint8_t finger);

// Turns off vibration motor
void vibrationOff(uint8_t finger);


#endif /* INC_VIBRATION_H_ */
