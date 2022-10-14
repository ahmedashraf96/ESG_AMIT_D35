#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "MTIMER_interface.h"

int main(void)
{
    mdio_setPinStatus(PORTB, PIN3, OUTPUT);
    mtimer_init(TIMER_CHANNEL_0, TIMER_PWM_MODE, TIMER_FREQ_500_HZ);

    mtimer_startPWM_signal(TIMER_CHANNEL_0);
    mtimer_runPWM_signal(TIMER_CHANNEL_0, 50);
    while(1);

    return 0;
}