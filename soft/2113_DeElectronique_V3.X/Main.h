/* 
 * File:   Main.h
 * Author: maxcolloud
 *
 * Created on October 26, 2021, 10:37 AM
 */

#ifndef MAIN_H
#define	MAIN_H
#include "stdint.h"
#include "stdbool.h"
#ifdef	__cplusplus
extern "C" {
#endif
    typedef enum
    {
        APP_INIT,
        APP_WAIT_FOR_INT,
        APP_CALC,
        APP_DISPLAY,
        APP_DELAY,
        APP_KILL,        
    }states;

    typedef struct {
        uint8_t state;
        bool disp;
        bool firstTimeSincePowerUp ;
        bool shakenHasOccured;
        bool anymHasOccured;
        bool APP_DelayTimeIsRunning;
        uint16_t AppDelay;
        uint8_t status;
        uint8_t nombreEntier;
        
    } appData;

    
void APP_WaitStart(uint16_t waitingTime);
void APP_TMR1_CallBack();
bool APP_WaitStart_noBlocking();
void SetStates(states newstate);


#ifdef	__cplusplus
}

#endif

#endif	/* MAIN_H */

