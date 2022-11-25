/**
 * @file    HEEP_interface.h
 * @author  Ahmed Ashraf (ahmedashrafelnaqeeb@gmail.com)
 * @brief   This file contains interfacing information related to EEPROM module
 * @version 1.0
 * @date    2022-11-25
 * 
 * 
 */

/*Header file guard*/
#ifndef __HEEP_INTERFACE_H__
#define __HEEP_INTERFACE_H__

/***************************************************************************************************/
/*                                         Interfacing macros                                      */
/***************************************************************************************************/

/*EEPROM interfacing blocks*/
#define EEPROM_BLOCK_0         (0)
#define EEPROM_BLOCK_1         (1)
#define EEPROM_BLOCK_2         (2)
#define EEPROM_BLOCK_3         (3)
#define EEPROM_BLOCK_4         (4)
#define EEPROM_BLOCK_5         (5)
#define EEPROM_BLOCK_6         (6)
#define EEPROM_BLOCK_7         (7)

/***************************************************************************************************/
/*                                        Functions' prototypes                                    */
/***************************************************************************************************/

/**
 * @brief This function is responsible for Initializing I2C communication bus with 100KHz
 * 
 */
void heeprom_init(void);

/**
 * @brief This function is responsible for writing a data byte in a specific eeprom block 
 * 
 * @param au8_eepromBlock
 * @param au8_eepromAddress 
 * @param au8_data 
 */
void heeprom_writeByte(u8_t au8_eepromBlock, u8_t au8_eepromAddress, u8_t au8_data);

/**
 * @brief This function is responsible for writing a stream of data bytes in a specific eeprom block 
 * 
 * @param au8_eepromBlock 
 * @param au8_eepromAddress 
 * @param pu8_data 
 * @param au8_dataSize 
 */
void heeprom_writeDataStream(u8_t au8_eepromBlock, u8_t au8_eepromAddress, u8_t* pu8_data, u8_t au8_dataSize);

/**
 * @brief This function is responsible for reading a data byte from a specific eeprom block
 * 
 * @param au8_eepromBlock 
 * @param au8_eepromAddress 
 * @param pu8_data 
 */
void heeprom_readByte(u8_t au8_eepromBlock, u8_t au8_eepromAddress, u8_t* pu8_data);

/**
 * @brief This function is responsible for reading a stream of data bytes from a specific eeprom block
 * 
 * @param au8_eepromBlock 
 * @param au8_eepromAddress 
 * @param pu8_data 
 */
void heeprom_readDataStream(u8_t au8_eepromBlock, u8_t au8_eepromAddress, u8_t* pu8_data, u8_t au8_dataSize);

#endif /*__HEEP_INTERFACE_H__*/