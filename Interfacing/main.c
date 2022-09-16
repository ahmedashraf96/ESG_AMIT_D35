#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "util/delay.h"

int main(void)
{
    u8_t button_value;
    
    mdio_setPinStatus(PORTC, PIN2, OUTPUT);
    mdio_setPinStatus(PORTD, PIN2, INPUT_FLOAT);

    while(1)
    {
        mdio_getPinValue(PORTD, PIN2, &button_value);
       
        if(button_value == HIGH)
        {
            _delay_ms(200);
            mdio_togglePinValue(PORTC, PIN2 | PIN7);
        }
        else
        {
            /*Do nothing*/            
        }
    }

    return 0;
}