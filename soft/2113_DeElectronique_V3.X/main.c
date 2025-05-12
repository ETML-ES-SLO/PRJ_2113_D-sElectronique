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
#include "Main.h"
#include "Mc32Delays.h"
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
bool shakenHasOccured = false;
bool anymHasOccured = false;
bool APP_DelayTimeIsRunning = false;
bool _10msOccured = false;
bool _50msOccured = false;
uint8_t status = 0;
static uint16_t AppDelay = 0;


/*
int16_t testX;
int16_t testY;
int16_t testz; 
uint8_t mockShakeInterrupt=1;
 */
int main(void) {
    // initialize the device
    SYSTEM_Initialize();
    POWER_HOLD = 1; //assure maintien alim.
    
    if (!INT_SHAKE) {

        MC3419_start();
        POWER_HOLD = 0;
    } 
    uint16_t randomSum = 0;
    uint8_t nombreEntier = 0;
    MC3419_start();//added cause bug afte like 10 rolls on last PCB version used
    //to clean EXT_INT at startut otherwise it's stuck Uc OFF with EXT_INT
    //-> need to shake longer
    while (1) {
  
        status = MC3419_ReadStatusRegister();
        shakenHasOccured = (status& SHAKE_INT);
        anymHasOccured =(status& ANYM_INT);

        if ((shakenHasOccured || anymHasOccured)&& (firstTimeSincePowerUp == true)) {
            firstTimeSincePowerUp = false;
            
            randomSum = ReadRegister8(addr_Xout_Ex_L);
            randomSum += ReadRegister8(addr_Xout_Ex_H);
            randomSum +=ReadRegister8(addr_Yout_Ex_L);
            randomSum +=ReadRegister8(addr_Yout_Ex_H);
            randomSum +=ReadRegister8(addr_Zout_Ex_L);
            randomSum +=ReadRegister8(addr_Zout_Ex_H);
            //randomSum = testX+testY+testz;
            srand(randomSum);
            randomSum = rand();

            
            nombreEntier = randomSum % 6;
            if (nombreEntier == 0) {
                nombreEntier = 1;
            }
            Display_Dice_PWM(nombreEntier, 10);
            APP_WaitStart(5000);
            MC3419_clearRegister();
            if (!INT_SHAKE) {

                POWER_HOLD = 0;
                while (1) {
                };
            }

        }
    }
    return 1;
}

/**
 End of File
 */
void APP_TMR1_CallBack() {

    if (AppDelay > 0) {
        AppDelay--;
    } else {
        APP_DelayTimeIsRunning = 0;
    }

    //APP_WaitStart(cnt);

}

void APP_WaitStart(uint16_t waitingTime_ms) {

    AppDelay = waitingTime_ms - 1;
    TMR1_Start();
    APP_DelayTimeIsRunning = 1;
    while (APP_DelayTimeIsRunning) {
    }
    TMR1_Stop();
}




