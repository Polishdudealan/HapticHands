/*
 * comms.c
 *
 *  Created on: Oct 7, 2022
 *      Author: alan1
 */
#include "comms.h"

extern UART_HandleTypeDef huart6;
//extern FingerState finger_state;

// UART buffer. Data will be received via interrupts
uint8_t received_data[UART_BUFFER_SIZE] = {0};
uint8_t rx_buffer[UART_BUFFER_SIZE];

// uint8 to uint16 helper function
uint16_t uint8_to_uint16(uint8_t msb, uint8_t lsb){
	uint16_t val = (msb << 8) | lsb;
	return val;
}

// Clears finger state
void clearFingerState(){
	finger_state.valid = 0;

	 finger_state.angle0 = 0;
	 finger_state.coll0 = 0;

	 finger_state.angle1 = 0;
	 finger_state.coll1 = 0;

	 finger_state.angle2 = 0;
	 finger_state.coll2 = 0;

	 finger_state.angle3 = 0;
	 finger_state.coll3 = 0;

	 finger_state.angle4 = 0;
	 finger_state.coll4 = 0;
}

// Processes received data
void updateFingerState(){

	char SOP = received_data[0];
	uint8_t tag = received_data[1];

	 if(SOP == '$'){

		 switch(tag){
			 case POTENTIOMETER:
				 finger_state.valid = 1;

				 finger_state.angle0 = uint8_to_uint16(received_data[2], received_data[3]);
				 finger_state.coll0 = received_data[4];

				 finger_state.angle1 = uint8_to_uint16(received_data[5], received_data[6]);
				 finger_state.coll1 = received_data[7];

				 finger_state.angle2 = uint8_to_uint16(received_data[8], received_data[9]);
				 finger_state.coll2 = received_data[10];

				 finger_state.angle3 = uint8_to_uint16(received_data[11], received_data[12]);
				 finger_state.coll3 = received_data[13];

				 finger_state.angle4 = uint8_to_uint16(received_data[14], received_data[15]);
				 finger_state.coll4 = received_data[16];
				 break;

			 default:
				 break;
		 }

	 }
	 else{
		 finger_state.valid = 0;
	 }

}

// UART callback. Moves data from uart buffer into received_data buffer
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
//	memcpy(received_data, rx_buffer, UART_BUFFER_SIZE);
//	HAL_UART_Receive_IT(&huart6, rx_buffer, UART_BUFFER_SIZE);
	updateFingerState();
	HAL_UART_Receive_DMA(&huart6, received_data, UART_BUFFER_SIZE);
}


void UART_INIT(){
	// Start listening for uart data
	HAL_UART_Receive_DMA (&huart6, received_data, UART_BUFFER_SIZE);
//	HAL_UART_Receive_IT(&huart6, rx_buffer, UART_BUFFER_SIZE);
}

// Sets command in format
// Sends ‘$,1,a1,a2,b1,b2,c1,c2,d1,d2,e1,e2’
// Each a1, a2 represents 2 bytes = potentiometer value in degrees
// Used for sending finger angle data to unity
// Current BAUD rate: 115200

void sendCommand(uint8_t cmd_type, uint16_t f1, uint16_t f2, uint16_t f3, uint16_t f4, uint16_t f5){
#ifdef DEBUG
	//HAL_Delay(1000);
#endif
	uint8_t cmd[12] = {'$', cmd_type,
						(f1 >> 8) & 0x0F, f1 & 0xFF,
						(f2 >> 8) & 0x0F, f2 & 0xFF,
						(f3 >> 8) & 0x0F, f3 & 0xFF,
						(f4 >> 8) & 0x0F, f4 & 0xFF,
						(f5 >> 8) & 0x0F, f5 & 0xFF};

	//Modified: cmd should be passed, not &cmd
	HAL_UART_Transmit(&huart6, cmd, sizeof(cmd), 200);

	return;
}
