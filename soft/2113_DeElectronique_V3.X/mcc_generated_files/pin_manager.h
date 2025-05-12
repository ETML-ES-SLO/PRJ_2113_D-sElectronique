/**
  System Interrupts Generated Driver File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the generated manager file for the MPLAB(c) Code Configurator device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description:
    This source file provides implementations for MPLAB(c) Code Configurator interrupts.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - pic24-dspic-pic32mm : 1.75.1
        Device            :  PIC32MM0064GPL020
    The generated drivers are tested against the following:
        Compiler          :  XC32 v2.10
        MPLAB             :  MPLAB X v5.05

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/

#ifndef _PIN_MANAGER_H
#define _PIN_MANAGER_H
/**
    Section: Includes
*/
#include <xc.h>
#include <stdbool.h>
/**
    Section: Device Pin Macros
*/
/**
  @Summary
    Sets the GPIO pin, RA0, high using LATAbits.LATA0.

  @Description
    Sets the GPIO pin, RA0, high using LATAbits.LATA0.

  @Preconditions
    The RA0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA0 high (1)
    IO_RA0_SetHigh();
    </code>

*/
#define SS1_SetHigh()          ( LATBSET = (1 << 15) )
/**
  @Summary
    Sets the GPIO pin, RB15, low using LATBbits.LATB15.

  @Description
    Sets the GPIO pin, RB15, low using LATBbits.LATB15.

  @Preconditions
    The RB15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB15 low (0)
    SS1_SetLow();
    </code>

*/
#define SS1_SetLow()           ( LATBCLR = (1 << 15) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RB15, low or high using LATBbits.LATB15.

  @Preconditions
    The RB15 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RB15 to low.
    SS1_SetValue(false);
    </code>

*/

inline static void SS1_SetValue(bool value)
{
  if(value)
  {
    SS1_SetHigh();
  }
  else
  {
    SS1_SetLow();
  }
}

#define IO_RA0_SetHigh()          ( LATASET = (1 << 0) )
/**
  @Summary
    Sets the GPIO pin, RA0, low using LATAbits.LATA0.

  @Description
    Sets the GPIO pin, RA0, low using LATAbits.LATA0.

  @Preconditions
    The RA0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA0 low (0)
    IO_RA0_SetLow();
    </code>

*/
#define IO_RA0_SetLow()           ( LATACLR = (1 << 0) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RA0, low or high using LATAbits.LATA0.

  @Preconditions
    The RA0 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RA0 to low.
    IO_RA0_SetValue(false);
    </code>

