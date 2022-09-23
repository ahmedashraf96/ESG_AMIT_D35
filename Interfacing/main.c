#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "HLCD_interface.h"
#include "util/delay.h"

int main(void)
{
    hlcd_init();

    hlcd_displayCharacter('A');
    hlcd_displayCharacter('H');
    hlcd_displayCharacter('M');
    hlcd_displayCharacter('E');
    hlcd_displayCharacter('D');

    while(1)
    {
    }

    return 0;
}