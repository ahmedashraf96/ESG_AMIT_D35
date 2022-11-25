/**
 * @file    HEEP_program.c
 * @author  Ahmed Ashraf (ahmedashrafelnaqeeb@gmail.com)
 * @brief   This file contains logical implementation related to EEPROM module
 * @version 1.0
 * @date    2022-11-25
 * 
 * 
 */

/***************************************************************************************************/
/*                                             Includes                                            */
/***************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MTWI_interface.h"
#include "HEEP_cfg.h"
#include "HEEP_interface.h"
#include "util/delay.h"

/***************************************************************************************************/
/*                                          Important macros                                       */
/***************************************************************************************************/

/***************************************************************************************************/
/*                                       Functions' definitions                                    */
/***************************************************************************************************/

void heeprom_init(void)
{
    /*Initializing TWI bus*/
    mtwi_init();

    /*Return from this function*/
    return;
}

void heeprom_writeByte(u8_t au8_eepromBlock, u8_t au8_eepromAddress, u8_t au8_data)
{
    /*Getting the EEPROM block*/
    au8_eepromBlock |= EEPROM_SLAVE_ADDRESS_BASE;

    /*Starting the TWI operation*/
    mtwi_start(au8_eepromBlock, TWI_WRITE_OPERATION);

    /*Sending the write address*/
    mtwi_masterSend(au8_eepromAddress);

    /*Waiting for 10ms*/
    _delay_ms(10);

    /*Sending the data byte*/
    mtwi_masterSend(au8_data);

    /*Waiting for 10ms*/
    _delay_ms(10);

    /*Stop the TWI operation*/
    mtwi_stop();

    /*Return from this function*/
    return;
}

void heeprom_writeDataStream(u8_t au8_eepromBlock, u8_t au8_eepromAddress, u8_t* pu8_data, u8_t au8_dataSize)
{
    /*local variable used in looping operations*/
    u8_t au8_loopingVar = 0;

    /*Getting the EEPROM block*/
    au8_eepromBlock |= EEPROM_SLAVE_ADDRESS_BASE;

    /*Checking if the write size is more than page size or not*/
    if(au8_dataSize > EEPROM_PAGE_SIZE)
    {
        /*Setting the page size as default*/
        au8_loopingVar = EEPROM_PAGE_SIZE;
    }
    else
    {
        /*Setting the data size as default*/
        au8_loopingVar = au8_dataSize;
    }

    /*Starting the TWI operation*/
    mtwi_start(au8_eepromBlock, TWI_WRITE_OPERATION);

    /*Sending the write address*/
    mtwi_masterSend(au8_eepromAddress);

    /*Waiting for 10ms*/
    _delay_ms(10);

    /*Looping over the data bytes*/
    while(au8_loopingVar--)
    {
        /*Sending the data byte*/
        mtwi_masterSend(*pu8_data);

        /*Moving to the next data byte*/
        pu8_data++;
    }

    /*Waiting for 10ms*/
    _delay_ms(10);

    /*Stop the TWI operation*/
    mtwi_stop();

    /*Return from this function*/
    return;
}

void heeprom_readByte(u8_t au8_eepromBlock, u8_t au8_eepromAddress, u8_t* pu8_data)
{
    /*Getting the EEPROM block*/
    au8_eepromBlock |= EEPROM_SLAVE_ADDRESS_BASE;

    /*Starting the TWI operation*/
    mtwi_start(au8_eepromBlock, TWI_WRITE_OPERATION);

    /*Sending the write address*/
    mtwi_masterSend(au8_eepromAddress);

    /*Waiting for 10ms*/
    _delay_ms(10);

    /*Generating repeated start with read opertion*/
    mtwi_start(au8_eepromBlock, TWI_READ_OPERATION);

    /*Getting the data from EEPROM and sending NACK*/
    mtwi_masterRecv_NACK(pu8_data);

    /*Wait for 10ms*/
    _delay_ms(10);

    /*Stop the TWI operation*/
    mtwi_stop();

    /*Return from this function*/
    return;
}

void heeprom_readDataStream(u8_t au8_eepromBlock, u8_t au8_eepromAddress, u8_t* pu8_data, u8_t au8_dataSize)
{
    /*Getting the EEPROM block*/
    au8_eepromBlock |= EEPROM_SLAVE_ADDRESS_BASE;

    /*Decrementing the data size by 1*/
    au8_dataSize--;

    /*Starting the TWI operation*/
    mtwi_start(au8_eepromBlock, TWI_WRITE_OPERATION);

    /*Sending the write address*/
    mtwi_masterSend(au8_eepromAddress);

    /*Waiting for 10ms*/
    _delay_ms(10);

    /*Generating repeated start with read opertion*/
    mtwi_start(au8_eepromBlock, TWI_READ_OPERATION);

    /*Looping over data size*/
    while(au8_dataSize--)
    {
        /*Getting the data byte from EEPROM and sending ACK*/
        mtwi_masterRecv_ACK(pu8_data);

        /*Waiting for 10ms*/
        //_delay_ms(10);

        /*Go to the next byte address*/
        pu8_data++;
    }

    /*Getting the data from EEPROM and sending NACK*/
    mtwi_masterRecv_NACK(pu8_data);

    /*Wait for 10ms*/
    _delay_ms(10);

    /*Stop the TWI operation*/
    mtwi_stop();
    
    /*Return from this function*/
    return;
}
