#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "HSEV_SEG_interface.h"
#include "util/delay.h"

int main(void)
{
    hsev_seg_init(SEV_SEG_1);
    hsev_seg_enable(SEV_SEG_1);
    //hsev_seg_disable(SEV_SEG_2);

    while(1)
    {
        u8_t au8_looping;
        for(au8_looping = NUMBER_0; au8_looping <= NUMBER_9; au8_looping++)
        {
            hsev_seg_displayNumber(au8_looping);
            _delay_ms(1000);
        }
    }

    return 0;
}