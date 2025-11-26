/*
 * command_parser.c
 *
 *  Created on: Nov 26, 2025
 *      Author: ngoqu
 */

#include "command_parser_fsm.h"
#include <string.h>

/* Biến toàn cục được định nghĩa **một lần duy nhất** */
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t buffer_flag = 0;
uint8_t index_buffer = 0;

uint8_t command_flag = 0;

void command_parser_init() {
    memset(buffer, 0, MAX_BUFFER_SIZE);
    buffer_flag = 0;
    index_buffer = 0;
    command_flag = 0;
}

void command_parser_run() {
    if(buffer_flag == 0) return;

    buffer_flag = 0;
    buffer[index_buffer] = '\0';

    if (strstr((char*)buffer, "!RST#")) {
        command_flag = 1;
    }
    else if (strstr((char*)buffer, "!OK#")) {
        command_flag = 2;
    }

    index_buffer = 0;
}
