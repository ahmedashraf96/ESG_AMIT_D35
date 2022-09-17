#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "HLED_interface.h"
#include "HPBUTT_interface.h"
#include "util/delay.h"

int main(void)
{
    u8_t pb_status;

    hled_init(LED1);
    hpbutt_init(PUSH_BUTTON_0);

    while(1)
    {
        hpbutt_getStatus(PUSH_BUTTON_0, &pb_status);

        if(pb_status == PRESSED)
        {
            _delay_ms(200);
            hled_toggleLedValue(LED1);         
        }
        else
        {
            /*Do nothing*/
        }
    }

    return 0;
}