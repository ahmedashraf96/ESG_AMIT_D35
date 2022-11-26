#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "HLED_interface.h"
#include "STTS_interface.h"
#include "avr/interrupt.h"

void task1(void)
{
    hled_toggleLedValue(LED0);
}

int main(void)
{
    task_t task_led0 = {task1, 10};

    hled_init(LED0);

    stts_init();

    stts_addTask(task_led0);

    sei();

    stts_run(100);

    while(1)
    {
    }

    return 0;
}