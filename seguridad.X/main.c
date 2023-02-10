/* PROYECTO CARRITO CON MEDICIÒN DE TEMPERATURA*/

//Inclusiòn de librerias a usar 
#include <xc.h>
#include <pic16f887.h>
#include <stdio.h>
#include <string.h>
#include "CONFIG.h"
#include "LCD.h"
#include "adc.h"
#include "uart.h"
#include <math.h>

//DECLARACIÓN DE VARIABLES
#define beta 4090 //the beta of the thermistor
#define TEMPERATURA_ALTA 30 // //
#define TEMPERATURA_IDEAL 27//
#define TEMPERATURA_BAJA 24//
#define HUMEDAD_ALTA 100 //
#define HUMEDAD_IDEAL 80 //
#define HUMEDAD_BAJA 60 //
#define MUCHA_LUZ 20 //
#define lUZ_IDEAL 150 //
#define POCA_LUZ 900 //


unsigned char idx = 0;
char Temperatura[4];    
char Humedad[4];
char Luz [];
char Fila1[16];
char Fila2[16];
long Sensor_Temperatura;
long Sensor_Humedad;
long Sensor_Luz;


void main() {
    //Configura Fosc = 8Mhz interno, Fuente de Fosc del sistema = interno
    OSCCON = 0x71; //Configura oscilador interno (FOSC = 8Mhz)
    TRISE = 0x00;
    ANSEL = 0x07;
    USART_Init(9600);
    
    
    LCD_Init(); //Inicializa el LCD
    ADC_Init();
    __delay_ms(5000);
    LCD_Command(0xC0);
    
    while (1) {
       
        //Etapa de Monitoreo
       Sensor_Temperatura = 1023 - ADC_Read(0);
        __delay_ms(500); 
       Sensor_Humedad = ADC_Read(1);
        __delay_ms(500); 
       Sensor_Luz = ADC_Read(2);
       __delay_ms(500); 
     
        
        //Etapa de procesamiento de los datos recibidos
        float Valor_Temperatura = (float) (beta /(log((1025.0 * 10 / Sensor_Temperatura - 10) / 10) + beta / 298.0) - 273.0);
        //float Porcentaje_Humedad = (-0.17 * Sensor_Humedad)+171.4;    
        /*convert integer value to ASCII string */
        
        //Visualización en el LCD 
        strcpy(Fila1,"Temperatura: ");
        sprintf(Temperatura,"%d%cC  ",(int) Valor_Temperatura ,0xdf);
        strcat(Fila1, Temperatura);
         __delay_ms(500); //Deja una espera de 5s para que se reproduzca el mensaje
        //strcat(Fila1,"H: ");
        //sprintf (Humedad,"%d%c  ", (int)Porcentaje_Humedad,0x25);
        //strcat(Fila1,Humedad);
        __delay_ms(500); 
        LCD_String_xy(0,0,Fila1);
        //strcpy(Fila2, "L: ");
        //sprintf (Luz, "%d  ", (int)(Sensor_Luz));
        //strcat(Fila2,Luz);
        __delay_ms(500); 
        //LCD_String_xy(2,0,Fila2);
        
        USART_SendString(Temperatura);
        
        //Limites temperatura usando condicionales if y else
        if (Valor_Temperatura > TEMPERATURA_ALTA){
           PORTEbits.RE0=1;
           PORTEbits.RE1=0;
           PORTEbits.RE2=0;
        }else{
            if(TEMPERATURA_ALTA >= Valor_Temperatura && Valor_Temperatura >= TEMPERATURA_BAJA){
               PORTEbits.RE0=0;
               PORTEbits.RE1=1;
               PORTEbits.RE2=0;           
            }else{ 
                if(Valor_Temperatura<TEMPERATURA_BAJA){
                   PORTEbits.RE0=0;
                   PORTEbits.RE1=0;
                   PORTEbits.RE2=1;
                }else{
                    PORTEbits.RE0=0;
                    PORTEbits.RE1=0;
                    PORTEbits.RE2=0;   
                }
            }
        }
        __delay_ms(2000);
        LCD_Clear(); //Llamado a funciòn que limpia la pantalla del LCD
    }
}

