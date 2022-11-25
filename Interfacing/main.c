#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "HEEP_interface.h"
#include "util/delay.h"

int main(void)
{
    u8_t arr[] = "Mohamed";
    u8_t arr2[8];
    u8_t var;

    heeprom_init();

    heeprom_writeByte(EEPROM_BLOCK_5, 10, 0x50);

    heeprom_writeDataStream(EEPROM_BLOCK_2, 0, arr, 8);

    heeprom_readByte(EEPROM_BLOCK_5, 10, &var);

    heeprom_readDataStream(EEPROM_BLOCK_2, 0, arr2, 8);

    while(1)
    {
    }

    return 0;
}