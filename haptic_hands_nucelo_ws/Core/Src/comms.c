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

// Processes received data
void updateFingerState(){

	char SOP = received_data[0];
	uint8_t tag = received_data[1];

	 if(SOP == '$'){
		 switch(tag){
			 case POTENTIOMETER:
				 finger_state.valid = 1;
				 for(int i = 0; i < 5; i++){
					 finger_state.angles[i] = uint8_to_uint16(received_data[3 * i + 2], received_data[3 * i + 3]);
					 finger_state.collisions[i] = received_data[3 * i + 4];
//					 finger_state.angles[i] = potRead(i);
				 }
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
	updateFingerState();
	HAL_UART_Receive_DMA(&huart6, received_data, UART_BUFFER_SIZE);
}

// Start listening for uart data
void UART_INIT(){
	HAL_UART_Receive_DMA (&huart6, received_data, UART_BUFFER_SIZE);
}

// Sets command in format
// Sends ‘$,1,a1,a2,b1,b2,c1,c2,d1,d2,e1,e2’
// Each a1, a2 represents 2 bytes = potentiometer value in raw 12bits values
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
