#include "stdio.h"

typedef unsigned char u8_t;
typedef unsigned short u16_t;


#pragma pack(1)
typedef struct
{
    u8_t x:4;
    u8_t y:4;
    u16_t z:10;
}data_t;


int main(void)
{
    data_t data_obj = {15, 20, 500};

    printf("The values of x= %d  y= %d  z= %d\n", data_obj.x, data_obj.y, data_obj.z);
    printf("The size of structure is: %d\n", sizeof(data_t));
    return 0;
}