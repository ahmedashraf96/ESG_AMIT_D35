/**
 * @file    HKPD_program.c
 * @author  Ahmed Ashraf (ahmedashrafelnaqeeb@gmail.com)
 * @brief   This file contains logical implementation related to Keypad module
 * @version 1.0
 * @date    2022-09-24
 * 
 * 
 */

/***************************************************************************************************/
/*                                             Includes                                            */
/***************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "HKPD_cfg.h"
#include "HKPD_interface.h"
#include "util/delay.h"

/***************************************************************************************************/
/*                                          Important macros                                       */
/***************************************************************************************************/

#define DEBOUNCE_TIME_MS      (250)

/***************************************************************************************************/
/*                                          Important variables                                    */
/***************************************************************************************************/

/*Static global 2-D Array used to store the mapping of the keypad*/
static u8_t garr_keypadMapping[KPD_NUM_ROWS][KPD_NUM_COLS] = KEYPAD_MAPPING;

/***************************************************************************************************/
/*                                       Functions' definitions                                    */
/***************************************************************************************************/

void hkpd_init(void)
{
    /*Setting the rows as input pullup*/
    mdio_setPinStatus(KPD_PORT, (KPD_ROW0 | KPD_ROW1 | KPD_ROW2| KPD_ROW3), INPUT_PULLUP);

    /*Setting the columns as output*/
    mdio_setPinStatus(KPD_PORT, (KPD_COL0 | KPD_COL1 | KPD_COL2 | KPD_COL3), OUTPUT);

    /*Setting the columns as output high*/
    mdio_setPinValue(KPD_PORT, (KPD_COL0 | KPD_COL1 | KPD_COL2 | KPD_COL3), HIGH);

    /*Return from this function*/
    return;
}

void hkpd_getPressedButton(u8_t* pu8_button)
{
    /*Local variable used to track the columns*/
    u8_t au8_column;

    /*Local variable used to track the rows*/
    u8_t au8_row;

    /*Local variable used to hold the DIO pin status*/
    u8_t au8_returnValue;

    /*Setting the default value*/
    *pu8_button = KPD_DEFAULT_VALUE;

    /*Looping over keypad columns*/
    for(au8_column = 0; au8_column < KPD_NUM_COLS; au8_column++)
    {
        /*Settting the column value with low*/
        mdio_setPinValue(KPD_PORT, (KPD_COL0 << au8_column), LOW);

        /*Looping over keypad rows*/
        for(au8_row = 0; au8_row < KPD_NUM_ROWS; au8_row++)
        {
            /*Getting the row pin value*/
            mdio_getPinValue(KPD_PORT, (KPD_ROW0 << au8_row), &au8_returnValue);

            /*Checking if the row pin value equals low or not*/
            if(au8_returnValue == LOW)
            {
                /*Delay to avoid debouncing*/
                _delay_ms(DEBOUNCE_TIME_MS);

                /*Getting the pressed key value*/
                *pu8_button = garr_keypadMapping[au8_row][au8_column];

                /*Breaking from the loop*/
                break;
            }
            else
            {
                /*Do nothing*/
            }
        }

        /*Settting the column value with high*/
        mdio_setPinValue(KPD_PORT, (KPD_COL0 << au8_column), HIGH);
        
        /*Checking if there's a pressed key or not*/
        if(*pu8_button != KPD_DEFAULT_VALUE)
        {
            /*Breaking from the loop*/
            break;
        }
        else
        {
            /*Do nothing*/
        }
    }

    /*Return from this function*/
    return;
}
