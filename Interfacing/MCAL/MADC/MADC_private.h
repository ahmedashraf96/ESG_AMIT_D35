/**
 * @file    MADC_private.h
 * @author  Ahmed Ashraf (ahmedashrafelnaqeeb@gmail.com)
 * @brief   This file contains private information related to ADC module
 * @version 1.0
 * @date    2022-10-07
 * 
 * 
 */

/*Header file guard*/
#ifndef __MADC_PRIVATE_H__
#define __MADC_PRIVATE_H__

/***************************************************************************************************/
/*                                         ADC Registers                                           */
/***************************************************************************************************/

#define MADC_ADMUX                 (*(volatile u8_t*)(0x27))
#define MADC_ADCSRA                (*(volatile u8_t*)(0x26))
#define MADC_ADCH                  (*(volatile u8_t*)(0x25))
#define MADC_ADCL                  (*(volatile u8_t*)(0x24))
#define MADC_ADC                   (*(volatile u16_t*)(0x24))

/***************************************************************************************************/
/*                                       ADC Registers' bits                                       */
/***************************************************************************************************/

/*ADMUX register*/
#define MADC_ADMUX_ADLAR_BIT           (5)

/*ADCSRA register*/
#define MADC_ADCSRA_ADSC_BIT           (6)
#define MADC_ADCSRA_ADIF_BIT           (4)

#endif /*__MADC_PRIVATE_H__*/