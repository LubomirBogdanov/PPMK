/*
 * uart.c
 *
 *  Created on: 26.09.2016
 *      Author: lbogdanov
 */
#include "uart.h"
#include  <msp430.h>
#include <stdio.h>
#include <string.h>
#include <driverlib.h>

//N = fBRCLK / baud rate = 16 000 000 / 9600 = 1666.666
//OS16 = 1, UCBRx = INT(N/16) = 1666.666 / 16 = 104.166 = 104
//UCBRFx = INT([(N/16) – INT(N/16)] × 16) = 0.166 x 16 = 2.656 = 2
//N ( = N - INT(N) ) in Table 24-4 = 0,666 => 0xAD
EUSCI_A_UART_initParam uart_init_struct = {
		.selectClockSource = EUSCI_A_UART_CLOCKSOURCE_SMCLK,
		.clockPrescalar = 104,
		.firstModReg = 2,
		.secondModReg = 0xD6,
		.parity = EUSCI_A_UART_NO_PARITY,
		.msborLsbFirst = EUSCI_A_UART_LSB_FIRST,
		.numberofStopBits = EUSCI_A_UART_ONE_STOP_BIT,
		.uartMode = EUSCI_A_UART_MODE,
		.overSampling = EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION
};

void initUART()
{
	// Configure UART pins
	GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P3, GPIO_PIN4, GPIO_PRIMARY_MODULE_FUNCTION);
	LCD_C_setPinAsPortFunction(LCD_C_BASE, LCD_C_SEGMENT_LINE_25);
	GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P3, GPIO_PIN5, GPIO_PRIMARY_MODULE_FUNCTION);
	LCD_C_setPinAsPortFunction(LCD_C_BASE, LCD_C_SEGMENT_LINE_24);

	EUSCI_A_UART_init(EUSCI_A1_BASE, &uart_init_struct);
	EUSCI_A_UART_enable(EUSCI_A1_BASE);
}

void UARTCharPut(char TXChar)
{
	EUSCI_A_UART_transmitData(EUSCI_A1_BASE, TXChar);
}

/*!
 * \brief UARTCharGet - get a single char on the UART
 * \param echo_on_off - 1 echo is ON, 0 echo is OFF
 * \return The received char from the UART.
 */
char UARTCharGet(uint8_t echo_on_off)
{
	char tempCh;

    tempCh = EUSCI_A_UART_receiveData(EUSCI_A1_BASE);
    if(echo_on_off){
    	EUSCI_A_UART_transmitData(EUSCI_A1_BASE, tempCh); //Echo the received char.
    }

    return tempCh;
}
