/**
 * @file    MTIMER_private.h
 * @author  Ahmed Ashraf (ahmedashrafelnaqeeb@gmail.com)
 * @brief   This file contains private information related to Timer module
 * @version 1.0
 * @date    2022-10-08
 * 
 * 
 */

/*Header file guard*/
#ifndef __MTIMER_PRIVATE_H__
#define __MTIMER_PRIVATE_H__

/***************************************************************************************************/
/*                                        Timer Registers                                          */
/***************************************************************************************************/

/*General timer registers*/
#define MTIMER_TIMSK             (*(volatile u8_t*)(0x59))
#define MTIMER_TIFR              (*(volatile u8_t*)(0x58))

/*Timer0 registers*/
#define MTIMER_TCCR0             (*(volatile u8_t*)(0x53))
#define MTIMER_TCNT0             (*(volatile u8_t*)(0x52))
#define MTIMER_OCR0              (*(volatile u8_t*)(0x5C))

/***************************************************************************************************/
/*                                       Timer Registers' bits                                      */
/***************************************************************************************************/

/*TIFR bits*/
#define MTIMER_TIFR_OCF0_BIT     (1)

/*TIMSK bits*/
#define MTIMER_TIMSK_OCIE0_BIT   (1)

#endif /*__MTIMER_PRIVATE_H__*/