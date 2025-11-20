/*
 * command_parser_fsm.c
 *
 *  Created on: Nov 21, 2025
 *      Author: ngoqu
 */


#include "command_parser_fsm.h"
#include <string.h>

uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t buffer_flag = 0;
uint8_t index_buffer = 0;

uint8_t command_flag = 0;
uint8_t command_data[10];


void command_parser_init() {
    index_buffer = 0;
    buffer_flag = 0;
    command_flag = 0;
}

/*
   FSM dạng MATCHING PATTERN:
   Nhận chuỗi !RST#  → command_flag = 1
   Nhận chuỗi !OK#   → command_flag = 2
*/
void command_parser_run() {

    if(buffer_flag == 0) return;

    buffer_flag = 0;

    buffer[index_buffer] = '\0';   // Ensure null termination

    if (strstr((char*)buffer, "!RST#") != NULL) {
        command_flag = 1;
    }
    else if (strstr((char*)buffer, "!OK#") != NULL) {
        command_flag = 2;
    }

    /* Reset buffer to avoid matching again */
    index_buffer = 0;
}
