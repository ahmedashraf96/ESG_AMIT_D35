#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "HLED_interface.h"
#include "STTS_interface.h"
#include "avr/interrupt.h"

void task1(void)
{
    hled_toggleLedValue(LED0);
}

void task2(void)
{
    hled_toggleLedValue(LED1);
}

void task3(void)
{
    hled_toggleLedValue(LED2);
}

int main(void)
{
    task_t task_led0 = {task1, 20};
    task_t task_led1 = {task2, 10};
    task_t task_led2 = {task3, 5};

    hled_init(LED0);
    hled_init(LED1);
    hled_init(LED2);

    stts_init();

    stts_addTask(task_led0);
    stts_addTask(task_led1);
    stts_addTask(task_led2);

    sei();

    stts_run(50);

    while(1)
    {
        /*Idle*/
    }

    return 0;
}