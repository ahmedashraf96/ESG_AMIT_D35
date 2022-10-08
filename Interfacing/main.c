#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "avr/interrupt.h"
#include "MDIO_interface.h"
#include "MTIMER_interface.h"

int main(void)
{
    mdio_setPinStatus(PORTC, PIN7, OUTPUT);
    mtimer_init(TIMER_CHANNEL_0, TIMER_DELAY_MODE, TIMER_DELAY_PRESCALER);

    while(1)
    {
        mdio_togglePinValue(PORTC, PIN7);
        mtimer_delayMs_synchronous(TIMER_CHANNEL_0, 1000);       
    }

    return 0;
}