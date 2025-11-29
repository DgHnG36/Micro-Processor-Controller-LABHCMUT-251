#include "uart_com_fsm.h"

char str[50];

void uart_communication_fsm(void) {
	switch (status_uart) {
		case UART_IDLE:
			if (start_flag == 1) {
				if (isTimerExpired(1)) {
					setTimer(1, 300);
					if (adc_flag == 1) {
						adc_flag = 0;
						ADC_val = HAL_ADC_GetValue(&hadc1);
						sprintf(saved_previous, "\r!ADC=%lu#\r\n", ADC_val);
					}
					HAL_UART_Transmit(&huart2, (void*)saved_previous, strlen(saved_previous), 1000);
				}
			}
			break;
		case UART_TRANS:
			command_flag = 1;
			status_uart = UART_IDLE;
			break;
		default:
			status_uart = UART_IDLE;
			break;
	}
//	switch (status_com)
//	    {
//	        case COM_IDLE:
//	            // không làm gì
//	            break;
//
//	        case COM_WAIT:                                      // vừa nhận xong !RST#
//	            if (timer_flag[1] == 1)                         // timer hết 3s
//	            {
//	                // LẦY ADC MỘT LẦN DUY NHẤT khi nhận !RST#
//	                if (strlen(saved_packet) == 0)              // lần đầu tiên
//	                {
//	                    ADC_val = HAL_ADC_GetValue(&hadc1);
//	                    sprintf(saved_packet, "\r!ADC=%lu#\r\n", ADC_val);
//	                }
//
//	                HAL_UART_Transmit(&huart2, (uint8_t*)saved_packet, strlen(saved_packet), 1000);
//	                setTimer(1, 300);                           // đếm lại 3s
//	            }
//	            break;
//
//	        default:
//	            break;
//	    }
}
