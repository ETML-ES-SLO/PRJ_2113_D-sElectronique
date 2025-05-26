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

//set the display time to 10s  cause setting are in ms   
#define DISPLAYTIME  3000 //set to 3S
#define STEPON 3 //there is 3 step in display sequence
#define DISPLAY_UP  1000 //ramp up is 1s
#define DISPLAY_ON  1000    //static up is 1s
#define DISPLAY_DODW    1000    //ramp down is 1s
#define STEPPWM 10    //there is 10  step to do 
#define STEPWMSEC (DISPLAY_ON/STEPPWM) //so this is the time per pwm step 
#define TIMERATIO 1000 //and this is time ratio cause 1s= 1000ms


    typedef enum {
        RAMPUP,
        RAMPSTATIC,
        RAMPDOWN,
    } sens;

    typedef enum {
        APP_INIT,
        APP_WAIT_FOR_INT,
        APP_CALC,
        APP_DISPLAY,
        APP_DELAY,
        APP_KILL,
    } states;

    typedef struct {
        uint8_t state;
        bool disp;
        bool firstTimeSincePowerUp;
        bool shakenHasOccured;
        bool anymHasOccured;
        bool APP_DelayTimeIsRunning;
        uint16_t AppDelay;
        uint8_t status;
        uint8_t nombreEntier;
        uint8_t RC;
        uint16_t cntPwmWaiting;
    } appData;


    void APP_WaitStart(uint16_t waitingTime);
    void APP_TMR1_CallBack();
    bool APP_WaitStart_noBlocking();
    void SetStates(states newstate);
    void APP_CORETIMER_CALLBACK(void);

#ifdef	__cplusplus
}

#endif

#endif	/* MAIN_H */

