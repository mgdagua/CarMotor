/* 
 * File:   adc.h
 * Author: Logicos
 */
/**
 * @file adc
 * @version 1.0
 * @date 10-02-2023
 * @brief funciones que permiten la inicializacion y lectura del conversor ADC
 * @title Configuracion del adc
 */
#ifndef ADC_H
#define	ADC_H

#ifdef	__cplusplus
extern "C" {
#endif
/**
 * @brief void ADC_Init inicializa el conversor ADC
 * @param recibe parametro para inicializar
 */ 
void ADC_Init(void);
/**
 * @brief void ADC_Read permite la lectura del canal del ADC
 * @param recibe parametro para la lectura
 */ 
int ADC_Read(int channel);


#ifdef	__cplusplus
}
#endif

#endif	/* ADC_H */

