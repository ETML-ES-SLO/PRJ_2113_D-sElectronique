/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c la 

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system intialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.75.1
        Device            :  PIC32MM0064GPL020
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.35
        MPLAB 	          :  MPLAB X v5.05
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/

#include "mcc_generated_files/system.h"
#include "mcc_generated_files/spi1.h"
#include "mcc_generated_files/pin_manager.h"
#include "Accelerometre.h"
#include "DeElectronique.h"
#include "mcc_generated_files/tmr1.h"
#include <stdbool.h>
#include <stdlib.h>
/*
                         Main application
 */
bool firstTimeSincePowerUp = true;
bool shakenHasOccured=false;
/*
int16_t testX;
int16_t testY;
int16_t testz; 
*/
int main(void)
{    
    // initialize the device
    SYSTEM_Initialize();
    POWER_HOLD = 1;   //assure maintien alim.
    
    if(firstTimeSincePowerUp)
    {
        MC3419_start();
    }
    
    shakenHasOccured = (MC3419_ReadStatusRegister()& SHAKE_INT);
    if (!INT_SHAKE)
    {
        POWER_HOLD = 0;
    }
    
    
    
    
    
    //uint8_t test;
  
    int randomSum=0;
    uint8_t nombreEntier=0; 
   // char dutyCycle = 50; //50%
    //char number;
    while (1)
    {
        
        shakenHasOccured = (MC3419_ReadStatusRegister()& SHAKE_INT);
      
        if ( shakenHasOccured && (firstTimeSincePowerUp == 1))
        {
            firstTimeSincePowerUp = false;
            randomSum = ReadRegister8(addr_Xout_Ex_L);
            randomSum += ReadRegister8(addr_Xout_Ex_H);
            randomSum +=ReadRegister8(addr_Yout_Ex_L);
            randomSum +=ReadRegister8(addr_Yout_Ex_H);
            randomSum +=ReadRegister8(addr_Zout_Ex_L);
            randomSum +=ReadRegister8(addr_Zout_Ex_H);
            srand (randomSum);
            randomSum = rand();
            //number=RandomNum (seed);
            nombreEntier = randomSum %6;
            //pointeurfct(seed);
            TMR1_Start();
             // MC3419_start();
            //Display_Dice_PWM(nombreEntier,dutyCycle);
        }    
        /*
        testX= testX|(ReadRegister8(addr_Xout_Ex_H)<<8);
        testX= testX|ReadRegister8(addr_Xout_Ex_L); 
        testY= testY|(ReadRegister8(addr_Yout_Ex_H)<<8);
        testY= testY|ReadRegister8(addr_Yout_Ex_L);   
        testz= testz|(ReadRegister8(addr_Zout_Ex_H)<<8);
        testz= testz|ReadRegister8(addr_Zout_Ex_L); 
        testz=0;
        testY=0;
        testX=0;
        */
       //dutyCycle=fade(dutyCycle);
        if(!(firstTimeSincePowerUp))
        {
            Display_Dice_PWM(nombreEntier,15);
        }
        
               
            
        
    }
    return 1; 
}
/**
 End of File
*/