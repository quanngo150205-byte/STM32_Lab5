/*
 * command_parser.c
 *
 *  Created on: Nov 30, 2025
 *      Author: ngoqu
 */

#include "command_parser.h"

void  CommandParser_Execute();

CommandParserState cp_state = CP_IDLE;
volatile int cmd_rst_flag = 0;
volatile int cmd_ok_flag = 0;
static uint8_t cmd_buffer[16];
static uint8_t cmd_index = 0;

void CommandParser_Init(void){
    cp_state = CP_IDLE;
    cmd_rst_flag = 0;
    cmd_ok_flag = 0;
}

void  CommandParser_Execute(){
	if (strcmp((char*)cmd_buffer, "RST") == 0){
		cmd_rst_flag = 1; // Xử lý lệnh RST
	}
	else if (strcmp((char*)cmd_buffer, "OK") == 0){
		cmd_ok_flag = 1; // Xử lý lệnh OK
	}
	else{
	    return;// Unknown command
	}
}

void CommandParser_Run(char byte){
    switch(cp_state){
        case CP_IDLE:
            if(byte == '!'){
            	 cmd_index = 0;
            	 cp_state = CP_RECEIVING;
            }
            break;
        case CP_RECEIVING:
        	if (byte == '#'){
        	    cmd_buffer[cmd_index] = '\0';
        	    cp_state = CP_IDLE;
        	    CommandParser_Execute();
        	}
        	else if (cmd_index < sizeof(cmd_buffer) - 1)
        	{
        		cmd_buffer[cmd_index++] = byte;
        	}
            break;
    }
}

