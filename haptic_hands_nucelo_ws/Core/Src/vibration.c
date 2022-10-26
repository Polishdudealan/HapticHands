/*
 * vibration.c
 *
 *  Created on: Oct 25, 2022
 *      Author: 10RE
 */
#include "vibration.h"

uint16_t vibration_pin[5] = {
		GPIO_PIN_12,
		GPIO_PIN_11,
		GPIO_PIN_10,
		GPIO_PIN_9,
		GPIO_PIN_8
};

// Turns on vibration motor
void vibrationOn(uint8_t finger) {
	HAL_GPIO_WritePin(GPIOA, vibration_pin[finger], GPIO_PIN_SET);
	//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);
}

// Turns off vibration motor
void vibrationOff(uint8_t finger) {
	HAL_GPIO_WritePin(GPIOA, vibration_pin[finger], GPIO_PIN_RESET);
}

