/**
 * @file    STTS_program.c
 * @author  Ahmed Ashraf (ahmedashrafelnaqeeb@gmail.com)
 * @brief   This file contains logical implementation related to Time Triggered System (TTS) module
 * @version 1.0
 * @date    2022-11-26
 * 
 * 
 */

/***************************************************************************************************/
/*                                             Includes                                            */
/***************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "STTS_private.h"
#include "STTS_cfg.h"
#include "STTS_interface.h"

/***************************************************************************************************/
/*                                          Important macros                                       */
/***************************************************************************************************/

/*TTS operations*/
#define TIMER1_CTC_MODE                   (0x0008)
#define CONVERT_TIME_TO_TIMER_TICKS       (250)
#define TASK_TIME_ACHIEVED                (0)
#define TIMER2_COMPA_ISR                  (__vector_7)

/***************************************************************************************************/
/*                                          Important variables                                    */
/***************************************************************************************************/

/*Tasks pool array*/
static task_t xTasks_arr[NUMBER_OF_TASKS];

/*Global counter used to count number of tasks*/
static u8_t gu8_tasksCounter = 0;

/*Global counter used to count the system ticks*/
volatile static u32_t gu32_systemTicks = 0;

/***************************************************************************************************/
/*                                       Functions' definitions                                    */
/***************************************************************************************************/

void stts_init(void)
{
    /*Enable timer1 with CTC mode*/
    MTIMER_TCCR1 = TIMER1_CTC_MODE;

    /*Reset the output compare register*/
    MTIMER_OCR1A = 0;

    /*Reset the timer counter*/
    MTIMER_TCNT1 = 0;

    /*Return from this function*/
    return;
}

void stts_run(u32_t au32_tickTimeMs)
{
    /*Setting tick time*/
    MTIMER_OCR1A = (au32_tickTimeMs * CONVERT_TIME_TO_TIMER_TICKS);

    /*Enable timer1 CTC mode interrupt*/
    SET_BIT(MTIMER_TIMSK, MTIMER_TIMSK_OCIE1A_BIT);

    /*Running timer1*/
    MTIMER_TCCR1 |= TIMER_PRESCALER;

    /*Return from this function*/
    return;
}

void stts_addTask(task_t xTask)
{
    /*Checking if the number of entered tasks is less than the number of system tasks*/
    if(gu8_tasksCounter < NUMBER_OF_TASKS)
    {
        /*Adding the new task*/
        xTasks_arr[gu8_tasksCounter] = xTask;

        /*Incrementing the tasks counter*/
        gu8_tasksCounter++;
    }
    else
    {
        /*Do nothing*/
    }

    /*Return from this function*/
    return;
}

/**
 * @brief This function is used to schedule between the system tasks
 * 
 */
static void stts_scheduler(void)
{
    /*Local variable used in looping operations*/
    u8_t au8_loopingVar = 0;

    /*Looping over system tasks*/
    for(au8_loopingVar = 0; au8_loopingVar < NUMBER_OF_TASKS; au8_loopingVar++)
    {
        /*Chehcking if the task periodicity happened or not*/
        if((gu32_systemTicks % xTasks_arr[au8_loopingVar].task_periodicity) == TASK_TIME_ACHIEVED)
        {
            /*Executing task code*/
           xTasks_arr[au8_loopingVar].fptr(); 
        }
        else
        {
            /*Do nothing*/
        }
    }

    /*Rerturn from this function*/
    return;    
}

/***************************************************************************************************/
/*                                          Timer1 ISR                                             */
/***************************************************************************************************/

void TIMER2_COMPA_ISR(void) __attribute__((signal));
void TIMER2_COMPA_ISR(void)
{
    /*Increasing system tick*/
    gu32_systemTicks++;

    /*Running the system scheduler*/
    stts_scheduler();
}