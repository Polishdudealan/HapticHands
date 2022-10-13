/*
 * potentiometer.h
 *
 *  Created on: Sep 29, 2022
 *      Author: atondryk
 */
#include "main.h"

#ifndef INC_POTENTIOMETER_H_
#define INC_POTENTIOMETER_H_

extern uint32_t adc_buffer[10];

// Reads 12-bit ADC value from
// potentiometer into a 16 bit number
uint16_t potRead(uint8_t finger);

// Callback for when conversion finishes
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc1);

#endif /* INC_POTENTIOMETER_H_ */
