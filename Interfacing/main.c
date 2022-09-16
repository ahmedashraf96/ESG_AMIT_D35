#include "avr/io.h"
#include "util/delay.h"


int main(void)
{
    SET_BIT(DDRC, 2);

    while(1)
    {
        TOGGLE_BIT(PORTC, 2);
        _delay_ms(100);
    }

    return 0;
}