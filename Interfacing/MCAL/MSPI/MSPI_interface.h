/**
 * @file    MSPI_interface.h
 * @author  Ahmed Ashraf (ahmedashrafelnaqeeb@gmail.com)
 * @brief   This file contains interfacing information related to SPI module
 * @version 1.0
 * @date    2022-10-29
 * 
 * 
 */

/*Header file guard*/
#ifndef __MSPI_INTERFACE_H__
#define __MSPI_INTERFACE_H__

/***************************************************************************************************/
/*                                         Interfacing macros                                      */
/***************************************************************************************************/

/*Master/Slave modes*/
#define SPI_MASTER_MODE             (1)
#define SPI_SLAVE_MODE              (0)

/*Data order*/
#define SPI_MSB_FIRST               (0)
#define SPI_LSB_FIRST               (1)

/*Data transfer mode*/
#define SPI_SAMPLE_R_SETUP_F        (0)
#define SPI_SETUP_R_SAMPLE_F        (1)
#define SPI_SAMPLE_F_SETUP_R        (2)
#define SPI_SETUP_F_SAMPLE_R        (3)

/*SPI clock prescalers*/
#define SPI_PRESCALER_2             (0)
#define SPI_PRESCALER_4             (1)
#define SPI_PRESCALER_8             (2)
#define SPI_PRESCALER_16            (3)
#define SPI_PRESCALER_32            (4)
#define SPI_PRESCALER_64            (5)
#define SPI_PRESCALER_128           (7)

/***************************************************************************************************/
/*                                        Functions' prototypes                                    */
/***************************************************************************************************/

/**
 * @brief This function is used to initialize the SPI peripheral with: 
 * (Master/Slave - Data order - Transfer mode - clock prescaler) operations
 * 
 * @param au8_master_slave_select 
 * @param au8_dataOrder 
 * @param au8_dataTransferMode 
 * @param au8_spiClockPrescaler 
 */
void mspi_init(u8_t au8_master_slave_select, u8_t au8_dataOrder, u8_t au8_dataTransferMode, u8_t au8_spiClockPrescaler);

/**
 * @brief This function is used in sending and receiving data bytes in master mode
 * 
 * @param au8_sendDataByte 
 * @param pu8_recvDataByte 
 */
void mspi_masterSendRecv_byte(u8_t au8_sendDataByte, u8_t* pu8_recvDataByte);

/**
 * @brief This function is used in sending and receiving data bytes in slave mode
 * 
 * @param au8_sendDataByte 
 * @param pu8_recvDataByte 
 */
void mspi_slaveSendRecv_byte(u8_t au8_sendDataByte, u8_t* pu8_recvDataByte);

#endif /*__MSPI_INTERFACE_H__*/