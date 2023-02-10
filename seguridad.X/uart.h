/* 
 * File:   uart.h
 * Author: Logicos
 */
/**
 * @file uart
 * @version 1.0
 * @date 10-02-2023
 * @brief funciones que permiten comunicacion entre Tx y Rx
 * @title Configuracion del UART
 */
#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <pic16f887.h>
#include <xc.h>
   
void USART_Init(long);
/**
 * @brief void USART_TxChar envia un caracter para poder ser transmitido
 * @param recibe un caracter para ser transmitido
 */ 
void USART_TxChar(char);
/**
 * @brief void USART_SendString envia un caracter
 * @param recibe un caracter
 */
void USART_SendString(const char *);
/**
 * @brief void USART_RxChar sirve como funcion de receptor
 */ 
char USART_RxChar();

#define F_CPU 8000000/64
//#define Baud_value(baud_rate) (((float)(F_CPU)/(float)baud_rate)-1)
#define Baud_value (((float)(F_CPU)/(float)baud_rate)-1)


#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

