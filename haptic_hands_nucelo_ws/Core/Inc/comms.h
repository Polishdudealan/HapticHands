/*
 * comms.h
 *
 *  Created on: Sep 29, 2022
 *      Author: atondryk
 */
#include <stdint.h>

#define UART_BUFFER_SIZE 20

#ifndef INC_COMMS_H_
#define INC_COMMS_H_
// comms will be over UART

// message structure sent to unity
struct PotMsg{
	uint16_t angle[5];
};

// message structures received from unity
struct VibrationMsg{
	uint8_t finger[5];
};

// UART buffer. Data will be received via interrupts
uint8_t received_data[UART_BUFFER_SIZE];

// UART callback. Moves data from uart buffer into received_data buffer
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

// Sets command in format
// '$,DATA,CHECKSUM'
// Used for sending finger angle data to unity
void sendCommand(uint8_t* cmd);

#endif /* INC_COMMS_H_ */