*/
inline static void IO_RA0_SetValue(bool value)
{
  if(value)
  {
    IO_RA0_SetHigh();
  }
  else
  {
    IO_RA0_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RA0, using LATAbits.LATA0.

  @Description
    Toggles the GPIO pin, RA0, using LATAbits.LATA0.

  @Preconditions
    The RA0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA0
    IO_RA0_Toggle();
    </code>

*/
#define IO_RA0_Toggle()           ( LATAINV = (1 << 0) )
/**
  @Summary
    Reads the value of the GPIO pin, RA0.

  @Description
    Reads the value of the GPIO pin, RA0.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA0
    postValue = IO_RA0_GetValue();
    </code>

*/
#define IO_RA0_GetValue()         PORTAbits.RA0
/**
  @Summary
    Configures the GPIO pin, RA0, as an input.

  @Description
    Configures the GPIO pin, RA0, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA0 as an input
    IO_RA0_SetDigitalInput();
    </code>

*/
#define IO_RA0_SetDigitalInput()   ( TRISASET = (1 << 0) )
/**
  @Summary
    Configures the GPIO pin, RA0, as an output.

  @Description
    Configures the GPIO pin, RA0, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA0 as an output
    IO_RA0_SetDigitalOutput();
    </code>

*/
#define IO_RA0_SetDigitalOutput()   ( TRISACLR = (1 << 0) )
/**
  @Summary
    Sets the GPIO pin, RA1, high using LATAbits.LATA1.

  @Description
    Sets the GPIO pin, RA1, high using LATAbits.LATA1.

  @Preconditions
    The RA1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA1 high (1)
    IO_RA1_SetHigh();
    </code>

*/
#define IO_RA1_SetHigh()          ( LATASET = (1 << 1) )
/**
  @Summary
    Sets the GPIO pin, RA1, low using LATAbits.LATA1.

  @Description
    Sets the GPIO pin, RA1, low using LATAbits.LATA1.

  @Preconditions
    The RA1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA1 low (0)
    IO_RA1_SetLow();
    </code>

*/
#define IO_RA1_SetLow()           ( LATACLR = (1 << 1) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RA1, low or high using LATAbits.LATA1.

  @Preconditions
    The RA1 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RA1 to low.
    IO_RA1_SetValue(false);
    </code>

*/
inline static void IO_RA1_SetValue(bool value)
{
  if(value)
  {
    IO_RA1_SetHigh();
  }
  else
  {
    IO_RA1_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RA1, using LATAbits.LATA1.

  @Description
    Toggles the GPIO pin, RA1, using LATAbits.LATA1.

  @Preconditions
    The RA1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA1
    IO_RA1_Toggle();
    </code>

*/
#define IO_RA1_Toggle()           ( LATAINV = (1 << 1) )
/**
  @Summary
    Reads the value of the GPIO pin, RA1.

  @Description
    Reads the value of the GPIO pin, RA1.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA1
    postValue = IO_RA1_GetValue();
    </code>

*/
#define IO_RA1_GetValue()         PORTAbits.RA1
/**
  @Summary
    Configures the GPIO pin, RA1, as an input.

  @Description
    Configures the GPIO pin, RA1, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA1 as an input
    IO_RA1_SetDigitalInput();
    </code>

*/
#define IO_RA1_SetDigitalInput()   ( TRISASET = (1 << 1) )
/**
  @Summary
    Configures the GPIO pin, RA1, as an output.

  @Description
    Configures the GPIO pin, RA1, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA1 as an output
    IO_RA1_SetDigitalOutput();
    </code>

*/
#define IO_RA1_SetDigitalOutput()   ( TRISACLR = (1 << 1) )
/**
  @Summary
    Sets the GPIO pin, RA2, high using LATAbits.LATA2.

  @Description
    Sets the GPIO pin, RA2, high using LATAbits.LATA2.

  @Preconditions
    The RA2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA2 high (1)
    IO_RA2_SetHigh();
    </code>

*/
#define IO_RA2_SetHigh()          ( LATASET = (1 << 2) )
/**
  @Summary
    Sets the GPIO pin, RA2, low using LATAbits.LATA2.

  @Description
    Sets the GPIO pin, RA2, low using LATAbits.LATA2.

  @Preconditions
    The RA2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA2 low (0)
    IO_RA2_SetLow();
    </code>

*/
#define IO_RA2_SetLow()           ( LATACLR = (1 << 2) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RA2, low or high using LATAbits.LATA2.

  @Preconditions
    The RA2 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RA2 to low.
    IO_RA2_SetValue(false);
    </code>

*/
inline static void IO_RA2_SetValue(bool value)
{
  if(value)
  {
    IO_RA2_SetHigh();
  }
  else
  {
    IO_RA2_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RA2, using LATAbits.LATA2.

  @Description
    Toggles the GPIO pin, RA2, using LATAbits.LATA2.

  @Preconditions
    The RA2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA2
    IO_RA2_Toggle();
    </code>

*/
#define IO_RA2_Toggle()           ( LATAINV = (1 << 2) )
/**
  @Summary
    Reads the value of the GPIO pin, RA2.

  @Description
    Reads the value of the GPIO pin, RA2.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA2
    postValue = IO_RA2_GetValue();
    </code>

*/
#define IO_RA2_GetValue()         PORTAbits.RA2
/**
  @Summary
    Configures the GPIO pin, RA2, as an input.

  @Description
    Configures the GPIO pin, RA2, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA2 as an input
    IO_RA2_SetDigitalInput();
    </code>

*/
#define IO_RA2_SetDigitalInput()   ( TRISASET = (1 << 2) )
/**
  @Summary
    Configures the GPIO pin, RA2, as an output.

  @Description
    Configures the GPIO pin, RA2, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA2 as an output
    IO_RA2_SetDigitalOutput();
    </code>

*/
#define IO_RA2_SetDigitalOutput()   ( TRISACLR = (1 << 2) )
/**
  @Summary
    Sets the GPIO pin, RA3, high using LATAbits.LATA3.

  @Description
    Sets the GPIO pin, RA3, high using LATAbits.LATA3.

  @Preconditions
    The RA3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA3 high (1)
    IO_RA3_SetHigh();
    </code>

*/
#define IO_RA3_SetHigh()          ( LATASET = (1 << 3) )
/**
  @Summary
    Sets the GPIO pin, RA3, low using LATAbits.LATA3.

  @Description
    Sets the GPIO pin, RA3, low using LATAbits.LATA3.

  @Preconditions
    The RA3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA3 low (0)
    IO_RA3_SetLow();
    </code>

*/
#define IO_RA3_SetLow()           ( LATACLR = (1 << 3) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RA3, low or high using LATAbits.LATA3.

  @Preconditions
    The RA3 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RA3 to low.
    IO_RA3_SetValue(false);
    </code>

*/
inline static void IO_RA3_SetValue(bool value)
{
  if(value)
  {
    IO_RA3_SetHigh();
  }
  else
  {
    IO_RA3_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RA3, using LATAbits.LATA3.

  @Description
    Toggles the GPIO pin, RA3, using LATAbits.LATA3.

  @Preconditions
    The RA3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA3
    IO_RA3_Toggle();
    </code>

*/
#define IO_RA3_Toggle()           ( LATAINV = (1 << 3) )
/**
  @Summary
    Reads the value of the GPIO pin, RA3.

  @Description
    Reads the value of the GPIO pin, RA3.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA3
    postValue = IO_RA3_GetValue();
    </code>

*/
#define IO_RA3_GetValue()         PORTAbits.RA3
/**
  @Summary
    Configures the GPIO pin, RA3, as an input.

  @Description
    Configures the GPIO pin, RA3, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA3 as an input
    IO_RA3_SetDigitalInput();
    </code>

*/
#define IO_RA3_SetDigitalInput()   ( TRISASET = (1 << 3) )
/**
  @Summary
    Configures the GPIO pin, RA3, as an output.

  @Description
    Configures the GPIO pin, RA3, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA3 as an output
    IO_RA3_SetDigitalOutput();
    </code>

*/
#define IO_RA3_SetDigitalOutput()   ( TRISACLR = (1 << 3) )
/**
  @Summary
    Sets the GPIO pin, RA4, high using LATAbits.LATA4.

  @Description
    Sets the GPIO pin, RA4, high using LATAbits.LATA4.

  @Preconditions
    The RA4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA4 high (1)
    IO_RA4_SetHigh();
    </code>

*/
#define IO_RA4_SetHigh()          ( LATASET = (1 << 4) )
/**
  @Summary
    Sets the GPIO pin, RA4, low using LATAbits.LATA4.

  @Description
    Sets the GPIO pin, RA4, low using LATAbits.LATA4.

  @Preconditions
    The RA4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA4 low (0)
    IO_RA4_SetLow();
    </code>

*/
#define IO_RA4_SetLow()           ( LATACLR = (1 << 4) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RA4, low or high using LATAbits.LATA4.

  @Preconditions
    The RA4 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RA4 to low.
    IO_RA4_SetValue(false);
    </code>

*/
inline static void IO_RA4_SetValue(bool value)
{
  if(value)
  {
    IO_RA4_SetHigh();
  }
  else
  {
    IO_RA4_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RA4, using LATAbits.LATA4.

  @Description
    Toggles the GPIO pin, RA4, using LATAbits.LATA4.

  @Preconditions
    The RA4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA4
    IO_RA4_Toggle();
    </code>

*/
#define IO_RA4_Toggle()           ( LATAINV = (1 << 4) )
/**
  @Summary
    Reads the value of the GPIO pin, RA4.

  @Description
    Reads the value of the GPIO pin, RA4.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA4
    postValue = IO_RA4_GetValue();
    </code>

*/
#define IO_RA4_GetValue()         PORTAbits.RA4
/**
  @Summary
    Configures the GPIO pin, RA4, as an input.

  @Description
    Configures the GPIO pin, RA4, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA4 as an input
    IO_RA4_SetDigitalInput();
    </code>

*/
#define IO_RA4_SetDigitalInput()   ( TRISASET = (1 << 4) )
/**
  @Summary
    Configures the GPIO pin, RA4, as an output.

  @Description
    Configures the GPIO pin, RA4, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA4 as an output
    IO_RA4_SetDigitalOutput();
    </code>

*/
#define IO_RA4_SetDigitalOutput()   ( TRISACLR = (1 << 4) )
/**
  @Summary
    Sets the GPIO pin, RB12, high using LATBbits.LATB12.

  @Description
    Sets the GPIO pin, RB12, high using LATBbits.LATB12.

  @Preconditions
    The RB12 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB12 high (1)
    IO_RB12_SetHigh();
    </code>

*/
#define IO_RB12_SetHigh()          ( LATBSET = (1 << 12) )
/**
  @Summary
    Sets the GPIO pin, RB12, low using LATBbits.LATB12.

  @Description
    Sets the GPIO pin, RB12, low using LATBbits.LATB12.

  @Preconditions
    The RB12 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB12 low (0)
    IO_RB12_SetLow();
    </code>

*/
#define IO_RB12_SetLow()           ( LATBCLR = (1 << 12) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RB12, low or high using LATBbits.LATB12.

  @Preconditions
    The RB12 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RB12 to low.
    IO_RB12_SetValue(false);
    </code>

*/
inline static void IO_RB12_SetValue(bool value)
{
  if(value)
  {
    IO_RB12_SetHigh();
  }
  else
  {
    IO_RB12_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RB12, using LATBbits.LATB12.

  @Description
    Toggles the GPIO pin, RB12, using LATBbits.LATB12.

  @Preconditions
    The RB12 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB12
    IO_RB12_Toggle();
    </code>

*/
#define IO_RB12_Toggle()           ( LATBINV = (1 << 12) )
/**
  @Summary
    Reads the value of the GPIO pin, RB12.

  @Description
    Reads the value of the GPIO pin, RB12.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB12
    postValue = IO_RB12_GetValue();
    </code>

*/
#define IO_RB12_GetValue()         PORTBbits.RB12
/**
  @Summary
    Configures the GPIO pin, RB12, as an input.

  @Description
    Configures the GPIO pin, RB12, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB12 as an input
    IO_RB12_SetDigitalInput();
    </code>

*/
#define IO_RB12_SetDigitalInput()   ( TRISBSET = (1 << 12) )
/**
  @Summary
    Configures the GPIO pin, RB12, as an output.

  @Description
    Configures the GPIO pin, RB12, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB12 as an output
    IO_RB12_SetDigitalOutput();
    </code>

*/
#define IO_RB12_SetDigitalOutput()   ( TRISBCLR = (1 << 12) )
/**
  @Summary
    Sets the GPIO pin, RB13, high using LATBbits.LATB13.

  @Description
    Sets the GPIO pin, RB13, high using LATBbits.LATB13.

  @Preconditions
    The RB13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB13 high (1)
    IO_RB13_SetHigh();
    </code>

*/
#define IO_RB13_SetHigh()          ( LATBSET = (1 << 13) )
/**
  @Summary
    Sets the GPIO pin, RB13, low using LATBbits.LATB13.

  @Description
    Sets the GPIO pin, RB13, low using LATBbits.LATB13.

  @Preconditions
    The RB13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB13 low (0)
    IO_RB13_SetLow();
    </code>

*/
#define IO_RB13_SetLow()           ( LATBCLR = (1 << 13) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RB13, low or high using LATBbits.LATB13.

  @Preconditions
    The RB13 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RB13 to low.
    IO_RB13_SetValue(false);
    </code>

*/
inline static void IO_RB13_SetValue(bool value)
{
  if(value)
  {
    IO_RB13_SetHigh();
  }
  else
  {
    IO_RB13_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RB13, using LATBbits.LATB13.

  @Description
    Toggles the GPIO pin, RB13, using LATBbits.LATB13.

  @Preconditions
    The RB13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB13
    IO_RB13_Toggle();
    </code>

*/
#define IO_RB13_Toggle()           ( LATBINV = (1 << 13) )
/**
  @Summary
    Reads the value of the GPIO pin, RB13.

  @Description
    Reads the value of the GPIO pin, RB13.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB13
    postValue = IO_RB13_GetValue();
    </code>

*/
#define IO_RB13_GetValue()         PORTBbits.RB13
/**
  @Summary
    Configures the GPIO pin, RB13, as an input.

  @Description
    Configures the GPIO pin, RB13, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB13 as an input
    IO_RB13_SetDigitalInput();
    </code>

*/
#define IO_RB13_SetDigitalInput()   ( TRISBSET = (1 << 13) )
/**
  @Summary
    Configures the GPIO pin, RB13, as an output.

  @Description
    Configures the GPIO pin, RB13, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB13 as an output
    IO_RB13_SetDigitalOutput();
    </code>

*/
#define IO_RB13_SetDigitalOutput()   ( TRISBCLR = (1 << 13) )
/**
  @Summary
    Sets the GPIO pin, RB2, high using LATBbits.LATB2.

  @Description
    Sets the GPIO pin, RB2, high using LATBbits.LATB2.

  @Preconditions
    The RB2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB2 high (1)
    IO_RB2_SetHigh();
    </code>

*/
#define IO_RB2_SetHigh()          ( LATBSET = (1 << 2) )
/**
  @Summary
    Sets the GPIO pin, RB2, low using LATBbits.LATB2.

  @Description
    Sets the GPIO pin, RB2, low using LATBbits.LATB2.

  @Preconditions
    The RB2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB2 low (0)
    IO_RB2_SetLow();
    </code>

*/
#define IO_RB2_SetLow()           ( LATBCLR = (1 << 2) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RB2, low or high using LATBbits.LATB2.

  @Preconditions
    The RB2 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RB2 to low.
    IO_RB2_SetValue(false);
    </code>

*/
inline static void IO_RB2_SetValue(bool value)
{
  if(value)
  {
    IO_RB2_SetHigh();
  }
  else
  {
    IO_RB2_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RB2, using LATBbits.LATB2.

  @Description
    Toggles the GPIO pin, RB2, using LATBbits.LATB2.

  @Preconditions
    The RB2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB2
    IO_RB2_Toggle();
    </code>

*/
#define IO_RB2_Toggle()           ( LATBINV = (1 << 2) )
/**
  @Summary
    Reads the value of the GPIO pin, RB2.

  @Description
    Reads the value of the GPIO pin, RB2.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB2
    postValue = IO_RB2_GetValue();
    </code>

*/
#define IO_RB2_GetValue()         PORTBbits.RB2
/**
  @Summary
    Configures the GPIO pin, RB2, as an input.

  @Description
    Configures the GPIO pin, RB2, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB2 as an input
    IO_RB2_SetDigitalInput();
    </code>

*/
#define IO_RB2_SetDigitalInput()   ( TRISBSET = (1 << 2) )
/**
  @Summary
    Configures the GPIO pin, RB2, as an output.

  @Description
    Configures the GPIO pin, RB2, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB2 as an output
    IO_RB2_SetDigitalOutput();
    </code>

*/
#define IO_RB2_SetDigitalOutput()   ( TRISBCLR = (1 << 2) )
/**
  @Summary
    Sets the GPIO pin, RB4, high using LATBbits.LATB4.

  @Description
    Sets the GPIO pin, RB4, high using LATBbits.LATB4.

  @Preconditions
    The RB4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB4 high (1)
    IO_RB4_SetHigh();
    </code>

*/
#define IO_RB4_SetHigh()          ( LATBSET = (1 << 4) )
/**
  @Summary
    Sets the GPIO pin, RB4, low using LATBbits.LATB4.

  @Description
    Sets the GPIO pin, RB4, low using LATBbits.LATB4.

  @Preconditions
    The RB4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB4 low (0)
    IO_RB4_SetLow();
    </code>

*/
#define IO_RB4_SetLow()           ( LATBCLR = (1 << 4) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RB4, low or high using LATBbits.LATB4.

  @Preconditions
    The RB4 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RB4 to low.
    IO_RB4_SetValue(false);
    </code>

*/
inline static void IO_RB4_SetValue(bool value)
{
  if(value)
  {
    IO_RB4_SetHigh();
  }
  else
  {
    IO_RB4_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RB4, using LATBbits.LATB4.

  @Description
    Toggles the GPIO pin, RB4, using LATBbits.LATB4.

  @Preconditions
    The RB4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB4
    IO_RB4_Toggle();
    </code>

*/
#define IO_RB4_Toggle()           ( LATBINV = (1 << 4) )
/**
  @Summary
    Reads the value of the GPIO pin, RB4.

  @Description
    Reads the value of the GPIO pin, RB4.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB4
    postValue = IO_RB4_GetValue();
    </code>

*/
#define IO_RB4_GetValue()         PORTBbits.RB4
/**
  @Summary
    Configures the GPIO pin, RB4, as an input.

  @Description
    Configures the GPIO pin, RB4, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB4 as an input
    IO_RB4_SetDigitalInput();
    </code>

*/
#define IO_RB4_SetDigitalInput()   ( TRISBSET = (1 << 4) )
/**
  @Summary
    Configures the GPIO pin, RB4, as an output.

  @Description
    Configures the GPIO pin, RB4, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB4 as an output
    IO_RB4_SetDigitalOutput();
    </code>

*/
#define IO_RB4_SetDigitalOutput()   ( TRISBCLR = (1 << 4) )

/**
    Section: Function Prototypes
*/
/**
  @Summary
    Configures the pin settings of the PIC32MM0064GPL020
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description
    This is the generated manager file for the MPLAB(c) Code Configurator device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    void SYSTEM_Initialize(void)
    {
        // Other initializers are called from this function
        PIN_MANAGER_Initialize();
    }
    </code>

*/
void PIN_MANAGER_Initialize(void);

#endif
