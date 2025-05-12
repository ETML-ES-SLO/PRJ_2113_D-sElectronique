/* 
 * File:   Main.h
 * Author: maxcolloud
 *
 * Created on October 26, 2021, 10:37 AM
 */

#ifndef MAIN_H
#define	MAIN_H
#include "stdint.h"
#ifdef	__cplusplus
extern "C" {
#endif

void APP_WaitStart(uint16_t waitingTime);
void APP_TMR1_CallBack();




#ifdef	__cplusplus
}

#endif

#endif	/* MAIN_H */

