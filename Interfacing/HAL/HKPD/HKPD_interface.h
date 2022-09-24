/**
 * @file    HKPD_interface.h
 * @author  Ahmed Ashraf (ahmedashrafelnaqeeb@gmail.com)
 * @brief   This file contains interfacing information related to Keypad module
 * @version 1.0
 * @date    2022-09-24
 * 
 * 
 */

/*Header file guard*/
#ifndef __HKPD_INTERFACE_H__
#define __HKPD_INTERFACE_H__

/***************************************************************************************************/
/*                                        Functions' prototypes                                    */
/***************************************************************************************************/

/**
 * @brief This function is responsible for initializing the keypad module
 * 
 */
void hkpd_init(void);

/**
 * @brief This function is used to get the pressed keypad button value
 * 
 * @param pu8_button 
 */
void hkpd_getPressedButton(u8_t* pu8_button);

#endif /*__HKPD_INTERFACE_H__*/