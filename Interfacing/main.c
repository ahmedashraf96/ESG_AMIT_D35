#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "HLED_interface.h"
#include "util/delay.h"

int main(void)
{
    hled_init(LED0);

    while(1)
    {
        hled_toggleLedValue(LED0);
        _delay_ms(100);
    }

    return 0;
}