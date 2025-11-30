/*
 * uart_communication.c
 *
 *  Created on: Nov 30, 2025
 *      Author: ngoqu
 */

#include "uart_communication.h"

void get_adc_value();
void UART_Send(const char *msg);

extern UART_HandleTypeDef huart2;

UARTState uart_state = UART_IDLE;
int auto_send_enabled = 0;
uint32_t last_send_tick = 0;
uint16_t adc_value;

void UART_Comm_Init(void){
    uart_state = UART_IDLE;
    auto_send_enabled = 0;
    last_send_tick = 0;
}

void UART_Send(const char *msg){
    HAL_UART_Transmit(&huart2,(uint8_t*)msg,strlen(msg),100);
}

void get_adc_value(){
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, 10);
	adc_value = HAL_ADC_GetValue(&hadc1);
}

void UART_Comm_Run(uint32_t tick){
    switch(uart_state){
        case UART_IDLE:
            if(cmd_rst_flag){
                auto_send_enabled = 1;
                last_send_tick = tick;
                cmd_rst_flag = 0;
            	get_adc_value();
                char msg[32];
                sprintf(msg,"!ADC=%04d#",adc_value);
                UART_Send(msg);
                uart_state = UART_RESEND_WAIT;
            }
            break;
        case UART_RESEND_WAIT:
            if(auto_send_enabled && tick - last_send_tick >= 3000){
            	get_adc_value();
                char msg[32];
                sprintf(msg,"!ADC=%04d#",adc_value);
                UART_Send(msg);
                last_send_tick = tick;
            }
            if(cmd_ok_flag){
                auto_send_enabled = 0;
                cmd_ok_flag = 0;
                uart_state = UART_IDLE;
            }
            break;
    }
}

