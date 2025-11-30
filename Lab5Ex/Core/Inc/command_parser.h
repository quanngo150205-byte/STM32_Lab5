/*
 * command_parser.h
 *
 *  Created on: Nov 30, 2025
 *      Author: ngoqu
 */

#ifndef INC_COMMAND_PARSER_H_
#define INC_COMMAND_PARSER_H_

#include "global.h"
#include <string.h>

void CommandParser_Init(void);
void CommandParser_Run(char);  // State machine xử lý byte


#endif /* INC_COMMAND_PARSER_H_ */
