#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "MUART_interface.h"

int main(void)
{
    u8_t au8_data;

    muart_init(UART_9600_BPS);

    mdio_setPinStatus(PORTD, PIN0, INPUT_FLOAT);
    mdio_setPinStatus(PORTD, PIN1, OUTPUT);
    mdio_setPinStatus(PORTC, PIN2, OUTPUT);

    while(1)
    {
        muart_recvByte(&au8_data);

        if(au8_data == 'a')
        {
            mdio_setPinValue(PORTC, PIN2, HIGH);
            muart_sendByte('\r');
            muart_sendByte('\n');
            muart_sendByte('O');
            muart_sendByte('N');
        }
        else if(au8_data == 'b')
        {
            mdio_setPinValue(PORTC, PIN2, LOW);
            muart_sendByte('\r');
            muart_sendByte('\n');
            muart_sendByte('O');
            muart_sendByte('F');
            muart_sendByte('F');
        }
        else
        {
            /*Do nothing*/
        }

        au8_data = 0;
    }

    return 0;
}