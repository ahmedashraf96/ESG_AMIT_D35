#include "stdio.h"

typedef unsigned char u8_t;
typedef unsigned short int u16_t;
typedef unsigned long int u32_t;

typedef signed char s8_t;
typedef signed short int s16_t;
typedef signed long int s32_t;

typedef float f32_t;
typedef double f64_t;


extern u8_t n;

void function(void);

void function(void)
{
    printf("The n value is: %d\n", n);
}