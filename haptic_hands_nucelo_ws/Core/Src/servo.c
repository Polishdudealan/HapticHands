/*
 * servo.c
 *
 *  Created on: Oct 4, 2022
 *      Author: alan1
 */

#include "comms.h"
#include "servo.h"
#include <stdint.h>


// Attaches servo to certain pin
void servoInit(uint8_t finger, uint8_t pin){
	return;
}

// Sets position of the servo
// Takes in degrees
void servoSetPos(uint8_t finger, uint8_t deg){
	// Modification to flip servo direction
//	deg = 180 - deg;
    // 4000 offset because control ranges from 1ms-2ms duty cycle
	// 0.045 is determined by 180 deg / 8000 cnts per millisecond
	// 2 is because 180 deg is mapped across 2 ms, not 1
	// servo seems to be mapped from 2000-10000 => 0-180 deg
	// This is NOT what the spec said
//	TIM2->CCR1 = (uint16_t)(2.0*(deg / 0.045) + 2000);

	// Try this for multi-finger
	uint16_t val = (deg * (8000.0 / 180.0) * 2.0) - 2000.0;
	switch(finger){
		case 0:
			TIM2->CCR2 = val;
			break;
		case 1:
			TIM2->CCR1 = val;
			break;
		case 2:
			TIM2->CCR3 = val;
			break;
		case 3:
			TIM5->CCR1 = val;
			break;
		case 4:
			TIM5->CCR2 = val;
			break;
		default:
			break;
	}
}

// Checks if a collision has occurred on any of the fingers
void servoCheckCollisions(){
	float deg_conv = 180.0 / 4096.0;
//	float deg_conv = 360.0 / 4095.0;
	// TODO uncomment this for 5 fingers

	for(int i = 0; i < 5; i++){
		if(finger_state.collisions[i] == '1'){
			servoSetPos(i, finger_state.angles[i] * deg_conv);
//			if((finger_state.angles[i] - pot_reading > 200)){
//				 clearFingerState();
//			}
		}
		else{
			clearCollision(i);
			uint16_t p = potRead(i);
			servoSetPos(i, p * deg_conv + 50);
		}
	}
	// For index finger only
//	if(finger_state.collisions[1] == '1'){
//			servoSetPos(0, finger_state.angles[1] * deg_conv);
//	}


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
