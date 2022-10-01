#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "HLCD_interface.h"
#include "HKPD_interface.h"
#include "avr/io.h"
#include "util/delay.h"

int main(void)
{
    u8_t button = 0;
    hlcd_init();
    hkpd_init();

    while(1)
    {
        hkpd_getPressedButton(&button);

        if(button != 0)
        {
            hlcd_displayCharacter(button);
        }
        else
        {
            /*Do nothing*/
        }
        
        TCNT2 = button;
    }

    return 0;
}