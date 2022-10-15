#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "avr/io.h"
#include "MDIO_interface.h"
#include "MTIMER_interface.h"

int main(void)
{
    u8_t duty;
    u32_t freq;

    mdio_setPinStatus(PORTB, PIN3, OUTPUT);
    mdio_setPinStatus(PORTD, PIN6, INPUT_FLOAT);
    
    mtimer_init(TIMER_CHANNEL_0, TIMER_PWM_MODE, TIMER_FREQ_1KHZ);
    mtimer_init(TIMER_CHANNEL_1, TIMER_ICU_MODE, TIMER_ICU_PRESCALER);

    mtimer_startPWM_signal(TIMER_CHANNEL_0);
    mtimer_runPWM_signal(TIMER_CHANNEL_0, 230);
    
    while(1)
    {
        mtimer_getSignal_duty_and_freq(&duty, &freq);

        TCNT2 = duty;
        OCR1A = (u16_t)freq;
    }

    return 0;
}