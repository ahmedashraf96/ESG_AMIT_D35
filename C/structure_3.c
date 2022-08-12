#include "stdio.h"

typedef unsigned char u8_t;
typedef unsigned short int u16_t;
typedef unsigned long int u32_t;

#pragma pack(1)
typedef struct 
{
    u8_t x;
    u16_t y;
    u16_t m;
    u32_t z;
    u32_t o;
}number_t;

int main(void)
{
    printf("The size of structure is: %d\n", sizeof(number_t));
    return 0;
}