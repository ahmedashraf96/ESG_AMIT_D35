/**
 * @file    MTWI_interface.h
 * @author  Ahmed Ashraf (ahmedashrafelnaqeeb@gmail.com)
 * @brief   This file contains interfacing information related to TWI module
 * @version 1.0
 * @date    2022-11-04
 * 
 * 
 */

/*Header file guard*/
#ifndef __MTWI_INTERFACE_H__
#define __MTWI_INTERFACE_H__

/***************************************************************************************************/
/*                                         Interfacing macros                                      */
/***************************************************************************************************/

/*TWI R/W operations*/
#define TWI_WRITE_OPERATION     (0)
#define TWI_READ_OPERATION      (1)

/***************************************************************************************************/
/*                                        Functions' prototypes                                    */
/***************************************************************************************************/

/**
 * @brief This function is responsible for initializing the TWI operations
 * 
 */
void mtwi_init(void);

/**
 * @brief This function is used to generate a start condition or repeated start with read/write operation 
 * 
 * @param au8_slaveAddress 
 * @param au8_readWrite_operation 
 */
void mtwi_start(u8_t au8_slaveAddress, u8_t au8_readWrite_operation);

/**
 * @brief This function is used to generate a stop condition
 * 
 */
void mtwi_stop(void);

/**
 * @brief This function is responsible for sending a master data byte
 * 
 * @param au8_data 
 */
void mtwi_masterSend(u8_t au8_data);

/**
 * @brief This function is responsible for receiving a data byte as a master and send ACK to slave
 *
 * @param pu8_data 
 */
void mtwi_masterRecv_ACK(u8_t* pu8_data);

/**
 * @brief This function is responsible for receiving a data byte as a master and send NACK to slave
 * 
 * @param pu8_data 
 */
void mtwi_masterRecv_NACK(u8_t* pu8_data);

#endif /*__MTWI_INTERFACE_H__*/