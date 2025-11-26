/*
 * uart_communication.h
 *
 *  Created on: Nov 26, 2025
 *      Author: ngoqu
 */

#ifndef INC_UART_COMMUNICATION_FSM_H_
#define INC_UART_COMMUNICATION_FSM_H_

#include "stm32f1xx_hal.h"
#include "command_parser_fsm.h"

extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;

void uart_communication_init();
void uart_communication_run();

#endif /* INC_UART_COMMUNICATION_FSM_H_ */
