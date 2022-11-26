/**
 * @file    STTS_private.h
 * @author  Ahmed Ashraf (ahmedashrafelnaqeeb@gmail.com)
 * @brief   This file contains private information related to Time Triggered System (TTS) module
 * @version 1.0
 * @date    2022-11-26
 * 
 * 
 */

/*Header file guard*/
#ifndef __STTS_PRIVATE_H__
#define __STTS_PRIVATE_H__

/***************************************************************************************************/
/*                                         TTS Timer Registers                                     */
/***************************************************************************************************/

/*General timer registers*/
#define MTIMER_TIMSK             (*(volatile u8_t*)(0x59))
#define MTIMER_TIFR              (*(volatile u8_t*)(0x58))

/*Timer1 registers*/
#define MTIMER_TCCR1             (*(volatile u16_t*)(0x4E))
#define MTIMER_TCNT1             (*(volatile u16_t*)(0x4C))
#define MTIMER_OCR1A             (*(volatile u16_t*)(0x4A))
#define MTIMER_OCR1B             (*(volatile u16_t*)(0x48))
#define MTIMER_ICR1              (*(volatile u16_t*)(0x46))

/***************************************************************************************************/
/*                                       Timer Registers' bits                                     */
/***************************************************************************************************/

/*TIMSK bits*/
#define MTIMER_TIMSK_OCIE1A_BIT  (4)

#endif /*__STTS_PRIVATE_H__*/