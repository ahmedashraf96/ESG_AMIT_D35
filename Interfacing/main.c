#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "MSPI_interface.h"
#include "util/delay.h"

int main(void)
{
    u8_t au8_data;

    mspi_init(SPI_MASTER_MODE, SPI_MSB_FIRST, SPI_SAMPLE_R_SETUP_F, SPI_PRESCALER_8);

    mdio_setPinStatus(PORTB, PIN4 | PIN5 | PIN7, OUTPUT);
    mdio_setPinStatus(PORTB, PIN6, INPUT_FLOAT);

    while(1)
    {
        mspi_masterSendRecv_byte(0x50, &au8_data);
        _delay_ms(1000);
        mspi_masterSendRecv_byte(0x60, &au8_data);
        _delay_ms(1000);
        mspi_masterSendRecv_byte(0x70, &au8_data);
        _delay_ms(1000);
        mspi_masterSendRecv_byte(0x80, &au8_data);
        _delay_ms(1000);
        mspi_masterSendRecv_byte(0x90, &au8_data);
        _delay_ms(1000);
    }

    return 0;
}