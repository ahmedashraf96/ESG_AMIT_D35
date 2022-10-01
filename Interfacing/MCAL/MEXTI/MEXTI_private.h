/**
 * @file    MEXTI_private.h
 * @author  Ahmed Ashraf (ahmedashrafelnaqeeb@gmail.com)
 * @brief   This file contains private information related to EXTI module
 * @version 1.0
 * @date    2022-10-01
 * 
 * 
 */

/*Header file guard*/
#ifndef __MEXTI_PRIVATE_H__
#define __MEXTI_PRIVATE_H__

/***************************************************************************************************/
/*                                         EXTI Registers                                          */
/***************************************************************************************************/

#define MEXTI_MCUCSR                    (*(volatile u8_t*)(0x54))
#define MEXTI_MCUCR                     (*(volatile u8_t*)(0x55))
#define MEXTI_GIFR                      (*(volatile u8_t*)(0x5A))
#define MEXTI_GICR                      (*(volatile u8_t*)(0x5B))

/***************************************************************************************************/
/*                                       EXTI Registers' bits                                      */
/***************************************************************************************************/

/*GICR bits*/
#define MEXTI_GICR_INT0_BIT             (6)
#define MEXTI_GICR_INT1_BIT             (7)
#define MEXTI_GICR_INT2_BIT             (5)

/*MCUCSR bits*/
#define MEXTI_MCUCSR_ISC2_BIT           (6)

#endif /*__MEXTI_PRIVATE_H__*/