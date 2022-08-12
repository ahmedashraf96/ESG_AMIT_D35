#include <stdio.h>

int main(void)
{
    int x = 10;
    float y = 100.56;
    int z;
    float w;

    printf("Enter the value of z:");
    scanf("%d",&z);

    printf("Enter the value of w:");
    scanf("%f",&w);

    printf("The value of x is %d\n", x);
    printf("The value of y is %.2f\n", y);
    printf("The value of z is %i\n", z);
    printf("The value of w is %.2f\n", w);

    printf("%d", x+z);

    /**
     * cmd: a , b
     * sum = a + b
     * print: sum
     * 
     */
    
    return 0;
}
