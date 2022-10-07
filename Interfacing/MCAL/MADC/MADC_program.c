/**
 * @file    MADC_program.c
 * @author  Ahmed Ashraf (ahmedashrafelnaqeeb@gmail.com)
 * @brief   This file contains logical implementation related to ADC module
 * @version 1.0
 * @date    2022-10-07
 * 
 * 
 */

/***************************************************************************************************/
/*                                             Includes                                            */
/***************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MADC_private.h"
#include "MADC_interface.h"

/***************************************************************************************************/
/*                                        Important macros                                         */
/***************************************************************************************************/

/*ADC operations*/
#define ADC_ENABLE            (0x80)
#define CHANNEL_CLEAR         (0xE0)

/*Bit manipulation*/
#define SHIFT_LEFT_5          (5)
#define SHIFT_LEFT_6          (6)

/***************************************************************************************************/
/*                                        Important variables                                      */
/***************************************************************************************************/

/***************************************************************************************************/
/*                                       Functions' definitions                                    */
/***************************************************************************************************/

void madc_init(u8_t au8_voltageReference, u8_t au8_conversionMode, u8_t au8_prescaler)
{
    /*Setting the voltage reference and conversion mode*/
    MADC_ADMUX = (au8_voltageReference << SHIFT_LEFT_6) | (au8_conversionMode << SHIFT_LEFT_5);

    /*Enabling the ADC and setting the presacler value*/
    MADC_ADCSRA = ADC_ENABLE | (au8_prescaler);

    /*Return from this function*/
    return;
}

void madc_singleConversion(u8_t au8_channel, u16_t* pu16_adcValue)
{
    /*Clearing channel bits*/
    MADC_ADMUX &= CHANNEL_CLEAR;

    /*Setting the selected ADC channel*/
    MADC_ADMUX |= au8_channel;

    /*Starting ADC conversion*/
    SET_BIT(MADC_ADCSRA, MADC_ADCSRA_ADSC_BIT);

    /*Waiting until the ADC finishes the conversion*/
    while(!GET_BIT(MADC_ADCSRA, MADC_ADCSRA_ADIF_BIT));

    /*Clearing ADC flag bit*/
    SET_BIT(MADC_ADCSRA, MADC_ADCSRA_ADIF_BIT);

    /*Checking if the left adjustment bit is enabled or not*/
    if(GET_BIT(MADC_ADMUX, MADC_ADMUX_ADLAR_BIT) == ADC_8_BITS)
    {
        /*Reading ADC high register*/
        *pu16_adcValue = (u16_t)MADC_ADCH;
    }
    else
    {
        /*Reading full ADC value (10-bits)*/
        *pu16_adcValue = MADC_ADC;
    }

    /*Return from this function*/
    return;
}
