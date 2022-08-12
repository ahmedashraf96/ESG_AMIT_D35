#include <stdio.h>

int main(void)
{
    int x = 0;
    int y = 0;
    
    printf("%d\n", x++); //-> x++ -> 1.operation(printing) 2.Execute Adding
    printf("%d\n", ++x); //-> ++x -> 1.Exceute Adding 2.operation (printing)

    y = ++x;
    y = x++;

    printf("%d\n", y);
    printf("%d\n", x);

    for(x = 0; x > 10; ++x)
    {
        printf("%d.",x);
        printf("Ahmed\n");
    }

    printf("x value is: %d", x);
    return 0;
}