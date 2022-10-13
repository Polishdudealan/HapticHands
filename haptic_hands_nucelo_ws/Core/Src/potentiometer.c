/*
 * potentiometer.c
 *
 *  Created on: Sep 30, 2022
 *      Author: atondryk
 */
#include "potentiometer.h"

uint32_t buf;
uint32_t adc_buffer[10];

uint16_t potRead(uint8_t finger){
	return buf;
}

// Callback for when conversion finishes
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc1){
	buf = 0x99;

	// This leads to hard fault... why
	HAL_ADC_Start_DMA(hadc1, adc_buffer, 1);
}
