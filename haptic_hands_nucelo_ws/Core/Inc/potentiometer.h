/*
 * potentiometer.h
 *
 *  Created on: Sep 29, 2022
 *      Author: atondryk
 */
#include "main.h"

#ifndef INC_POTENTIOMETER_H_
#define INC_POTENTIOMETER_H_

typedef uint32_t ADC_BUF_TYPE; //change to uint16_t if needed and tested

extern ADC_BUF_TYPE adc_buffer[NUM_FINGERS];

// Reads 12-bit ADC value from
// potentiometer into a 16 bit number
uint16_t potRead(uint8_t finger);

// Callback for when conversion finishes
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc1);

#endif /* INC_POTENTIOMETER_H_ */
