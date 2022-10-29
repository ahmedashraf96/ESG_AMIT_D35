/**
 * @file    MSPI_private.h
 * @author  Ahmed Ashraf (ahmedashrafelnaqeeb@gmail.com)
 * @brief   This file contains private information related to SPI module
 * @version 1.0
 * @date    2022-10-29
 * 
 * 
 */

/*Header file guard*/
#ifndef __MSPI_PRIVATE_H__
#define __MSPI_PRIVATE_H__

/***************************************************************************************************/
/*                                         SPI Registers                                          */
/***************************************************************************************************/

#define MSPI_SPDR              (*(volatile u8_t*)(0x2F))
#define MSPI_SPSR              (*(volatile u8_t*)(0x2E))
#define MSPI_SPCR              (*(volatile u8_t*)(0x2D))

/***************************************************************************************************/
/*                                       SPI Registers' bits                                      */
/***************************************************************************************************/

/*SPCR bits*/
#define MSPI_SPCR_DORD_BIT     (5)
#define MSPI_SPCR_MSTR_BIT     (4)
#define MSPI_SPCR_CPOL_BIT     (3)
#define MSPI_SPCR_CPHA_BIT     (2)

/*SPSR bits*/
#define MSPI_SPSR_SPIF_BIT     (7)
#define MSPI_SPSR_SPI2X_BIT    (0)

#endif /*__MSPI_PRIVATE_H__*/