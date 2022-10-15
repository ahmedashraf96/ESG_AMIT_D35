#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "LWDT.h"
#include "MDIO_interface.h"
#include "util/delay.h"

int main(void)
{
    mdio_setPinStatus(PORTA, PIN0, OUTPUT);

    WDT_START(TIMEOUT_2_1_S);
    _delay_ms(1500);        
    WDT_STOP();
    
    while(1)
    {
        mdio_togglePinValue(PORTA, PIN0);
        _delay_ms(1000);        
    }

    return 0;
}