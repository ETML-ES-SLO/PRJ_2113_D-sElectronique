#include "DeElectronique.h"
#include <stdbool.h>

/**
 * @brief Ã‰teint toutes les LEDs du dé.
 * @details Met toutes les sorties LED à 0 pour éteindre l'affichage du dé.
 */
void DISPLAYNONUM (void)
{
    LED0 = 0;
    LED1 = 0;
    LED2 = 0;
    LED3 = 0;
    LED4 = 0;
    LED5 = 0;
    LED6 = 0;
}

/**
 * @brief Affiche le chiffre 1 sur le dé.
 * @details Allume la LED centrale pour représenter le 1.
 */
void DISPLAY_NUM1 (void)
{
    LED3 = 1;
    //LED0 = 1;
}

/**
 * @brief Affiche le chiffre 2 sur le dé.
 * @details Allume deux LEDs opposées pour représenter le 2.
 */
void DISPLAY_NUM2 (void)
{
    LED0 = 1;
    LED6 = 1;
}

/**
 * @brief Affiche le chiffre 3 sur le dé.
 * @details Allume trois LEDs pour représenter le 3.
 */
void DISPLAY_NUM3 (void)
{
    LED0 = 1;
    LED3 = 1;
    LED6 = 1;
}

/**
 * @brief Affiche le chiffre 4 sur le dé.
 * @details Allume quatre LEDs pour représenter le 4.
 */
void DISPLAY_NUM4 (void)
{
    LED0 = 1;
    LED2 = 1; 
    LED4 = 1;
    LED6 = 1;
}

/**
 * @brief Affiche le chiffre 5 sur le dé.
 * @details Allume cinq LEDs pour représenter le 5.
 */
void DISPLAY_NUM5 (void)
{
    LED0 = 1;
    LED2 = 1;
    LED3 = 1;
    LED4 = 1;
    LED6 = 1;
}

/**
 * @brief Affiche le chiffre 6 sur le dé.
 * @details Allume six LEDs pour représenter le 6.
 */
void DISPLAY_NUM6 (void)
{
    LED0 = 1;
    LED1 = 1;
    LED2 = 1;
    LED4 = 1;
    LED5 = 1;
    LED6 = 1;
}

/**
 * @brief Affiche le nombre sur le dé avec PWM (effet de fade).
 * @details Gère l'affichage du nombre avec modulation de largeur d'impulsion pour un effet visuel.
 * @param NumberToDisplay Nombre à afficher (1 Ã  6).
 * @param dutyCycle Rapport cyclique du PWM.
 */
void Display_Dice_PWM (int NumberToDisplay, char dutyCycle)
{
   static char compteurPWM=0;
   static char sens =1;
   compteurPWM++;
   //dutyCycle=sens;
   if (compteurPWM <dutyCycle)
   {
       switch (NumberToDisplay)
        {
            case 0 :
                DISPLAY_NUM1();
                break;
            case 1 :
                DISPLAY_NUM2();
                break;
             case 2 :
                DISPLAY_NUM3();

                break;
            case 3 :
                DISPLAY_NUM4();

                break;
            case 4 :
                DISPLAY_NUM5();

                break;
            case 5 :
                DISPLAY_NUM6();

                break;
            default :
                DISPLAY_NUM6();
                DISPLAY_NUM1();
                break;
        }
   
   }
   else
   {
        DISPLAYNONUM();
        if (compteurPWM >= 100)
        {
            compteurPWM =0;
            if(sens == 1)
            {
                sens =-1;
            }
            else
            {
                sens=1;
            }
           // compteurPWM =0;
        }
   }
}

/**
 * @brief Affiche un nombre aléatoire entre 1 et 6 sur le dé.
 * @details Utilise le modulo pour garantir une valeur entre 1 et 6.
 * @param Number Nombre à  afficher.
 */
void RandomNum (int Number)
{
    uint8_t EntierNumber;
    
    EntierNumber = Number %6;
    
    switch (EntierNumber)
    {
        case 0 :
            DISPLAY_NUM1();
           
            break;
        case 1 :
            DISPLAY_NUM2();
            
            break;
        case 2 :
            DISPLAY_NUM3();
            
            break;
        case 3 :
            DISPLAY_NUM4();
           
            break;
        case 4 :
            DISPLAY_NUM5();
           
            break;
        case 5 :
            
            DISPLAY_NUM6();
            break;
        default :
            break;
    }
}