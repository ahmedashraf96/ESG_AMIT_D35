/**
 * @file    MSPI_program.c
 * @author  Ahmed Ashraf (ahmedashrafelnaqeeb@gmail.com)
 * @brief   This file contains logical implementation related to SPI module
 * @version 1.0
 * @date    2022-10-29
 * 
 * 
 */

/***************************************************************************************************/
/*                                             Includes                                            */
/***************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MSPI_private.h"
#include "MSPI_interface.h"

/***************************************************************************************************/
/*                                        Important macros                                         */
/***************************************************************************************************/

/*SPI operations*/
#define SPI_ENABLE              (0x40)
#define DIVIDE_BY_2             (2)
#define IS_EVEN_NUMBER          (0)
#define DATA_NOT_SET            (0)
#define DATA_IS_SET             (1)

/***************************************************************************************************/
/*                                       Functions' definitions                                    */
/***************************************************************************************************/

void mspi_init(u8_t au8_master_slave_select, u8_t au8_dataOrder, u8_t au8_dataTransferMode, u8_t au8_spiClockPrescaler)
{
    /*Checking if the spi clock prescaler value is even number or not*/
    if((au8_spiClockPrescaler % DIVIDE_BY_2) == IS_EVEN_NUMBER)
    {
        /*Setting the double speed bit*/
        SET_BIT(MSPI_SPSR, MSPI_SPSR_SPI2X_BIT);
    }
    else
    {
        /*Do nothing*/
    }

    /*Getting the clock bits value*/
    au8_spiClockPrescaler /= DIVIDE_BY_2;

    /*Setting the SPI settings*/
    MSPI_SPCR = SPI_ENABLE | (au8_master_slave_select << MSPI_SPCR_MSTR_BIT) | (au8_dataOrder << MSPI_SPCR_DORD_BIT) 
                           | (au8_dataTransferMode << MSPI_SPCR_CPHA_BIT) | (au8_spiClockPrescaler);

    /*Return from this function*/
    return;
}

void mspi_masterSendRecv_byte(u8_t au8_sendDataByte, u8_t* pu8_recvDataByte)
{
    /*Setting the data byte to be sent over SPI*/
    MSPI_SPDR = au8_sendDataByte;

    /*Waiting until the data transfer will be complete*/
    while(!GET_BIT(MSPI_SPSR, MSPI_SPSR_SPIF_BIT));

    /*Getting the received data byte*/
    *pu8_recvDataByte = MSPI_SPDR;

    /*Return from this function*/
    return;
}

void mspi_slaveSendRecv_byte(u8_t au8_sendDataByte, u8_t* pu8_recvDataByte)
{
    /*Static local variable used as SPI slave data set reporting flag*/
    static u8_t au8_slaveData_flag = DATA_NOT_SET;

    /*Checking if the slave data is not set or not*/
    if(au8_slaveData_flag == DATA_NOT_SET)
    {
        /*Sending a data byte to master in the new SPI cycle*/
        MSPI_SPDR = au8_sendDataByte;

        /*Report that the data is already set*/
        au8_slaveData_flag = DATA_IS_SET;   
    }
    else
    {
        /*Do nothing*/
    }

    /*Checking if there's a new data received from master*/
    if(GET_BIT(MSPI_SPSR, MSPI_SPSR_SPIF_BIT))
    {
        /*Getting the received data byte*/
        *pu8_recvDataByte = MSPI_SPDR;

        /*Sending a data byte to master in the new SPI cycle*/
        MSPI_SPDR = au8_sendDataByte;   
    }
    else
    {
        /*Do nothing*/
    }

    /*Return from this function*/
    return;
}
