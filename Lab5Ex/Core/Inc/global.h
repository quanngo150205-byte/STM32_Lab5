/*
 * global.h
 *
 *  Created on: Nov 30, 2025
 *      Author: ngoqu
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define UART_BUFFER_SIZE		30

#include "stm32f1xx_hal.h"
#include <stdint.h>

extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;

// UART buffer
extern uint8_t uart_rx_temp; // Byte nhận tạm thời
extern uint8_t uart_rx_buffer[UART_BUFFER_SIZE]; // Buffer UART
extern uint16_t uart_rx_index; // Index ghi tiếp theo
extern volatile int uart_rx_flag; // Cờ báo dữ liệu mới


// Parser module
typedef enum { CP_IDLE, CP_RECEIVING } CommandParserState;
extern CommandParserState cp_state;
extern volatile int cmd_rst_flag;
extern volatile int cmd_ok_flag;

// UART module state
typedef enum { UART_IDLE, UART_RESEND_WAIT } UARTState;
extern UARTState uart_state;
extern int auto_send_enabled;
extern uint32_t last_send_tick;



// ADC value
extern uint16_t adc_value;

#endif /* INC_GLOBAL_H_ */
