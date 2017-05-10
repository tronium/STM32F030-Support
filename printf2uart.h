/*
 *  printf2uart.h
 *
 *  First created on: 19 April 2017
 *            Author: Ori Novanda
 *             Email: cargmax-at-gmail.com
 *
 */

#ifndef PRINTF2UART_H_
#define PRINTF2UART_H_

#include "stm32f0xx.h"
#include "supportconf.h"

#define TARGET_USART USART1
#ifdef __STM32F0xx_HAL_UART_H
	#define TX_EMPTY_FLAG UART_FLAG_TXE
#else
	#define TX_EMPTY_FLAG USART_FLAG_TXE
#endif

#ifdef __cplusplus
 extern "C" {
#endif

#if TOOLCHAIN_TARGET == TOOLCHAIN_TARGET_MDK_ARM
int fputc(int c, FILE *f);
#else
int _write(int file, char *data, int len);
#endif

#ifdef __cplusplus
}
#endif

#endif /* PRINTF2UART_H_ */
