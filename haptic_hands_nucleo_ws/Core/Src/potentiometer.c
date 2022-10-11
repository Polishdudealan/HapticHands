/*
 * potentiometer.c
 *
 *  Created on: Sep 30, 2022
 *      Author: atondryk
 */
#include "main.h"
#include "potentiometer.h"
#include <stdint.h>

extern ADC_HandleTypeDef hadc1;
extern uint16_t adc_buffer;

uint16_t buf;

uint16_t potRead(uint8_t finger){
	return buf;
}

// Callback for when conversion finishes
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc1){
	buf = adc_buffer;

	// This leads to hard fault... why
	//HAL_ADC_Start_DMA(&hadc1, &adc_buffer, 1);
}
