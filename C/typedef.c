#include "stdio.h"

typedef unsigned char u8_t;
typedef unsigned short int u16_t;
typedef unsigned long int u32_t;

typedef signed char s8_t;
typedef signed short int s16_t;
typedef signed long int s32_t;

typedef float f32_t;
typedef double f64_t;

//static u8_t n = 10;
u8_t n = 10;
u16_t x; //2 bytes (unsigned)
s32_t y; //4 bytes (signed)

void function(void);

void func(void)
{
    static u8_t m = 0;

    m++;

    printf("Printing the m value: %d\n", m);

    return;
}

int main(void)
{   
    u8_t z = 0;
    
    printf("The size of u8_t is: %d bytes\n", sizeof(u8_t));
    printf("The size of u16_t is: %d bytes\n", sizeof(u16_t));
    printf("The size of s32_t is: %d bytes\n", sizeof(s32_t));
    printf("The size of f32_t is: %d bytes\n", sizeof(f32_t));
    printf("The size of f64_t is: %d bytes\n", sizeof(f64_t));

    while (z < 10)
    {
        func();
        z++;
    }
    
    function();

    return 0;
}


