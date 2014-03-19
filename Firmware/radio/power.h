//-----------------------------------------------------------------------------
// power.h
//-----------------------------------------------------------------------------
// Copyright (C) 2009 Silicon Laboratories, Inc.
// http://www.silabs.com
//
// Program Description:
//
// Driver for the 'F93x power management function.
//
// Target:         C8051F93x-C8051F90x
// Tool chain:     Generic
// Command Line:   None
//
// Release 1.0
//    -23 JUL 2009
//

//-----------------------------------------------------------------------------
// Register and Bit Definitions
//-----------------------------------------------------------------------------

// Power Management Bit Definitions
#define SLEEP        0x80              // Sleep Mode Select
#define SUSPEND      0x40              // Suspend Mode Select
#define CLEAR        0x20              // Wake-Up Flag Clear
#define RSTWK        0x10              // Reset Pin Falling Edge Wake-Up
#define RTCFWK       0x08              // SmaRTClock Failure Wake-Up
#define RTCAWK       0x04              // SmaRTClock Alarm Wake-Up
#define PMATWK       0x02              // Port Match Wake-Up
#define CPT0WK       0x01              // Comparator0 Wake-Up

// Friendly names for the LPM function arguments
#define PORT_MATCH   PMATWK


// FLSCL Bit Definition
#define BYPASS    0x40
#define NON_ZERO  0x01



//-----------------------------------------------------------------------------
// Extern Function PROTOTYPES
//-----------------------------------------------------------------------------
extern void LPM_Init (void);

extern void LPM_Sleep (void);
