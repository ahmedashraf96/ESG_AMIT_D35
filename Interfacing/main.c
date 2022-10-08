#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "avr/interrupt.h"
#include "MDIO_interface.h"
#include "MTIMER_interface.h"

void func(void)
{
    mdio_togglePinValue(PORTC, PIN7);
}

int main(void)
{
    mdio_setPinStatus(PORTC, PIN7, OUTPUT);
    mtimer_init(TIMER_CHANNEL_0, TIMER_DELAY_MODE, TIMER_DELAY_PRESCALER);

    sei();
    
    mtimer_delayMs_asynchronous(TIMER_CHANNEL_0, 2000, func, TIMER_PERIODIC_OPERATION);

    while(1);

    return 0;
}