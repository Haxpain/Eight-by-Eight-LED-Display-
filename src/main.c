/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

#include "config/default/peripheral/tmr1/plib_tmr1.h"
#include "config/default/peripheral/gpio/plib_gpio.h"

#include "MAX7219.h"

#define DISPLAYS 8

volatile bool bTriggered = false ;

void onTick(unsigned int state, unsigned int context)
{
     bTriggered = true ;
     
}

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main ( void )
{
    
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
    TMR1_CallbackRegister(onTick,1) ;
    
    TMR1_Start() ;
    
    MAX7219_init(DISPLAYS) ;
    
    MAX7219_displayText("HOMETIME") ;
    
    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );

        
        if (bTriggered == true)
        {
            bTriggered = false ;
            
            GPIO_LED_Toggle() ;
            
            //MAX7219_dropText("GREATEST") ;
           
            
        }
        
        
        WDT_Clear() ;
        
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}

/*******************************************************************************
 End of File
*/

