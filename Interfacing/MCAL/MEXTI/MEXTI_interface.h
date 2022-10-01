/**
 * @file    MEXTI_interface.h
 * @author  Ahmed Ashraf (ahmedashrafelnaqeeb@gmail.com)
 * @brief   This file contains interfacing information related to EXTI module
 * @version 1.0
 * @date    2022-10-01
 * 
 * 
 */

/*Header file guard*/
#ifndef __MEXTI_INTERFACE_H__
#define __MEXTI_INTERFACE_H__

/***************************************************************************************************/
/*                                         Interfacing macros                                      */
/***************************************************************************************************/

/*External interrupts' numbers*/
#define INT0_REQ_NUM             (0)
#define INT1_REQ_NUM             (1)
#define INT2_REQ_NUM             (2)

/*External interrupt modes*/
#define LOW_LEVEL_MODE           (0) 
#define LOGICAL_CHANGE_MODE      (1) 
#define FALLING_EDGE_MODE        (2) 
#define RISING_EDGE_MODE         (3) 

/***************************************************************************************************/
/*                                        Functions' prototypes                                    */
/***************************************************************************************************/

/**
 * @brief This function is used to enable specific external interrupt [0, 1 or 2]
 * 
 * @param au8_interruptNumber 
 */
void mexti_enableExternalInterrupt(u8_t au8_interruptNumber);

/**
 * @brief This function is used to disable specific external interrupt [0, 1 or 2]
 * 
 * @param au8_interruptNumber 
 */
void mexti_disableExternalInterrupt(u8_t au8_interruptNumber);

/**
 * @brief This function is used to attach function to a specific ISR [0, 1 or 2] with specific interrupt mode
 * 
 * @param au8_interruptNumber 
 * @param au8_interruptMode 
 * @param fptr_isrFunction 
 */
void mexti_attachISR(u8_t au8_interruptNumber, u8_t au8_interruptMode, void (*fptr_isrFunction)(void));

#endif /*__MEXTI_INTERFACE_H__*/