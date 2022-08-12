#include <stdio.h>

int main(void)
{
    int x = 0;
    int y = 0;
    int number = 0;
    int fact = 1;

    scanf("%d", &number);

    fact = number;

    do
    {
        fact *= (number - 1);
        number--;
    } while (number > 1);

    printf("%d\n", fact);

    for(y = 0; y < 3; y++)
    {
        for(x = 0; x < 10; x++)
        {
            if(x == 5)
            {
                break;
            }

            printf("%d\n", x * y);
        }
    }


    printf("Second loop\n");
    for(x = 0; x < 10; x++)
    {
        if(x == 5)
        {
            continue;
        }

        printf("%d\n", x);
    }


    while(1)
    {
        /*Infinite loop*/
    }

    for(;;)
    {
        /*Infinite loop*/
    }

    return 0;
}