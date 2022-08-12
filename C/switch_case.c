#include <stdio.h>

int main(void)
{
    int y = 0;

    switch(y)
    {
        case 0:
            printf("The value of y is 0\n");
            break;

        case 1:
            printf("The value of y is 1\n");
            break;

        case 5:
            printf("The value of y is 5\n");
            break;

        case 10:
            printf("The value of y is 10\n");
            break;

        case 15:
            printf("The value of y is 15\n");
            break;

        case 20:
            printf("The value of y is 20\n");
            break;

        default:
            printf("We entered the default case");
            break;          
    }

    return 0;
}