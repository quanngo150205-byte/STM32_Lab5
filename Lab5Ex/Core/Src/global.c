/*
 * global.c
 *
 *  Created on: Nov 30, 2025
 *      Author: ngoqu
 */

#include "global.h"

uint8_t uart_rx_temp;
uint8_t uart_rx_buffer[UART_BUFFER_SIZE];
uint16_t uart_rx_index = 0;
volatile int uart_rx_flag = 0;

