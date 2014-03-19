//-----------------------------------------------------------------------------
// power.c
//-----------------------------------------------------------------------------
// Copyright (C) 2009 Silicon Laboratories, Inc.
// http://www.silabs.com
//
// Program Description:
//
// Driver for the 'F93x power management function.
//
// Target:         C8051F93x-C8051F92x
// Tool chain:     Generic
// Command Line:   None
//
// Release 1.0
//    -23 JUL 2009
//

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <stdarg.h>
#include "board.h"
#include "power.h"


//-----------------------------------------------------------------------------
// LPM_Init ()
//-----------------------------------------------------------------------------
//
// Return Value : None
// Parameters   : None
//
// This function will initialize the low power functionality
//
//-----------------------------------------------------------------------------
void LPM_Init (void)
{
  PMU0CF = CLEAR;
  P1MASK = 0x00;
  P0MASK = 0x08;
  P0MAT = 0xFF;
}



//-----------------------------------------------------------------------------
// LPM
//-----------------------------------------------------------------------------
//
// Return Value : none
// Parameters   : 1) U8 mode -- can be SLEEP or SUSPEND
//
// This function places the device in a low power mode
//
//-----------------------------------------------------------------------------
void LPM_Sleep (void)
{
   
   // Save current system clock selection and select the low power oscillator
   // divided by 2 as the system clock
   CLKSEL = 0x14;
   
   // Enable the Flash read one-shot timer   
   FLSCL &= ~BYPASS;                   // Clear the one-shot bypass bit
   FLWR  =   NON_ZERO;                 // Write a "dummy" value to FLWR
   
   // Verify that the system clock setting has been applied
   while(!(CLKSEL & 0x80));            // Wait until CLKRDY -> 1
   

   //----------------------------------
   // ~~~ Device in Low Power Mode ~~~
   //
       PMU0CF = (SLEEP | PORT_MATCH);
  __asm
  NOP
  NOP
  NOP
  __endasm;
   //
   // ~~~   Device is now Awake    ~~~
   //----------------------------------
   
   //RESET
    RSTSRC |= (1 << 4);
        for (;;)
          ;
          

    
}               

 