/**
 * @file    MEXTI_program.c
 * @author  Ahmed Ashraf (ahmedashrafelnaqeeb@gmail.com)
 * @brief   This file contains logical implementation related to EXTI module
 * @version 1.0
 * @date    2022-10-01
 * 
 * 
 */

/***************************************************************************************************/
/*                                             Includes                                            */
/***************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "avr/interrupt.h"
#include "MEXTI_private.h"
#include "MEXTI_interface.h"

/***************************************************************************************************/
/*                                        Important macros                                         */
/***************************************************************************************************/

/*Null address*/
#define NULL                       ((void*)0)

/*INT0 and INT1 modes clearing masks*/
#define INT0_MODE_CLEAR_MASK       (0xFC)
#define INT1_MODE_CLEAR_MASK       (0xF3)

/*Arithmetic operations*/
#define SHIFT_LEFT_BY_2            (2)

/***************************************************************************************************/
/*                                        Important variables                                      */
/***************************************************************************************************/

/*External interrupts' function to pointers (ISRs)*/
static void (*fptr_int0Isr)(void) = NULL;
static void (*fptr_int1Isr)(void) = NULL;
static void (*fptr_int2Isr)(void) = NULL;

/***************************************************************************************************/
/*                                       Functions' definitions                                    */
/***************************************************************************************************/

void mexti_enableExternalInterrupt(u8_t au8_interruptNumber)
{
    /*Switching over interrupt numbers*/
    switch(au8_interruptNumber)
    {
        /*In case of INT0 number*/
        case INT0_REQ_NUM:

            /*Setting the INT0 bit*/
            SET_BIT(MEXTI_GICR, MEXTI_GICR_INT0_BIT);

            /*Break from this case*/
            break;

        /*In case of INT1 number*/
        case INT1_REQ_NUM:

            /*Setting the INT1 bit*/
            SET_BIT(MEXTI_GICR, MEXTI_GICR_INT1_BIT);

            /*Break from this case*/
            break;

        /*In case of INT2 number*/
        case INT2_REQ_NUM:

            /*Setting the INT2 bit*/
            SET_BIT(MEXTI_GICR, MEXTI_GICR_INT2_BIT);

            /*Break from this case*/
            break;

        /*In case of default*/
        default:

            /*Break from this case*/
            break;
    }

    /*Return from this function*/
    return;
}

void mexti_disableExternalInterrupt(u8_t au8_interruptNumber)
{
    /*Switching over interrupt numbers*/
    switch(au8_interruptNumber)
    {
        /*In case of INT0 number*/
        case INT0_REQ_NUM:

            /*Clearing the INT0 bit*/
            CLEAR_BIT(MEXTI_GICR, MEXTI_GICR_INT0_BIT);

            /*Break from this case*/
            break;

        /*In case of INT1 number*/
        case INT1_REQ_NUM:

            /*Clearing the INT1 bit*/
            CLEAR_BIT(MEXTI_GICR, MEXTI_GICR_INT1_BIT);

            /*Break from this case*/
            break;

        /*In case of INT2 number*/
        case INT2_REQ_NUM:

            /*Clearing the INT2 bit*/
            CLEAR_BIT(MEXTI_GICR, MEXTI_GICR_INT2_BIT);

            /*Break from this case*/
            break;

        /*In case of default*/
        default:

            /*Break from this case*/
            break;
    }

    /*Return from this function*/
    return;
}

void mexti_attachISR(u8_t au8_interruptNumber, u8_t au8_interruptMode, void (*fptr_isrFunction)(void))
{
    /*Switching over interrupt numbers*/
    switch(au8_interruptNumber)
    {
        /*In case of INT0 number*/
        case INT0_REQ_NUM:
            
            /*Clearing INT0 mode bits*/
            MEXTI_MCUCR &= INT0_MODE_CLEAR_MASK;

            /*Setting INT0 mode*/
            MEXTI_MCUCR |= au8_interruptMode;

            /*Getting the ISR function address*/
            fptr_int0Isr = fptr_isrFunction;

            /*Break from this case*/
            break;

        /*In case of INT1 number*/
        case INT1_REQ_NUM:

            /*Clearing INT1 mode bits*/
            MEXTI_MCUCR &= INT1_MODE_CLEAR_MASK;

            /*Setting INT1 mode*/
            MEXTI_MCUCR |= (au8_interruptMode << SHIFT_LEFT_BY_2);

            /*Getting the ISR function address*/
            fptr_int1Isr = fptr_isrFunction;

            /*Break from this case*/
            break;

        /*In case of INT2 number*/
        case INT2_REQ_NUM:

            /*Checking if the interrupt mode is rising or falling*/
            if(au8_interruptMode == RISING_EDGE_MODE)
            {
                /*Setting the rising edge mode*/
                SET_BIT(MEXTI_MCUCSR, MEXTI_MCUCSR_ISC2_BIT);
            }
            else if(au8_interruptMode == FALLING_EDGE_MODE)
            {
                /*Setting the falling edge mode*/
                CLEAR_BIT(MEXTI_MCUCSR, MEXTI_MCUCSR_ISC2_BIT);
            }
            else
            {
                /*Do nothing*/
            }

            /*Getting the ISR function address*/
            fptr_int2Isr = fptr_isrFunction;

            /*Break from this case*/
            break;

        /*In case of default*/
        default:

            /*Break from this case*/
            break;
    }

    /*Return from this function*/
    return;
}

/***************************************************************************************************/
/*                                              ISRs                                               */
/***************************************************************************************************/

/*INT0 ISR*/
ISR(INT0_vect)
{
    /*Checking if the passed function address isn't NULL*/
    if(fptr_int0Isr != NULL)
    {
        /*Calling INT0 callback function*/
        fptr_int0Isr();
    }
    else
    {
        /*Do nothing*/
    }
}

/*INT1 ISR*/
ISR(INT1_vect)
{
    /*Checking if the passed function address isn't NULL*/
    if(fptr_int1Isr != NULL)
    {
        /*Calling INT1 callback function*/
        fptr_int1Isr();
    }
    else
    {
        /*Do nothing*/
    }    
}

/*INT2 ISR*/
ISR(INT2_vect)
{
    /*Checking if the passed function address isn't NULL*/
    if(fptr_int2Isr != NULL)
    {
        /*Calling INT2 callback function*/
        fptr_int2Isr();
    }
    else
    {
        /*Do nothing*/
    }    
}
