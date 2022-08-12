#include "stdio.h"

typedef unsigned char u8_t;
typedef unsigned short int u16_t;
typedef unsigned long int u32_t;

typedef signed char s8_t;
typedef signed short int s16_t;
typedef signed long int s32_t;

typedef float f32_t;
typedef double f64_t;


int main(void)
{
    u8_t i;
    u8_t x;
    u8_t y;
    u8_t z;
    const u8_t m = 100;

    const u8_t arr[10] = {10, 20, 30, 40};
    u8_t* const ptr1 = &x;
    u8_t const* ptr2 = &y;
    const u8_t* ptr3 = &z;
    const u8_t* const ptr4 = &x;
    u8_t* ptr5 = &m;

    printf("The value of x is: %d\n", x);

    for(i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    *ptr1 = 100;    
    printf("\nx value is: %d\n", x);

    ptr2++;
    printf("\nThe value is: %d\n", *ptr2);

    ptr3++;
    printf("\nThe value is: %d\n", *ptr3);

    *ptr5 = 200;
    printf("\nThe m value is: %d\n", m);

    return 0;
}