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

#define ARRAY_SIZE 5

typedef struct
{
	uint16_t data[ARRAY_SIZE];
	uint16_t hist_data[ARRAY_SIZE];
} median;

void updateMedianArray(uint8_t finger, uint16_t val);

uint16_t getMedian(uint8_t finger);

#endif /* INC_MEDIAN_H_ */
