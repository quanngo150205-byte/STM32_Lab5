/*
 * uart_communication.h
 *
 *  Created on: Nov 30, 2025
 *      Author: ngoqu
 */

#ifndef INC_UART_COMMUNICATION_H_
#define INC_UART_COMMUNICATION_H_

#include "global.h"
#include <string.h>
#include <stdio.h>

void UART_Comm_Init(void);
void UART_Comm_Run(uint32_t tick);  // State machine gửi ADC

#endif /* INC_UART_COMMUNICATION_H_ */
