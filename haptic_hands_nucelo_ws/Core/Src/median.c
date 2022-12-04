/*
 * median.c
 *
 *  Created on: 2022年11月10日
 *      Author: 10RE
 */
#include "median.h"
#include <stdint.h>

#define ARRAY_SIZE 5

typedef struct
{
	uint16_t data[ARRAY_SIZE];
	uint16_t hist_data[ARRAY_SIZE];
} median;

median median_array[5] = {
	{0},
	{0},
	{0},
	{0},
	{0}
};

void update_median_array(uint8_t finger, uint16_t val) {
//	for (int i = 0; i < (sizeof(median_array) / sizeof(uint16_t)) - 1; i ++) {
	uint16_t head = median_array[finger].hist_data[0];
	for (int i = 0; i < ARRAY_SIZE - 1; i ++) {
		median_array[finger].hist_data[i] = median_array[finger].hist_data[i + 1];
	}
	median_array[finger].hist_data[ARRAY_SIZE - 1] = val;
	int move_flag = 0; // 0 no move, 1 move left, 2 move right
	int hold_val = 0;
	int head_checked = 0;
	int val_checked = 0;
	for (int i = 0; i < ARRAY_SIZE - 1; i ++) {
		if (move_flag == 1) {
			median_array[finger].data[i] = median_array[finger].data[i + 1];
		}
		else if (move_flag == 2) {
			int tmp_hold = median_array[finger].data[i];
			median_array[finger].data[i] = hold_val;
			hold_val = tmp_hold;
			hold_val = median_array[finger].data[i];
		}
		if (head_checked == 0 && median_array[finger].data[i] == head) {
			head_checked = 1;
			if ( move_flag == 0) {
				median_array[finger].data[i] = median_array[finger].data[i + 1];
				move_flag = 1;
			}
			else {
				median_array[finger].data[i] = hold_val;
				move_flag = 0;
				return;
			}
		}
		if (val_checked == 0 && val < median_array[finger].data[i]) {
			val_checked = 1;
			if ( move_flag == 0) {
				hold_val = median_array[finger].data[i];
				median_array[finger].data[i] = val;
				move_flag = 2;
			}
			else {
				median_array[finger].data[i] = val;
				move_flag = 0;
				return;
			}
		}
	}
	median_array[finger].data[ARRAY_SIZE - 1] = val;
  }

uint16_t get_median(uint8_t finger) {
	/* be careful when initializing, the array doesn't have the array filled. */
//	return median_array[(int)(sizeof(median_array) / sizeof(uint16_t)) / 2];
	return median_array[finger].data[(int)(ARRAY_SIZE / 2)];
}
