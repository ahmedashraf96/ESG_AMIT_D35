/**
 * @file    HPBUTT_cfg.h
 * @author  Ahmed Ashraf (ahmedashrafelnaqeeb@gmail.com)
 * @brief   This file contains configuration information related to Push button module
 * @version 1.0
 * @date    2022-09-17
 * 
 * 
 */

/*Header file guard*/
#ifndef __HPBUTT_CFG_H__
#define __HPBUTT_CFG_H__

/***************************************************************************************************/
/*                                       Configuration macros                                      */
/***************************************************************************************************/

/*Push button 0 configurations*/
#define PB0_PORT                      (PORTB)
#define PB0_PIN                       (PIN0)

/*Push button 1 configurations*/
#define PB1_PORT                      (PORTD)
#define PB1_PIN                       (PIN6)

/*Push button 2 configurations*/
#define PB2_PORT                      (PORTD)
#define PB2_PIN                       (PIN2)

#endif /*__HPBUTT_CFG_H__*/