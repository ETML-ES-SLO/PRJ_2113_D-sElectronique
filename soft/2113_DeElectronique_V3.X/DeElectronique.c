#include "DeElectronique.h"
#include <stdbool.h>

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
void DISPLAY_NUM1 (void)
{
    LED3 = 1;
    //LED0 = 1;
}
void DISPLAY_NUM2 (void)
{
    LED0 = 1;
    LED6 = 1;
}
void DISPLAY_NUM3 (void)
{
    LED0 = 1;
    LED3 = 1;
    LED6 = 1;
}
void DISPLAY_NUM4 (void)
{
    LED0 = 1;
    LED2 = 1; 
    LED4 = 1;
    LED6 = 1;
}
void DISPLAY_NUM5 (void)
{
    LED0 = 1;
    LED2 = 1;
    LED3 = 1;
    LED4 = 1;
    LED6 = 1;
}
void DISPLAY_NUM6 (void)
{
    LED0 = 1;
    LED1 = 1;
    LED2 = 1;
    LED4 = 1;
    LED5 = 1;
    LED6 = 1;
}

void Display_Dice_PWM (int NumberToDisplay, char dutyCycle)
{
   static char compteurPWM=0;
   
   compteurPWM++;
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
        }
   }
}

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