/*!
\file   LCD.h
\date   2022-06-08
\author Fulvio Vivas <fyvivas@unicauca.edu.co>
\brief  Functions Handler LCD 16x2 mode 4 bits.
 /**
 */
/**
 * @file LCD
 * @version 1.0
 * @date 10-02-2023
 * @brief funciones que permiten asignar lo referente al LCD
 * @title Configuracion del LCD
 */
#ifndef LCD_H
#define	LCD_H

#ifdef	__cplusplus
extern "C" {
#endif
/****************************Functions********************************/
   
#define RS PORTDbits.RD2  /*PIN 0 of PORTD is assigned for register select Pin of LCD*/
#define EN PORTDbits.RD3  /*PIN 1 of PORTD is assigned for enable Pin of LCD */
#define ldata PORTD  /*PORTD(PD4-PD7) is assigned for LCD Data Output*/ 
#define LCD_Port TRISD  /*define macros for PORTD Direction Register*/

/**
 * @brief void LCD_Init inicializa el LCD
 * @param recibe parametro para inicializar
 */    
void LCD_Init(void);                  
/**
 * @brief void LCD_Command envia comandos al LCD
 * @param recibe parametro para ser enviado al LCD
 */ 
void LCD_Command(unsigned char );  /*Send command to LCD*/
/**
 * @brief void LCD_Char envia datos al LCD
 * @param recibe parametro x para ser enviado al LCD
 */ 
void LCD_Char(unsigned char x);    /*Send data to LCD*/
/**
 * @brief void LCD_String presente una cadena de datos
 * @param recibe cadena de datos hacia el LCD
 */ 
void LCD_String(const char *);     /*Display data string on LCD*/
/**
 * @brief void LCD_String_xy presente una cadena de datos
 * @param recibe caracteres que seran representados en el LCD por filas y columnas
 */ 
void LCD_String_xy(char, char , const char *);
/**
 * @brief void LCD_Clear 
 * @param limpia la pantalla del LCD
 */ 
void LCD_Clear(void);                  /*Clear LCD Screen*/


#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

