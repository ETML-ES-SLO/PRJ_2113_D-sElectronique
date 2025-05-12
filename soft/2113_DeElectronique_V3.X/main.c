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
uint8_t status = 0;
static uint16_t AppDelay = 0;


int main(void) {
    // initialize the device
    SYSTEM_Initialize();
    POWER_HOLD = 1; //maintien alim ON
    
    //si  pas d'interrupt  
    if (!INT_SHAKE) {
        //config acceleromètre
        MC3419_start();
        // maintien alim OFF
        POWER_HOLD = 0;
    } 
    //configure acceleromete otherwise INT always stay ON 
    MC3419_start();
    uint16_t randomSum = 0;
    uint8_t nombreEntier = 0;
    
    while (1) {
        //Lecture registre accél
        status = MC3419_ReadStatusRegister();
        shakenHasOccured = (status& SHAKE_INT);
        anymHasOccured =(status& ANYM_INT);
        //si une interrupt et premier allumage 
        if ((shakenHasOccured || anymHasOccured)&& (firstTimeSincePowerUp == true)) {
            firstTimeSincePowerUp = false;
            //Somme de la valeur de chaque axe
            randomSum = ReadRegister8(addr_Xout_Ex_L);
            randomSum += ReadRegister8(addr_Xout_Ex_H);
            randomSum +=ReadRegister8(addr_Yout_Ex_L);
            randomSum +=ReadRegister8(addr_Yout_Ex_H);
            randomSum +=ReadRegister8(addr_Zout_Ex_L);
            randomSum +=ReadRegister8(addr_Zout_Ex_H);
            //générateur de nombre aléatoire
            srand(randomSum);
            randomSum = rand();

            //pour récupérer une valeure entre 1 et 6
            nombreEntier = randomSum % 6;
            if (nombreEntier == 0) {
                nombreEntier = 1;
            }
            //Affichage du nombre 
            Display_Dice_PWM(nombreEntier, 10);
            //attente de 5 secondes (temps en ms)
            APP_WaitStart(5000);
            //clear interrupt 
            MC3419_clearRegister();
            //test pour être sur 
            if (!INT_SHAKE) {
                // maintien alim OFF
                POWER_HOLD = 0;
                //boucle infini pour être sur
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

/*
 * Fct de call back du timer en fct du delay store dans AppData
 */
void APP_TMR1_CallBack(void) {

    if (AppDelay > 0) {
        AppDelay--;
    } else {
        APP_DelayTimeIsRunning = 0;
    }

    //APP_WaitStart(cnt);

}
/*
 * Fct d'attente en fct du param d'entrée en ms 
 * utilisation du timer 1 attente = 1ms
*/
void APP_WaitStart(uint16_t waitingTime_ms) {

    AppDelay = waitingTime_ms - 1;
    TMR1_Start();
    APP_DelayTimeIsRunning = 1;
    while (APP_DelayTimeIsRunning) {
    }
    TMR1_Stop();
}




