/*
 * potentiometer.h
 *
 *  Created on: Sep 29, 2022
 *      Author: atondryk
 */
#include <stdint.h>

#ifndef INC_POTENTIOMETER_H_
#define INC_POTENTIOMETER_H_

// Reads 12-bit ADC value from
// potentiometer into a 16 bit number
uint16_t potRead(uint8_t finger);

#endif /* INC_POTENTIOMETER_H_ */
