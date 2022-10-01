#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "avr/interrupt.h"
#include "MDIO_interface.h"
#include "MEXTI_interface.h"

void func(void)
{
    mdio_togglePinValue(PORTC, PIN2);
    return;
}

int main(void)
{
    mdio_setPinStatus(PORTC, PIN2, OUTPUT);
    mdio_setPinStatus(PORTD, PIN2, INPUT_FLOAT);

    mexti_enableExternalInterrupt(INT0_REQ_NUM);

    mexti_attachISR(INT0_REQ_NUM, RISING_EDGE_MODE, func);

    while(1);
    
    return 0;
}