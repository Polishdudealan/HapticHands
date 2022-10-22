/*
 * potentiometer.c
 *
 *  Created on: Sep 30, 2022
 *      Author: atondryk
 */
#include "potentiometer.h"
#include <string.h>

// Should contain only up to 5 values. One for each ADC channel.
// TODO double check all channels are being initialized properly
uint16_t buf[5];
uint16_t adc_buffer[5];

uint16_t potRead(uint8_t finger){
	return buf[finger];
}

// Callback for when conversion finishes
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc1){
	memcpy((void*)buf, (void*)adc_buffer, 10*sizeof(uint32_t));
}
