/* 
 * File:   DeElectronique.h
 * Author: maxcolloud
 *
 * Created on November 3, 2021, 1:35 PM
 */

#include "xc.h"
#include "Accelerometre.h"

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
    
#define HOLD LATBbits.LATB13
    
    // Fonctions
    void NONUM (void);
    void NUM1 (void);
    void NUM2 (void);
    void NUM3 (void);
    void NUM4 (void);
    void NUM5 (void);
    void NUM6 (void);
    void RandomNum (int Number);

#ifdef	__cplusplus
}
#endif

#endif	/* DEELECTRONIQUE_H */

