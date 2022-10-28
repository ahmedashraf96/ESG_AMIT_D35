/**
 * @file    MUART_interface.h
 * @author  Ahmed Ashraf (ahmedashrafelnaqeeb@gmail.com)
 * @brief   This file contains interfacing information related to UART module
 * @version 1.0
 * @date    2022-10-28
 * 
 * 
 */

/*Header file guard*/
#ifndef __MUART_INTERFACE_H__
#define __MUART_INTERFACE_H__

/***************************************************************************************************/
/*                                         Interfacing macros                                      */
/***************************************************************************************************/

/*UART Baud rates*/
#define UART_2400_BPS       (416)
#define UART_4800_BPS       (207)
#define UART_9600_BPS       (103)
#define UART_19200_BPS      (51)
#define UART_115200_BPS     (8)

/***************************************************************************************************/
/*                                        Functions' prototypes                                    */
/***************************************************************************************************/

/**
 * @brief This function is used in UART initialization with specific baud rate
 * 
 * @param au16_baudRate 
 */
void muart_init(u16_t au16_baudRate);

/**
 * @brief This function is responsible for sending data byte over UART
 * 
 * @param au8_dataByte 
 */
void muart_sendByte(u8_t au8_dataByte);

/**
 * @brief This function is responsible for receiving data byte over UART
 * 
 * @param pu8_dataByte 
 */
void muart_recvByte(u8_t* pu8_dataByte);

/**
 * @brief This function is responsible for sending data stream over UART
 * 
 * @param pu8_streamData 
 * @param au8_dataSize 
 */
void muart_sendStream(u8_t* pu8_streamData, u8_t au8_dataSize);

#endif /*__MUART_INTERFACE_H__*/