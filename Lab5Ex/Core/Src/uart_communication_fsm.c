/*
 * uart_communication.c
 *
 *  Created on: Nov 26, 2025
 *      Author: ngoqu
 */

#include "uart_communication_fsm.h"
#include <stdio.h>
#include <string.h>

static uint32_t last_tick = 0;
static char tx_buffer[50];
static uint32_t ADC_value = 0;

enum {
    UART_IDLE,
    UART_SEND_ADC,
    UART_WAIT_OK
};

static uint8_t uart_state = UART_IDLE;

/* Timeout = 3000 ms */
#define UART_TIMEOUT 3000

void uart_communication_init() {
    uart_state = UART_IDLE;
}

void uart_communication_run() {

    switch(uart_state) {

    case UART_IDLE:
        if(command_flag == 1) {          // !RST#
            command_flag = 0;

            ADC_value = HAL_ADC_GetValue(&hadc1);
            sprintf(tx_buffer, "!ADC=%lu#\r\n", ADC_value);

            HAL_UART_Transmit(&huart2,
                              (uint8_t*)tx_buffer,
                              strlen(tx_buffer),
                              1000);

            last_tick = HAL_GetTick();
            uart_state = UART_WAIT_OK;
        }
        break;

    case UART_WAIT_OK:
        if(command_flag == 2) {          // !OK#
            command_flag = 0;
            uart_state = UART_IDLE;
        }

        if(HAL_GetTick() - last_tick > UART_TIMEOUT) {
            HAL_UART_Transmit(&huart2,
                              (uint8_t*)tx_buffer,
                              strlen(tx_buffer),
                              1000);
            last_tick = HAL_GetTick();
        }
        break;
    }
}
