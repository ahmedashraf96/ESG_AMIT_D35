/**
 * @file    MTWI_program.c
 * @author  Ahmed Ashraf (ahmedashrafelnaqeeb@gmail.com)
 * @brief   This file contains logical implementation related to TWI module
 * @version 1.0
 * @date    2022-11-04
 * 
 * 
 */

/***************************************************************************************************/
/*                                             Includes                                            */
/***************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MTWI_private.h"
#include "MTWI_cfg.h"
#include "MTWI_interface.h"

/***************************************************************************************************/
/*                                        Important macros                                         */
/***************************************************************************************************/

/*TWI operations*/
#define RESET_PRESCLAER_BITS                                    (0)
#define BIT_VALUE_1                                             (1)
#define START_CONDITION_GENERATED                               (0x08)
#define REP_START_CONDITION_GENERATED                           (0x10)
#define CLEARING_PRESCALER_BITS                                 (0xF8)
#define SHIFT_LEFT_BY_1                                         (1)

/***************************************************************************************************/
/*                                       Functions' definitions                                    */
/***************************************************************************************************/

void mtwi_init(void)
{
    /*Setting the speed of TWI SCL pin*/
    MTWI_TWBR = TWI_SCL_SPEED;

    /*Resetting the TWPS bits*/
    MTWI_TWSR = RESET_PRESCLAER_BITS;

    /*Return from this function*/
    return;
}

void mtwi_start(u8_t au8_slaveAddress, u8_t au8_readWrite_operation)
{
    /*Setting the control register to generate a start condition*/   
    MTWI_TWCR = (BIT_VALUE_1 << MTWI_TWCR_TWINT_BIT) | (BIT_VALUE_1 << MTWI_TWCR_TWSTA_BIT) | (BIT_VALUE_1 << MTWI_TWCR_TWEN_BIT);

    /*Waiting until the start or repeated start conditions will be generated*/
    while( ((MTWI_TWSR & CLEARING_PRESCALER_BITS) != START_CONDITION_GENERATED) && ((MTWI_TWSR & CLEARING_PRESCALER_BITS) != REP_START_CONDITION_GENERATED) );

    /*Setting the SLA+R/W*/
    MTWI_TWDR = (au8_slaveAddress << SHIFT_LEFT_BY_1) | au8_readWrite_operation;

    /*Setting the control register to send SLA+R/W*/   
    MTWI_TWCR = (BIT_VALUE_1 << MTWI_TWCR_TWINT_BIT) | (BIT_VALUE_1 << MTWI_TWCR_TWEN_BIT);

    /*Waiting until the SLA+R/W is transmitted and ACK or NACK is received*/
    while(!GET_BIT(MTWI_TWCR, MTWI_TWCR_TWINT_BIT));

    /*Return from this function*/
    return;
}

void mtwi_stop(void)
{
    /*Setting the control register to generate a stop condition*/   
    MTWI_TWCR = (BIT_VALUE_1 << MTWI_TWCR_TWINT_BIT) | (BIT_VALUE_1 << MTWI_TWCR_TWSTO_BIT) | (BIT_VALUE_1 << MTWI_TWCR_TWEN_BIT);

    /*Waiting until the stop condition is sent*/
    while(GET_BIT(MTWI_TWCR, MTWI_TWCR_TWSTO_BIT));

    /*Return from this function*/
    return;
}

void mtwi_masterSend(u8_t au8_data)
{
    /*Setting the data to be sent*/
    MTWI_TWDR = au8_data;    

    /*Setting the control register to send the data byte*/   
    MTWI_TWCR = (BIT_VALUE_1 << MTWI_TWCR_TWINT_BIT) | (BIT_VALUE_1 << MTWI_TWCR_TWEN_BIT);

    /*Waiting until the data byte is transmitted and ACK or NACK is received*/
    while(!GET_BIT(MTWI_TWCR, MTWI_TWCR_TWINT_BIT));

    /*Return from this function*/
    return;
}

void mtwi_masterRecv_ACK(u8_t* pu8_data)
{
    /*Setting the control register to receive the data byte and send ACK*/   
    MTWI_TWCR = (BIT_VALUE_1 << MTWI_TWCR_TWINT_BIT) | (BIT_VALUE_1 << MTWI_TWCR_TWEA_BIT) | (BIT_VALUE_1 << MTWI_TWCR_TWEN_BIT);

    /*Waiting until the data byte is received and ACK is transmitted*/
    while(!GET_BIT(MTWI_TWCR, MTWI_TWCR_TWINT_BIT));

    /*Getting the received data byte*/
    *pu8_data = MTWI_TWDR;

    /*Return from this function*/
    return;
}

void mtwi_masterRecv_NACK(u8_t* pu8_data)
{
    /*Setting the control register to receive the data byte and send NACK*/   
    MTWI_TWCR = (BIT_VALUE_1 << MTWI_TWCR_TWINT_BIT) | (BIT_VALUE_1 << MTWI_TWCR_TWEN_BIT);

    /*Waiting until the data byte is received and NACK is transmitted*/
    while(!GET_BIT(MTWI_TWCR, MTWI_TWCR_TWINT_BIT));

    /*Getting the received data byte*/
    *pu8_data = MTWI_TWDR;

    /*Return from this function*/
    return;
}
