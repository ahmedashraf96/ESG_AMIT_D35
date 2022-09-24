/**
 * @file    HKPD_cfg.h
 * @author  Ahmed Ashraf (ahmedashrafelnaqeeb@gmail.com)
 * @brief   This file contains configuration information related to Keypad module
 * @version 1.0
 * @date    2022-09-24
 * 
 * 
 */

/*Header file guard*/
#ifndef __HKPD_CFG_H__
#define __HKPD_CFG_H__

/***************************************************************************************************/
/*                                         Configuration macros                                    */
/***************************************************************************************************/

/*Number of rows and columns configurations*/
#define KPD_NUM_ROWS        (4)
#define KPD_NUM_COLS        (4)

/*Keypad mapping configurations*/
#define KEYPAD_MAPPING      {                          \
                                {'1', '2', '3', 'A'},  \
                                {'4', '5', '6', 'B'},  \
                                {'7', '8', '9', 'C'},  \
                                {'*', '0', '#', 'D'}   \
                            }

/*Keypad pins configurations*/
#define KPD_PORT            (PORTC)
#define KPD_ROW0            (PIN0)
#define KPD_ROW1            (PIN1)
#define KPD_ROW2            (PIN2)
#define KPD_ROW3            (PIN3)
#define KPD_COL0            (PIN4)
#define KPD_COL1            (PIN5)
#define KPD_COL2            (PIN6)
#define KPD_COL3            (PIN7)

#define KPD_DEFAULT_VALUE   (0)

#endif /*__HKPD_CFG_H__*/