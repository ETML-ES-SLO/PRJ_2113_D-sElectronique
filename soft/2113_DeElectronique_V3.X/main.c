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
appData appdata;

int main(void) {
    appdata.state=APP_INIT;
    while (1) {
        switch (appdata.state) {
            case APP_INIT:
                SYSTEM_Initialize();
                appdata.status = 0;
                appdata.firstTimeSincePowerUp = true;
                appdata.shakenHasOccured = false;
                appdata.anymHasOccured = false;
                appdata.APP_DelayTimeIsRunning = false;
                appdata.AppDelay = 5000;
                appdata.disp=0;
                appdata.RC =10;
                uint16_t randomSum = 0;
                appdata.nombreEntier = 0;
                //static int8_t sens = 1;
                //static uint8_t ret = 0;
                //int8_t i = 0;
                // initialize the device
               
                POWER_HOLD = 1; //maintien alim ON

                //si  pas d'interrupt  
                if (!INT_SHAKE) {
                    //config acceleromètre
                    MC3419_start();
                    //maintien alim OFF
                    POWER_HOLD = 0;
                }
                SetStates(APP_WAIT_FOR_INT);
                break;


            case APP_WAIT_FOR_INT:
                
                //Lecture registre accél
                appdata.status = MC3419_ReadStatusRegister();
                appdata.shakenHasOccured = (appdata.status & SHAKE_INT);
                appdata.anymHasOccured = (appdata.status & ANYM_INT);
                if ((appdata.shakenHasOccured || appdata.anymHasOccured)&& (appdata.firstTimeSincePowerUp == true)) {
                    appdata.firstTimeSincePowerUp = false;
                    SetStates(APP_CALC);
                }
                break;
            case APP_CALC:
                //Somme de la valeur de chaque axe
                randomSum = ReadRegister8(addr_Xout_Ex_L);
                randomSum += ReadRegister8(addr_Xout_Ex_H);
                randomSum += ReadRegister8(addr_Yout_Ex_L);
                randomSum += ReadRegister8(addr_Yout_Ex_H);
                randomSum += ReadRegister8(addr_Zout_Ex_L);
                randomSum += ReadRegister8(addr_Zout_Ex_H);
                //générateur de nombre aléatoire
                srand(randomSum);
                randomSum = rand();

                //pour récupérer une valeure entre 1 et 6
                appdata.nombreEntier = randomSum % 6;
                if (appdata.nombreEntier == 0) {
                    appdata.nombreEntier = 1;
                }
                
                SetStates(APP_DISPLAY);
                break;
            case APP_DISPLAY:
                
                
                appdata.disp=1;
                SetStates(APP_DELAY);
                break; 
                
            case APP_DELAY:
                
                APP_WaitStart(10000);
                SetStates(APP_KILL);
                
                
                break;
            case APP_KILL:
                DISPLAYNONUM();
                MC3419_clearRegister();
                //test pour être sur 
                //POWER_HOLD = 0;
                APP_WaitStart(1);
                if (!INT_SHAKE) {
                    // maintien alim OFF
                   
                    POWER_HOLD = 0;
                    //boucle infini pour être sur
                    while (1) {
                    };
                    break;

                }







        }
    }
    return 1;
}

/**
 End of File
 */

/*
 * Fct de call back du timer en fct du delay store dans AppData
 */
void APP_TMR1_CallBack(void) {

    if (appdata.AppDelay > 0) {
        appdata.AppDelay--;
    } else {
        appdata.APP_DelayTimeIsRunning = 0;
    }

    //APP_WaitStart(cnt);

}

/*
 * Fct d'attente en fct du param d'entrée en ms 
 * utilisation du timer 1 attente = 1ms
 * attente bloquante
 */
void APP_WaitStart(uint16_t waitingTime_ms) {
    appdata.AppDelay = waitingTime_ms - 1;
    TMR1_Start();
    appdata.APP_DelayTimeIsRunning = 1;
    while (appdata.APP_DelayTimeIsRunning) {
        //Display_Dice_PWM
        Display_Dice_PWM(appdata.nombreEntier,appdata.RC);
    }
    TMR1_Stop();
}

void SetStates(states newstate) {
    appdata.state = newstate;
}


//add comms
void APP_CORETIMER_CALLBACK(void)
{
   
    static int8_t sens=1;
    /*
    appdata.RC+= sens;
    if (appdata.RC>=100)
    {
        appdata.RC=10;
    }
    
    */
    int8_t step = 10; 
    if (sens == 1) {
        appdata.RC += step;
        if (appdata.RC >= 100) {
            appdata.RC = 100; 
            sens = -1;        
        }
    } else if (sens == -1) {
        appdata.RC -= step;
        if (appdata.RC < 10) {
            appdata.RC = 10; 
            sens = 1;        
        }
    } else {
        sens = 1;
        appdata.RC = 10; // start at minimum
    }
    
}


