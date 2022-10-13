/*
 * servo.c
 *
 *  Created on: Oct 4, 2022
 *      Author: alan1
 */

#include "servo.h"
#include <stdint.h>

// Attaches servo to certain pin
void servoInit(uint8_t finger, uint8_t pin){
	return;
}

// Sets position of the servo
// Takes in degrees
void servoSetPos(uint8_t finger, uint8_t deg){
    // 4000 offset because control ranges from 1ms-2ms duty cycle
	// 0.045 is determined by 180 deg / 4000 cnts per millisecond
	// 2 is because 180 deg is mapped across 2 ms, not 1
	// servo seems to be mapped from 2000-10000 => 0-180 deg
	// This is NOT what the spec said
	TIM2->CCR1 = (uint16_t)(2.0*(deg / 0.045) + 2000);
}

// Sets a start/zero position of the servo
// Does not move the servo
void servoSetStart(uint8_t finger, uint8_t deg){
	return;
}


// Moves servo to previously set start position
void servoReset(uint8_t finger){
	return;
}
