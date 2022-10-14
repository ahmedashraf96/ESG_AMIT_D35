#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "MTIMER_interface.h"
#include "util/delay.h"

int main(void)
{
    u16_t delay_var = 0;

    mdio_setPinStatus(PORTB, PIN3, OUTPUT);
    mtimer_init(TIMER_CHANNEL_0, TIMER_PWM_MODE, TIMER_FREQ_1KHZ);

    mtimer_startPWM_signal(TIMER_CHANNEL_0);
    while(1)
    {
        for(delay_var = 0; delay_var <= 255; delay_var++)
        {
            mtimer_runPWM_signal(TIMER_CHANNEL_0, delay_var);
            _delay_ms(50);
        }

        _delay_ms(3000);

        for(delay_var = 255; delay_var >= 0; delay_var--)
        {
            mtimer_runPWM_signal(TIMER_CHANNEL_0, delay_var);
            _delay_ms(50);
        }

        _delay_ms(3000);
    }


    return 0;
}