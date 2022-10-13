/*
 * potentiometer.c
 *
 *  Created on: Sep 30, 2022
 *      Author: atondryk
 */
#include "potentiometer.h"
#include <string.h>

uint32_t buf[10];
uint32_t adc_buffer[10];

uint16_t potRead(uint8_t finger){
	return buf[0];
}

// Callback for when conversion finishes
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc1){
	memcpy((void*)buf, (void*)adc_buffer, 10*sizeof(uint32_t));
}
