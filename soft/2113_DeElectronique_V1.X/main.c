/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

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
/*
                         Main application
 */
int main(void)
{    
    // initialize the device
    SYSTEM_Initialize();
    HOLD = 1;   //assure maintien alim.
    
    MC3419_start();
    
//    if (!INT_SHAKE)
//    {
//        MC3419_start();
//        HOLD = 0;
//        while(1);
//    }
//    uint8_t test;
//    int seed;
    while (1)
    {
//        test = MC3419_ReadStatusRegister();
//        if (test == SHAKE_INT)
//        {
//            seed = ReadRegister8(addr_Xout_Ex_L);
//            seed = seed + ReadRegister8(addr_Xout_Ex_H);
//            seed = seed + ReadRegister8(addr_Yout_Ex_L);
//            seed = seed + ReadRegister8(addr_Yout_Ex_H);
//            seed = seed + ReadRegister8(addr_Zout_Ex_L);
//            seed = seed + ReadRegister8(addr_Zout_Ex_H);
//            srand (seed);
//            seed = rand();
//            RandomNum (seed);
            TMR1_Start();
//        }
    }
    return 1; 
}
/**
 End of File
*/