#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "MADC_interface.h"


int main(void)
{
    u16_t au16_value;

    mdio_setPinStatus(PORTC, (PIN3 | PIN7), OUTPUT);
    mdio_setPinStatus(PORTD, PIN3, OUTPUT);    
    mdio_setPinStatus(PORTA, PIN1, INPUT_FLOAT);

    madc_init(AVCC_MODE, ADC_10_BITS, ADC_PRESCALER_16);

    while(1)
    {
        madc_singleConversion(ADC_CHANNEL_1, &au16_value);

        if(au16_value >= 0 && au16_value <= 250)
        {
            mdio_setPinValue(PORTC, PIN3, HIGH);
            mdio_setPinValue(PORTC, PIN7, LOW);
            mdio_setPinValue(PORTD, PIN3, LOW);
        }
        else if(au16_value > 250 && au16_value <= 700)
        {
            mdio_setPinValue(PORTC, PIN3, LOW);
            mdio_setPinValue(PORTC, PIN7, HIGH);
            mdio_setPinValue(PORTD, PIN3, LOW);
        }
        else
        {
            mdio_setPinValue(PORTC, PIN3, LOW);
            mdio_setPinValue(PORTC, PIN7, LOW);
            mdio_setPinValue(PORTD, PIN3, HIGH);            
        }
    }

    return 0;
}