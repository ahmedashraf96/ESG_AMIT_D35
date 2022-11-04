/**
 * @file    MTWI_private.h
 * @author  Ahmed Ashraf (ahmedashrafelnaqeeb@gmail.com)
 * @brief   This file contains private information related to TWI module
 * @version 1.0
 * @date    2022-11-04
 * 
 * 
 */

/*Header file guard*/
#ifndef __MTWI_PRIVATE_H__
#define __MTWI_PRIVATE_H__

/***************************************************************************************************/
/*                                         TWI Registers                                           */
/***************************************************************************************************/

#define  MTWI_TWBR                       (*(volatile u8_t*)(0x20))
#define  MTWI_TWSR                       (*(volatile u8_t*)(0x21))
#define  MTWI_TWAR                       (*(volatile u8_t*)(0x22))
#define  MTWI_TWDR                       (*(volatile u8_t*)(0x23))
#define  MTWI_TWCR                       (*(volatile u8_t*)(0x56))

/***************************************************************************************************/
/*                                       TWI Registers' bits                                       */
/***************************************************************************************************/

/*TWCR bits*/
#define MTWI_TWCR_TWINT_BIT              (7)
#define MTWI_TWCR_TWEA_BIT               (6)
#define MTWI_TWCR_TWSTA_BIT              (5)
#define MTWI_TWCR_TWSTO_BIT              (4)
#define MTWI_TWCR_TWEN_BIT               (2)

#endif /*__MTWI_PRIVATE_H__*/