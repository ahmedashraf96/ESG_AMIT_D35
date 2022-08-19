#include "stdio.h"
#include "stdlib.h"
#include "typedefs.h"

int main(void)
{
    u8_t i=0;
    u32_t* ptr = NULL;
    u16_t* ptr2 = NULL;

    ptr = (u32_t*)malloc(10 * sizeof(u32_t));
    ptr2 = (u16_t*)calloc(20, sizeof(u16_t));

    realloc(ptr2, 10*sizeof(u16_t));

    printf("Malloc function......\n");

    for(i=0; i < 10; i++)
    {
        printf("The #%d is: %d\n", i+1, ptr[i]);
    }

    for(i=0; i < 10; i++)
    {
        ptr[i] = i * 100;
    }
    
    for(i=0; i < 10; i++)
    {
        printf("The #%d is: %d\n", i+1, ptr[i]);
    }

    free(ptr);

    printf("Calloc function......\n");

    for(i=0; i < 10; i++)
    {
        printf("The #%d is: %d\n", i+1, ptr2[i]);
    }

    for(i=0; i < 10; i++)
    {
        ptr2[i] = i + 100;
    }

    for(i=0; i < 10; i++)
    {
        printf("The #%d is: %d\n", i+1, ptr2[i]);
    }

    free(ptr2);
    
    return 0;
}