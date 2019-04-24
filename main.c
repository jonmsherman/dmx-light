/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
        Device            :  PIC16F18446
        Driver Version    :  2.00
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
#include <stdbool.h>
#include "mcc_generated_files/mcc.h"
#include "clock.h"
#include "tm1650.h"
#include "buttons.h"
#include "controller.h"
#include "beat.h"
#include "ledblink.h"

#pragma config WDTE = OFF

/*
                         Main application
 */

uint8_t DMXFrame[514];
uint16_t currentDMXSlot = 0;

void DMXFrameISR();
void LED_init();
void LED_setColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t white);

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    __delay_ms(500);
//    EUSART1_SetRxInterruptHandler(DMXFrameISR);
    CLOCK_init();
    
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();
   
    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

//    LED_init();
    TM1650_init();
    BUTTONS_init();
    CONTROLLER_init();
    BEAT_init();
    LEDBlink_init();
    LED_init();
    while (1)
    {
        BUTTONS_task();
        CONTROLLER_task();
        BEAT_task();
        LEDBlink_task();
        LED_setColor(255,255,255,255);

//        LED_setColor(DMXFrame[2],DMXFrame[3],DMXFrame[4],DMXFrame[5]);
        // Add your application code
    }
}

void DMXFrameISR()
{
    // If framing error, this is a new DMX frame
    if(RC1STAbits.FERR){
        currentDMXSlot = 0;
    }
    
    // If overflow error, restart UART peripheral
    if(RC1STAbits.OERR){
        RC1STAbits.CREN = 0;
        RC1STAbits.CREN = 1;
    }
    
    DMXFrame[currentDMXSlot++] = RC1REG;


}

void LED_init()
{
    T2CLKCON = 0x01; // see Table 27-1 for details

    T2CONbits.ON = 1; // turn on Timer2

    CCP1CONbits.CCP1EN = 1; // enable CCP1 register
    CCP1CONbits.MODE = 0b1100; // set to PWM mode
    
    CCP2CONbits.CCP2EN = 1; // enable CCP2 register
    CCP2CONbits.MODE = 0b1100; // set to PWM mode
    
    CCP3CONbits.CCP3EN = 1; // enable CCP3 register
    CCP3CONbits.MODE = 0b1100; // set to PWM mode
    
    CCP4CONbits.CCP4EN = 1; // enable CCP3 register
    CCP4CONbits.MODE = 0b1100; // set to PWM mode
    
    RC3PPSbits.RC3PPS = 0x0B; // route CCP1 to RC3 (blue)
    RC6PPSbits.RC6PPS = 0x0A; // route CCP2 to RC6 (green)
    RC7PPSbits.RC7PPS = 0x09; // route CCP3 to RC7 (red)
    RC4PPSbits.RC4PPS = 0x0C; // route CCP4 to RC4 (white)

    TRISCbits.TRISC3 = 0; // make RC3 (blue) an output
    TRISCbits.TRISC6 = 0; // make RC6 (green) an output
    TRISCbits.TRISC7 = 0; // make RC7 (red) an output
    TRISCbits.TRISC4 = 0; // make RC4 (white) an output


}

void LED_setColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t white)
{
    
    CCPR1H = 0x00;
    CCPR1L = (red / 2);
    
    CCPR2H = 0x00;
    CCPR2L = (green / 2);
   
    CCPR3H = 0x00;
    CCPR3L = (blue / 2);
    
    CCPR4H = 0x00;
    CCPR4L = (white / 2);

}

/**
 End of File
*/