#include "global.h"

char buffer_chr[MAX_BUFFER_SIZE];
uint8_t idx_buffer = 0;
uint8_t buffer_flag = 0;
uint8_t command_flag = 0;
uint8_t adc_flag = 0;
uint8_t start_flag = 0;
uint32_t ADC_val = 0;

char saved_previous[50] = "";
uint8_t status_uart = 0;
uint8_t status_com = 0;
