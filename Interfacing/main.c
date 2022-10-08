#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "avr/io.h"

int main(void)
{
    u16_t au16_value = 0;
    SET_BIT(DDRC, 7);
    TCCR0 = 0;
    TCNT0 = 113;
    TCCR0 |= 3;

    while(1)
    {
        TOGGLE_BIT(PORTC, 7);

        while(au16_value < 976)
        {
            while(!GET_BIT(TIFR, 0));
            SET_BIT(TIFR, 0);
            au16_value++;
        }
        au16_value = 0;
        
    }

    return 0;
}