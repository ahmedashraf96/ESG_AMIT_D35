#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "HLCD_interface.h"
#include "util/delay.h"

int main(void)
{
    hlcd_init();

    hlcd_displayString((u8_t*)"Ahmed");

    while(1)
    {
    }

    return 0;
}