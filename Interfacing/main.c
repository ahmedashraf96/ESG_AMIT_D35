#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "MTIMER_interface.h"
#include "util/delay.h"

int main(void)
{
    mdio_setPinStatus(PORTB, PIN3, OUTPUT);
    mtimer_init(TIMER_CHANNEL_0, TIMER_PWM_MODE, TIMER_FREQ_62_5_KHZ);

    mtimer_startPWM_signal(TIMER_CHANNEL_0);
    mtimer_runPWM_signal(TIMER_CHANNEL_0, 128);
    while(1);

    return 0;
}