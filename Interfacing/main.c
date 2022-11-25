#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "HEEP_interface.h"
#include "util/delay.h"

int main(void)
{
    u8_t arr[] = "Yamen";
    u8_t arr2[6];
    u8_t var;

    heeprom_init();

    heeprom_writeByte(EEPROM_BLOCK_5, 10, 0x50);

    _delay_ms(10);

    heeprom_writeDataStream(EEPROM_BLOCK_3, 1, arr, 6);

    _delay_ms(10);

    heeprom_readByte(EEPROM_BLOCK_5, 10, &var);

    _delay_ms(10);

    heeprom_readDataStream(EEPROM_BLOCK_3, 1, arr2, 6);

    _delay_ms(10);

    while(1)
    {
    }

    return 0;
}