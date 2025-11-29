#include "command_parser.h"

void command_parser(void) {
	uint8_t index = 0;
	if (idx_buffer == 0) {
		index = MAX_BUFFER_SIZE - 1;
	}
	else {
		index = idx_buffer - 1;
	}
	switch (status_com) {
		case COM_IDLE:
			if (command_flag == 1) {
				status_com = COM_RST1;
				command_flag = 0;
			}
			break;
		case COM_RST1:
			if (buffer_chr[index] == '!') {
				HAL_UART_Transmit(&huart2, (uint8_t*)&buffer_chr[index], 1, 1000);
				status_com = COM_RST2;
			}
			else if (buffer_chr[index] == 'O'){
				status_com = COM_OK2;
			}
			else {
				status_com = COM_IDLE;
			}
			break;
		case COM_RST2:
			if (buffer_chr[index] == 'R') {
				HAL_UART_Transmit(&huart2, (uint8_t *)&buffer_chr[index], 1, 1000);
				status_com = COM_RST3;
			}
			else {
				status_com = COM_IDLE;
			}
			break;
		case COM_RST3:
			if (buffer_chr[index] == 'S') {
				HAL_UART_Transmit(&huart2, (uint8_t*)&buffer_chr[index], 1, 1000);
				status_com = COM_RST4;
			}
			else {
				status_com = COM_IDLE;
			}
			break;
		case COM_RST4:
			if (buffer_chr[index] == 'T') {
				HAL_UART_Transmit(&huart2, (uint8_t*)&buffer_chr[index], 1, 1000);
				status_com = COM_RST5;
			}
			else {
				status_com = COM_IDLE;
			}
			break;
		case COM_RST5:
			if (buffer_chr[index] == '#') {
				HAL_UART_Transmit(&huart2, (uint8_t*)&buffer_chr[index], 1, 1000);
				status_com = COM_WAIT;

				adc_flag = 1;
				start_flag = 1;
			}
			else {
				status_com = COM_IDLE;
			}
			break;
		case COM_WAIT:
			if (buffer_chr[index] == '!' ) {
				HAL_UART_Transmit(&huart2, (uint8_t *)&buffer_chr[index], 1, 1000);
				status_com = COM_OK1;
			}
			break;
		case COM_OK1:
			if (buffer_chr[index] == 'O') {
				HAL_UART_Transmit(&huart2, (uint8_t*)&buffer_chr[index], 1, 1000);
				status_com = COM_OK2;
			}
			else {
				status_com = COM_WAIT;
			}
			break;
		case COM_OK2:
			if (buffer_chr[index] == 'K') {
				HAL_UART_Transmit(&huart2, (uint8_t*)&buffer_chr[index], 1, 1000);
				status_com = COM_OK3;
			}
			else {
				status_com = COM_WAIT;
			}
			break;
		case COM_OK3:
			if (buffer_chr[index] == '#') {
				HAL_UART_Transmit(&huart2, (uint8_t*)&buffer_chr[index], 1, 1000);
				status_com = COM_IDLE;
				start_flag = 0;
			}
			else {
				status_com = COM_WAIT;
			}
			break;
		default:
			status_com = COM_IDLE;
			break;
	}
//	if (strstr(buffer_chr, "!RST#") != NULL) {
//	        //HAL_UART_Transmit(&huart2, (uint8_t*)" !RST#\r\n", 9, 1000);
//	        status_com = COM_WAIT;
//	        memset(buffer_chr, 0, MAX_BUFFER_SIZE);
//	        idx_buffer = 0;
//	    }
//
//	    // Kiểm tra lệnh dừng (nếu có yêu cầu)
//	    else if (strstr(buffer_chr, "!OK#") != NULL) {
//	        //HAL_UART_Transmit(&huart2, (uint8_t*)" !OK#\r\n", 8, 1000);
//	        status_com = COM_IDLE;
//	        memset(buffer_chr, 0, MAX_BUFFER_SIZE);
//	        idx_buffer = 0;
//	    }
}
