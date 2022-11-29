/*
 * median.h
 *
 *  Created on: 2022年11月10日
 *      Author: 10RE
 */

#include <stdint.h>
#include "main.h"

#ifndef INC_MEDIAN_H_
#define INC_MEDIAN_H_

void update_median_array(uint8_t finger, uint16_t val);

uint16_t get_median(uint8_t finger);

#endif /* INC_MEDIAN_H_ */
