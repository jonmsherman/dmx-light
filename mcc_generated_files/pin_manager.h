/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
        Device            :  PIC16F18446
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.00
        MPLAB 	          :  MPLAB X 5.10	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set SDA1 aliases
#define SDA1_TRIS                 TRISAbits.TRISA4
#define SDA1_LAT                  LATAbits.LATA4
#define SDA1_PORT                 PORTAbits.RA4
#define SDA1_WPU                  WPUAbits.WPUA4
#define SDA1_OD                   ODCONAbits.ODCA4
#define SDA1_ANS                  ANSELAbits.ANSA4
#define SDA1_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define SDA1_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define SDA1_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define SDA1_GetValue()           PORTAbits.RA4
#define SDA1_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define SDA1_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define SDA1_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define SDA1_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define SDA1_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define SDA1_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define SDA1_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define SDA1_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set SCL1 aliases
#define SCL1_TRIS                 TRISAbits.TRISA5
#define SCL1_LAT                  LATAbits.LATA5
#define SCL1_PORT                 PORTAbits.RA5
#define SCL1_WPU                  WPUAbits.WPUA5
#define SCL1_OD                   ODCONAbits.ODCA5
#define SCL1_ANS                  ANSELAbits.ANSA5
#define SCL1_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define SCL1_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define SCL1_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define SCL1_GetValue()           PORTAbits.RA5
#define SCL1_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define SCL1_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define SCL1_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define SCL1_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define SCL1_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define SCL1_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define SCL1_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define SCL1_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set RB6 procedures
#define RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define RB6_GetValue()              PORTBbits.RB6
#define RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define RB6_SetPullup()             do { WPUBbits.WPUB6 = 1; } while(0)
#define RB6_ResetPullup()           do { WPUBbits.WPUB6 = 0; } while(0)
#define RB6_SetAnalogMode()         do { ANSELBbits.ANSB6 = 1; } while(0)
#define RB6_SetDigitalMode()        do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set channel_ANB7 aliases
#define channel_ANB7_TRIS                 TRISBbits.TRISB7
#define channel_ANB7_LAT                  LATBbits.LATB7
#define channel_ANB7_PORT                 PORTBbits.RB7
#define channel_ANB7_WPU                  WPUBbits.WPUB7
#define channel_ANB7_OD                   ODCONBbits.ODCB7
#define channel_ANB7_ANS                  ANSELBbits.ANSB7
#define channel_ANB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define channel_ANB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define channel_ANB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define channel_ANB7_GetValue()           PORTBbits.RB7
#define channel_ANB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define channel_ANB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define channel_ANB7_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define channel_ANB7_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define channel_ANB7_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define channel_ANB7_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define channel_ANB7_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define channel_ANB7_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/