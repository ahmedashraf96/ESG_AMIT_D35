#include "stdio.h"
#include "typedefs.h"

u32_t arr[3][2] = {
                    {10, 20},
                    {30, 40},
                    {50, 60}
                  };
u8_t i;
u8_t j;
u32_t* ptr = arr;

int main(void)
{
    printf("The size of array: %d\n", sizeof(arr));

    arr[2][1] = 100;

    **arr = 200;
    *(ptr+1) = 300;

    printf("%p\n", ptr);
    printf("%p\n", arr);

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 2; j++)
        {
            printf("%ld ", *(*(arr + i) + j)); //arr[i][j]
        }
        
        printf("\n");
    }

    return 0;
}