/**
 * @file    HEEP_cfg.h
 * @author  Ahmed Ashraf (ahmedashrafelnaqeeb@gmail.com)
 * @brief   This file contains configuration information related to EEPROM module
 * @version 1.0
 * @date    2022-11-25
 * 
 * 
 */

/*Header file guard*/
#ifndef __HEEP_CFG_H__
#define __HEEP_CFG_H__

/***************************************************************************************************/
/*                                         Configuration macros                                    */
/***************************************************************************************************/

/*EEPROM TWI base communication address*/
#define EEPROM_SLAVE_ADDRESS_BASE    (0x50)

/*EEPROM blocks*/
#define BLOCK_0                      (EEPROM_SLAVE_ADDRESS_BASE | 0)
#define BLOCK_1                      (EEPROM_SLAVE_ADDRESS_BASE | 1)
#define BLOCK_2                      (EEPROM_SLAVE_ADDRESS_BASE | 2)
#define BLOCK_3                      (EEPROM_SLAVE_ADDRESS_BASE | 3)
#define BLOCK_4                      (EEPROM_SLAVE_ADDRESS_BASE | 4)
#define BLOCK_5                      (EEPROM_SLAVE_ADDRESS_BASE | 5)
#define BLOCK_6                      (EEPROM_SLAVE_ADDRESS_BASE | 6)
#define BLOCK_7                      (EEPROM_SLAVE_ADDRESS_BASE | 7)

/*EEPROM page size*/
#define EEPROM_PAGE_SIZE             (16)

#endif /*__HEEP_CFG_H__*/