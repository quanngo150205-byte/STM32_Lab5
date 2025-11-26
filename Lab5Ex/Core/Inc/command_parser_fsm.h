/*
 * command_parser.h
 *
 *  Created on: Nov 26, 2025
 *      Author: ngoqu
 */

#ifndef INC_COMMAND_PARSER_FSM_H_
#define INC_COMMAND_PARSER_FSM_H_

#include <stdint.h>

#define MAX_BUFFER_SIZE 30


extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t buffer_flag;
extern uint8_t index_buffer;

extern uint8_t command_flag;

void command_parser_init();
void command_parser_run();

#endif /* INC_COMMAND_PARSER_FSM_H_ */
