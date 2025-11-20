/*
 * command_parser_fsm.h
 *
 *  Created on: Nov 21, 2025
 *      Author: ngoqu
 */

#ifndef __COMMAND_PARSER_FSM_H__
#define __COMMAND_PARSER_FSM_H__

#include "stm32f1xx_hal.h"
#include <stdint.h>

#define MAX_BUFFER_SIZE 30

extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;

/* Output of parser */
extern uint8_t command_flag;    // 1 = RST, 2 = OK
extern uint8_t command_data[10];

void command_parser_init();
void command_parser_run();

#endif
