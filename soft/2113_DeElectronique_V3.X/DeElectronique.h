/* 
 * File:   DeElectronique.h
 * Author: maxcolloud
 *
 * Created on November 3, 2021, 1:35 PM
 */

#include "xc.h"
#include "Accelerometre.h"
#include <stdbool.h>

#ifndef DEELECTRONIQUE_H
#define	DEELECTRONIQUE_H


#ifdef	__cplusplus
extern "C" {
#endif
    
#define INT_SHAKE PORTBbits.RB12
    
#define LED0 LATAbits.LATA0
#define LED1 LATAbits.LATA1
#define LED2 LATAbits.LATA2
#define LED3 LATBbits.LATB2
#define LED4 LATAbits.LATA3
#define LED5 LATBbits.LATB4
#define LED6 LATAbits.LATA4
    
#define POWER_HOLD LATBbits.LATB13
    
    // Fonctions
    void DISPLAYNONUM (void);
    void DISPLAY_NUM1 (void);
    void DISPLAY_NUM2 (void);
    void DISPLAY_NUM3 (void);
    void DISPLAY_NUM4 (void);
    void DISPLAY_NUM5 (void);
    void DISPLAY_NUM6 (void);
    void RandomNum (int Number);
    void Display_Dice_PWM (int NumberToDisplay, char dutyCycle);
    char fade (char dutyCycle);
#ifdef	__cplusplus
}
#endif

#endif	/* DEELECTRONIQUE_H */

