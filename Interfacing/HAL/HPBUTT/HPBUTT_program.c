/**
 * @file    HPBUTT_program.c
 * @author  Ahmed Ashraf (ahmedashrafelnaqeeb@gmail.com)
 * @brief   This file contains logical implementation related to Push button module
 * @version 1.0
 * @date    2022-09-17
 * 
 * 
 */

/***************************************************************************************************/
/*                                             Includes                                            */
/***************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "HPBUTT_cfg.h"
#include "HPBUTT_interface.h"


/***************************************************************************************************/
/*                                       Functions' definitions                                    */
/***************************************************************************************************/

void hpbutt_init(u8_t au8_pbNumber)
{
    switch(au8_pbNumber)
    {
        /*In case of push button 0*/
        case PUSH_BUTTON_0:

            /*Setting the PB0 as input*/
            mdio_setPinStatus(PB0_PORT, PB0_PIN, INPUT_FLOAT);

            /*Break from this case*/
            break;

        /*In case of push button 1*/
        case PUSH_BUTTON_1:

            /*Setting the PB1 as input*/
            mdio_setPinStatus(PB1_PORT, PB1_PIN, INPUT_FLOAT);

            /*Break from this case*/
            break;

        /*In case of push button 2*/
        case PUSH_BUTTON_2:

            /*Setting the PB2 as input*/
            mdio_setPinStatus(PB2_PORT, PB2_PIN, INPUT_FLOAT);

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

void hpbutt_getStatus(u8_t au8_pbNumber, u8_t* pu8_pbStatus)
{
    switch(au8_pbNumber)
    {
        /*In case of push button 0*/
        case PUSH_BUTTON_0:

            /*Getting the PB0 status*/
            mdio_getPinValue(PB0_PORT, PB0_PIN, pu8_pbStatus);

            /*Break from this case*/
            break;

        /*In case of push button 1*/
        case PUSH_BUTTON_1:

            /*Getting the PB1 status*/
            mdio_getPinValue(PB1_PORT, PB1_PIN, pu8_pbStatus);

            /*Break from this case*/
            break;

        /*In case of push button 2*/
        case PUSH_BUTTON_2:

            /*Getting the PB2 status*/
            mdio_getPinValue(PB2_PORT, PB2_PIN, pu8_pbStatus);

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
