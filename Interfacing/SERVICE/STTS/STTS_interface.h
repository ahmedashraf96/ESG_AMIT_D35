/**
 * @file    STTS_interface.h
 * @author  Ahmed Ashraf (ahmedashrafelnaqeeb@gmail.com)
 * @brief   This file contains interfacing information related to Time Triggered System (TTS) module
 * @version 1.0
 * @date    2022-11-26
 * 
 * 
 */

/*Header file guard*/
#ifndef __STTS_INTERFACE_H__
#define __STTS_INTERFACE_H__

/***************************************************************************************************/
/*                                         Interfacing datatypes                                   */
/***************************************************************************************************/

typedef struct 
{
    /*Task code*/
    void (*fptr)(void);

    /*Task periodicity*/
    u8_t task_periodicity;
}task_t;

/***************************************************************************************************/
/*                                        Functions' prototypes                                    */
/***************************************************************************************************/

/**
 * @brief This function is responsible for initializing the TTS system
 * 
 */
void stts_init(void);

/**
 * @brief This function is responsible for running the TTS with specific tick time in milli-seconds
 * 
 * @param au32_tickTimeMs 
 */
void stts_run(u32_t au32_tickTimeMs);

/**
 * @brief This function is responsible for adding a new task to the TTS
 * 
 * @param xTask 
 */
void stts_addTask(task_t xTask);

#endif /*__STTS_INTERFACE_H__*/