#include "DeElectronique.h"

void NONUM (void)
{
    LED0 = 0;
    LED1 = 0;
    LED2 = 0;
    LED3 = 0;
    LED4 = 0;
    LED5 = 0;
    LED6 = 0;
}
void NUM1 (void)
{
    LED3 = 1;
}
void NUM2 (void)
{
    LED0 = 1;
    LED6 = 1;
}
void NUM3 (void)
{
    LED0 = 1;
    LED3 = 1;
    LED6 = 1;
}
void NUM4 (void)
{
    LED0 = 1;
    LED2 = 1; 
    LED4 = 1;
    LED6 = 1;
}
void NUM5 (void)
{
    LED0 = 1;
    LED2 = 1;
    LED3 = 1;
    LED4 = 1;
    LED6 = 1;
}
void NUM6 (void)
{
    LED0 = 1;
    LED1 = 1;
    LED2 = 1;
    LED4 = 1;
    LED5 = 1;
    LED6 = 1;
}

void RandomNum (int Number)
{
    uint8_t EntierNumber;
    
    EntierNumber = Number %6;
    
    switch (EntierNumber)
    {
        case 0 :
            NUM1();
            break;
        case 1 :
            NUM2();
            break;
        case 2 :
            NUM3();
            break;
        case 3 :
            NUM4();
            break;
        case 4 :
            NUM5();
            break;
        case 5 :
            NUM6();
            break;
        default :
            break;
    }
}