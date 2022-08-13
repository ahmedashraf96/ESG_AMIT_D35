#include "stdio.h"

typedef unsigned char u8_t;
typedef unsigned short u16_t;
typedef unsigned long u32_t;


typedef union
{
    u8_t data_byte;

    struct
    {
        u8_t bit0:1;
        u8_t bit1:1;
        u8_t bit2:1;
        u8_t bit3:1;
        u8_t bit4:1;
        u8_t bit5:1;
        u8_t bit6:1;
        u8_t bit7:1;
    }data_bit;        
}data_t;

int main(void)
{
    data_t data_obj;

    printf("The size of union is: %d\n", sizeof(data_t));

    data_obj.data_byte = 200;

    printf("The data byte equals: %d\n", data_obj.data_byte);

    printf("The data byte value in binary: %d %d %d %d %d %d %d %d\n", data_obj.data_bit.bit7,
                                                                       data_obj.data_bit.bit6,
                                                                       data_obj.data_bit.bit5,
                                                                       data_obj.data_bit.bit4,
                                                                       data_obj.data_bit.bit3,
                                                                       data_obj.data_bit.bit2,
                                                                       data_obj.data_bit.bit1,
                                                                       data_obj.data_bit.bit0     
    );   

    return 0;
}