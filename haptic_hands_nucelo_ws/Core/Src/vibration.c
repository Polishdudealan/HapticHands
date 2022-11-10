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

uint8_t vibration_state[5] = {0, 0, 0, 0, 0};

void vibrationOnForDuration(uint8_t finger, uint8_t time) {
	if (vibration_state[i] == 0) {
		vibration_state[i] = time; // this value determines how long it will vibrates, vibrate_period = n * update_period
		vibrationOn(i);
	}
}

void resetVibration(uint8_t finger){
	vibrationOff(i);
	vibration_state[finger] = 0;
}

// Turns on vibration motor
void vibrationOn(uint8_t finger) {
	HAL_GPIO_WritePin(GPIOA, vibration_pin[finger], GPIO_PIN_SET);
}

// Turns off vibration motor
void vibrationOff(uint8_t finger) {
	HAL_GPIO_WritePin(GPIOA, vibration_pin[finger], GPIO_PIN_RESET);
}

void checkVibration(){
	  for (int i = 0; i < NUM_FINGERS; i++){
		  if (vibration_state[i] > 1){
			  vibration_state[i]--;
		  }
		  else if (vibration_state[i] == 1) {
			  vibrationOff(i);
		  }
	  }
  }
