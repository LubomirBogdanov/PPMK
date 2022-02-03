/*
 * uart.h
 *
 *  Created on: 26.09.2016
 *      Author: lbogdanov
 */

#ifndef UART_H_
#define UART_H_

#include <stdint.h>

void initClockSystem();
void initUART();
void UARTCharPut(char TXChar);
char UARTCharGet(uint8_t echo_on_off);

#endif /* UART_H_ */
