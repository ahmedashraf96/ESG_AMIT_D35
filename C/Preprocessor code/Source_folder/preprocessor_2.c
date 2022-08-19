#include "stdio.h"
#include "../Header_folder/preprocessor.h"

#define FALSE            (0)
#define TRUE             (1)
#define CHOOSE_X_VALUE   (3)
#define z  200
#undef z
#define m 5000

#if CHOOSE_X_VALUE == TRUE
    u8_t x = 200;
#elif CHOOSE_X_VALUE == FALSE
    u8_t x = 100;
#else
    u8_t x = 0;
#endif


#ifdef m
    #warning "m is defined"
#endif

#ifndef m
    #error "m is not defined"
#endif

int main(void)
{
    printf("%d", x);    

    #ifdef z
        printf("%d", z);
    #endif

    #ifndef z
        printf("The z macro is undefined");
    #endif   

    printf("%d", m);

    if(m == 5000)
    {
        //#error "m equals 5000"
    }
    else
    {
        #warning "m not equals 5000"
    }

    return 0;
}
