#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "HLCD_interface.h"
#include "util/delay.h"

int main(void)
{
    hlcd_init();

    hlcd_displayPosition(LCD_ROW_1, LCD_COL_3);

    _delay_ms(3000);

    hlcd_displayString((u8_t*)"Ahmed");

    while(1)
    {
    }

    return 0;
}