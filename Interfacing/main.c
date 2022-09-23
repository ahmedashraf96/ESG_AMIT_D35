#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "HSEV_SEG_interface.h"
#include "util/delay.h"

int main(void)
{
    u8_t au8_looping;
    u8_t au8_looping_2;

    u8_t big_number = 0;

    hsev_seg_init(SEV_SEG_1);
    hsev_seg_init(SEV_SEG_2);

    while(1)
    {
        for(au8_looping = NUMBER_0; au8_looping <= NUMBER_9; au8_looping++)
        {
            for(au8_looping_2 = 0; au8_looping_2 < 50; au8_looping_2++)
            {
                hsev_seg_enable(SEV_SEG_1);
                hsev_seg_displayNumber(big_number);
                _delay_ms(10);
                hsev_seg_disable(SEV_SEG_1);

                hsev_seg_enable(SEV_SEG_2);
                hsev_seg_displayNumber(au8_looping);
                _delay_ms(10);
                hsev_seg_disable(SEV_SEG_2);
            }
        }

        big_number++;

        if(big_number > NUMBER_9)
        {
            big_number = NUMBER_0;
        }
        else
        {
            /*Do nothing*/
        }

    }

    return 0;
}