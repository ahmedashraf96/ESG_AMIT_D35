#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "util/delay.h"

int main(void)
{
    mdio_setPinStatus(PORTC, PIN2, OUTPUT);

    while(1)
    {
        mdio_setPinValue(PORTC, PIN2, HIGH);

        _delay_ms(1000);

        mdio_getPinValue(PORTC, PIN2, LOW);

        _delay_ms(1000);
    }

    return 0;
}