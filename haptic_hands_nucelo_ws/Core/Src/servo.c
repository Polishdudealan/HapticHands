/*
 * servo.c
 *
 *  Created on: Oct 4, 2022
 *      Author: alan1
 */

#include "comms.h"
#include "servo.h"
#include <stdint.h>

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim4;

// Attaches servo to certain pin
void servoInit(){
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
	return;
}

void servoSetVal(uint8_t finger, uint16_t val) {
	switch(finger){
		case 0:
			TIM2->CCR1 = val;
			break;
		case 1:
			TIM2->CCR2 = val;
			break;
		case 2:
			TIM2->CCR3 = val;
			break;
		case 3:
			TIM4->CCR1 = val;
			break;
		case 4:
			TIM4->CCR2 = val;
			break;
		default:
			break;
	}
}

// Sets position of the servo
// Takes in degrees
//
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
	uint16_t val = 1000 + (double) 2 * 4000.0 * deg / 180.0;
	servoSetVal(finger, val);
}

/*
 *
 * Write servo position with the raw 2byte value from
 * the potentiometer
 *
 */
void servoSetPosRaw(uint8_t finger, uint16_t deg){
	uint16_t val = 1000 + (double) 2 * 4000.0 * deg / 0x0FFF; //Maybe right shift by 12? reduce FP?
	servoSetVal(finger, val);
}
