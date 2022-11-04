#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MTWI_interface.h"
#include "util/delay.h"

int main(void)
{
    mtwi_init();
    mtwi_start(0x60, TWI_WRITE_OPERATION);

    mtwi_masterSend(0x50);
    _delay_ms(1000);
    mtwi_masterSend(0x60);
    _delay_ms(1000);
    mtwi_masterSend(0x70);
    _delay_ms(1000);
    mtwi_masterSend(0x80);
    _delay_ms(1000);
    mtwi_masterSend(0x90);
    _delay_ms(1000);

    mtwi_stop();

    while(1)
    {
    }

    return 0;
}