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

/**
 * @brief Point d'entrée principal de l'application.
 * @return 1 en cas de fin de programme
 */
int main(void) {
    appdata.state=APP_INIT;
    while (1) {
        switch (appdata.state) {
            case APP_INIT:
                /**
                 * @brief Initialisation de l'application.
                 *
                 * - Configure le système et les périphériques.
                 * - Définit les valeurs par défaut des variables d'état.
                 * - Vérifie l'absence d'interruption pour configurer l'accéléromètre.
                 * - Passe à l'état d'attente d'interruption.
                 */
                SYSTEM_Initialize();
                appdata.status = 0;
                appdata.firstTimeSincePowerUp = true;
                appdata.shakenHasOccured = false;
                appdata.anymHasOccured = false;
                appdata.APP_DelayTimeIsRunning = false;
                appdata.AppDelay = DISPLAYTIME;
                appdata.disp=0;
                appdata.RC =0;
                //set PWM timing at displayTime/3 
                appdata.cntPwmWaiting = (DISPLAYTIME/(STEPON*10));
                uint16_t randomSum = 0;
                appdata.nombreEntier = 0;
                
                // initialize the device
               
                POWER_HOLD = 1; //maintien alim ON

                //si  pas d'interrupt  
                if (!INT_SHAKE) {
                    //config accelerom�tre
                    MC3419_start();
                    //maintien alim OFF
                   POWER_HOLD = 0;
                }
                SetStates(APP_WAIT_FOR_INT);
                break;


            case APP_WAIT_FOR_INT:
                /**
                 * @brief Attente d'une interruption de l'accéléromètre.
                 *
                 * - Lit le registre d'état de l'accéléromètre.
                 * - Vérifie les interruptions de type "shake" et "any motion".
                 * - Si une interruption est détectée et que c'est la première fois depuis la mise sous tension,
                 *   passe à l'état de calcul.
                 */
                
                //Lecture registre accéle
                appdata.status = MC3419_ReadStatusRegister();
                appdata.shakenHasOccured = (appdata.status & SHAKE_INT);
                appdata.anymHasOccured = (appdata.status & ANYM_INT);
                if ((appdata.shakenHasOccured || appdata.anymHasOccured)&& (appdata.firstTimeSincePowerUp == true)) {
                    appdata.firstTimeSincePowerUp = false;
                    SetStates(APP_CALC);
                }
                break;
            case APP_CALC:
                /**
                 * @brief Calcule la valeur pseudo-aléatoire du dé à partir des registres de l'accéléromètre.
                 *
                 * - Additionne les valeurs des axes X, Y, Z pour obtenir une graine.
                 * - Utilise srand/rand pour générer un nombre pseudo-aléatoire.
                 * - Garantit que le résultat est compris entre 1 et 6 (jamais 0).
                 * - Passe à l'état d'affichage.
                 */
                randomSum = ReadRegister8(addr_Xout_Ex_L);
                randomSum += ReadRegister8(addr_Xout_Ex_H);
                randomSum += ReadRegister8(addr_Yout_Ex_L);
                randomSum += ReadRegister8(addr_Yout_Ex_H);
                randomSum += ReadRegister8(addr_Zout_Ex_L);
                randomSum += ReadRegister8(addr_Zout_Ex_H);
                srand(randomSum);
                randomSum = rand();
                //pour récupérer une valeur entre 1 et 6
                appdata.nombreEntier = randomSum % 6;
                if (appdata.nombreEntier == 0) {
                    appdata.nombreEntier = 1;
                }
                SetStates(APP_DISPLAY);
                break;
            case APP_DISPLAY:
                /**
                 * @brief Prépare l'affichage du résultat sur les LEDs.
                 *
                 * - Initialise le rapport cyclique PWM (RC) à 10.
                 * - Active l'affichage (disp=1).
                 * - Passe à l'état d'attente d'affichage.
                 */
                appdata.RC =10;
                appdata.disp=1;
                SetStates(APP_DELAY);
                break; 
            case APP_DELAY:
                /**
                 * @brief Lance l'attente d'affichage du résultat.
                 *
                 * - Démarre l'attente bloquante (affichage du dé).
                 * - Passe à l'état d'extinction.
                 */
                APP_WaitStart(DISPLAYTIME);
                SetStates(APP_KILL);
                break;
            case APP_KILL:
                /**
                 * @brief Éteint les LEDs et met le système en veille si aucune interruption n'est détectée.
                 *
                 * - Éteint l'affichage.
                 * - Efface les interruptions de l'accéléromètre.
                 * - Si aucune interruption, coupe l'alimentation et boucle infinie pour arrêt total.
                 */
                DISPLAYNONUM();
                MC3419_clearRegister();
                if (!INT_SHAKE) {
                    // maintien alim OFF
                    MC3419_clearRegister();
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
    appdata.cntPwmWaiting--;
    //APP_WaitStart(cnt);

}

/**
 * @brief Attente bloquante pendant un temps donné en ms (utilise le timer 1).
 * @param waitingTime_ms Durée d'attente en millisecondes
 */
void APP_WaitStart(uint16_t waitingTime_ms) {
    
    int8_t step = 10;
    static int8_t sens = RAMPUP;
    appdata.AppDelay = waitingTime_ms - 1;
    static uint16_t cntFullON = 0;
    TMR1_Start();
    appdata.APP_DelayTimeIsRunning = 1;
    while (appdata.APP_DelayTimeIsRunning) {
        //Display_Dice_PWM with 10% RC 
        if(appdata.disp)
        {
        Display_Dice_PWM(appdata.nombreEntier, appdata.RC);
        

        if (appdata.cntPwmWaiting == 0) {
            //resest the "timer" 
            appdata.cntPwmWaiting = (DISPLAYTIME / (STEPON * STEPPWM));
        
            switch (sens) {
                case RAMPDOWN:
                    appdata.RC -= step;
                    if (appdata.RC < 10) {
                        appdata.RC = 10;
                        sens = RAMPSTATIC;
                    }


                    break;
                case RAMPUP:
                    appdata.RC += step;
                    
                    if (appdata.RC >= 100) {
                        appdata.RC = 100;
                        sens =RAMPSTATIC;
                    }

                    break;
                case RAMPSTATIC:
                   
                    if (cntFullON >= (STEPPWM-1))
                    {
                        sens =RAMPDOWN;
                    }
                    else
                    {
                        cntFullON++;
                    }
                    break;

                default:
                    sens = 1;
                    appdata.RC = 10; // start at minimum

                    break;
            }

            }
        }
    }
    TMR1_Stop();
    
    
}

/**
 * @brief Change l'état courant de l'application.
 * @param newstate Nouvel état à appliquer
 */
void SetStates(states newstate) {
    appdata.state = newstate;
}

/**
 * @brief Callback du core timer pour gérer la variation de RC.
 */
void APP_CORETIMER_CALLBACK(void)
{
    static int8_t sens=1;
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


