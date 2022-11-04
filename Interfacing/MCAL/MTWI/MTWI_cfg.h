/**
 * @file    MTWI_cfg.h
 * @author  Ahmed Ashraf (ahmedashrafelnaqeeb@gmail.com)
 * @brief   This file contains configuration parameters related to TWI module
 * @version 1.0
 * @date    2022-11-04
 * 
 * 
 */

/*Header file guard*/
#ifndef __MTWI_CFG_H__
#define __MTWI_CFG_H__

/***************************************************************************************************/
/*                                         Configuration macros                                    */
/***************************************************************************************************/

/*SCL speed macros*/
#define TWI_100KHZ_SPEED              (72)
#define TWI_200KHZ_SPEED              (32)
#define TWI_300KHZ_SPEED              (18)
#define TWI_400KHZ_SPEED              (12)

/*TWI SCL Speed choice*/
#define TWI_SCL_SPEED                 (TWI_100KHZ_SPEED)

#endif /*__MTWI_CFG_H__*/