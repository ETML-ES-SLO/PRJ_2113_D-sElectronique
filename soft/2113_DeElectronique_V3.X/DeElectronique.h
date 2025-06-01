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
    /**
     * @brief Éteint toutes les LEDs du dé.
     */
    void DISPLAYNONUM (void);
    /**
     * @brief Affiche le chiffre 1 sur le dé.
     */
    void DISPLAY_NUM1 (void);
    /**
     * @brief Affiche le chiffre 2 sur le dé.
     */
    void DISPLAY_NUM2 (void);
    /**
     * @brief Affiche le chiffre 3 sur le dé.
     */
    void DISPLAY_NUM3 (void);
    /**
     * @brief Affiche le chiffre 4 sur le dé.
     */
    void DISPLAY_NUM4 (void);
    /**
     * @brief Affiche le chiffre 5 sur le dé.
     */
    void DISPLAY_NUM5 (void);
    /**
     * @brief Affiche le chiffre 6 sur le dé.
     */
    void DISPLAY_NUM6 (void);
    /**
     * @brief Affiche un nombre aléatoire entre 1 et 6 sur le dé.
     * @param Number Nombre à afficher.
     */
    void RandomNum (int Number);
    /**
     * @brief Affiche le nombre sur le dé avec PWM (effet de fade).
     * @param NumberToDisplay Nombre à afficher.
     * @param dutyCycle Rapport cyclique du PWM.
     */
    void Display_Dice_PWM (int NumberToDisplay, char dutyCycle);
    /**
     * @brief Applique un effet de fondu sur le PWM.
     * @param dutyCycle Rapport cyclique actuel.
     * @return Nouveau rapport cyclique.
     */
    char fade (char dutyCycle);
#ifdef	__cplusplus
}
#endif

#endif	/* DEELECTRONIQUE_H */

