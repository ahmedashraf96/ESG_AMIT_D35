#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MTWI_interface.h"
#include "util/delay.h"

int main(void)
{
    u8_t au8_data;

    mtwi_init();
    mtwi_start(0x60, TWI_READ_OPERATION);

    mtwi_masterRecv_ACK(&au8_data);
    _delay_ms(100);
    mtwi_masterRecv_ACK(&au8_data);
    _delay_ms(100);
    mtwi_masterRecv_ACK(&au8_data);
    _delay_ms(100);
    mtwi_masterRecv_NACK(&au8_data);
    _delay_ms(100);
    mtwi_stop();

    while(1)
    {
    }

    return 0;
}