/*
 *  printf2uart.c
 *
 *  To use the UART/USART as the output of prinf()
 *
 *  Usage:
 *  1. Include the header file "printf2uart.h" in the main program ("main.c").
 *  2. The UART should already be initialised in the main program.
 *
 *  Created on: 19 April 2017
 *      Author: Ori Novanda
 *       Email: cargmax-at-gmail.com
 *
 */

#include "printf2uart.h"
#include "stm32f0xx.h"

#warning "TARGET_USART must already be initialised."

int _write(int file, char *data, int len) {
	for(uint32_t i=0; i<len; i++) {
		char ch = data[i];
		while ((TARGET_USART->ISR & TX_EMPTY_FLAG) == RESET);
		TARGET_USART->TDR = ch;
	}
	return len;
}
