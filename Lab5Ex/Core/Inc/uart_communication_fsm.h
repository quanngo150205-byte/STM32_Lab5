/*
 * uart_communication_fsm.h
 *
 *  Created on: Nov 21, 2025
 *      Author: ngoqu
 */

#ifndef __UART_COMMUNICATION_FSM_H__
#define __UART_COMMUNICATION_FSM_H__

#include "stm32f1xx_hal.h"
#include "command_parser_fsm.h"

extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;

void uart_communication_init();
void uart_communication_run();

#endif

