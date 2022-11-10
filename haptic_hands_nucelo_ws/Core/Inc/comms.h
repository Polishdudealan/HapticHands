/*
 * comms.h
 *
 *  Created on: Sep 29, 2022
 *      Author: atondryk
 */
#include "main.h"

#define UART_BUFFER_SIZE 17

#ifndef INC_COMMS_H_
#define INC_COMMS_H_
// comms will be over UART

// finger states
typedef struct {
	uint8_t valid;
	uint16_t angles[5];
	uint8_t collisions[5];
} FingerState;

extern FingerState finger_state;

// Enum for tags
extern enum CMD_TYPES{
	  CALIBRATEZERO = 'Z',
	  POTENTIOMETER = '1',
	  CALIBRATEMAX  = 'M'
}CMD_TYPE;

// uint8 to uint16 helper function
uint16_t uint8_to_uint16(uint8_t msb, uint8_t lsb);

// UART callback. Moves data from uart buffer into received_data buffer
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

// Sets command in format
// Sends ‘$,1,a1,a2,b1,b2,c1,c2,d1,d2,e1,e2’
// Each a1, a2 represents 2 bytes = potentiometer value in degrees
// Used for sending finger angle data to unity
void sendCommand(uint8_t cmd_type, uint16_t f1, uint16_t f2, uint16_t f3, uint16_t f4, uint16_t f5);

void updateFingerState();

void UART_INIT();

#endif /* INC_COMMS_H_ */
