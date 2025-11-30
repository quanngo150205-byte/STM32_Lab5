/*
 * command_parser.c
 *
 *  Created on: Nov 30, 2025
 *      Author: ngoqu
 */

#include "command_parser.h"

void cp_reset_buffer();
void cp_handle_command(char *cmd);

CommandParserState cp_state = CP_IDLE;
volatile int cmd_rst_flag = 0;
volatile int cmd_ok_flag = 0;

void CommandParser_Init(void){
    cp_state = CP_IDLE;
    cmd_rst_flag = 0;
    cmd_ok_flag = 0;
}

void cp_reset_buffer()
{
    uart_rx_index = 0;
    memset(uart_rx_buffer, 0, UART_BUFFER_SIZE);
}

void cp_handle_command(char *cmd){
	if (strcmp(cmd, "RST") == 0){
		cmd_rst_flag = 1; // Xử lý lệnh RST
		cp_reset_buffer();
	}
	else if (strcmp(cmd, "OK") == 0){
		cmd_ok_flag = 1; // Xử lý lệnh OK
		cp_reset_buffer();
	}
	else{
	    cp_reset_buffer();// Unknown command
	}
}

void CommandParser_Run(uint8_t byte){
    switch(cp_state){
        case CP_IDLE:
            if(byte == '!'){
            	cp_reset_buffer();
                cp_state = CP_RECEIVING;
            }
            break;
        case CP_RECEIVING:
            if(byte == '#'){
                uart_rx_buffer[uart_rx_index] = '\0';
                cp_handle_command(uart_rx_buffer);   // xử lý chuỗi ngay
                cp_state = CP_IDLE;
            }else {
                if (uart_rx_index < UART_BUFFER_SIZE - 1)
                    uart_rx_buffer[uart_rx_index++] = byte;
                else
                    cp_state = CP_IDLE; // overflow → reset state
                	cp_reset_buffer();
            }
            break;
    }
}

