#ifndef __COMMAND_PARSER_FSM_H__
#define __COMMAND_PARSER_FSM_H__

#include <stdint.h>

#define MAX_BUFFER_SIZE 30


extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t buffer_flag;
extern uint8_t index_buffer;

extern uint8_t command_flag;

void command_parser_init();
void command_parser_run();

#endif
