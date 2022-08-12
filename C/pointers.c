#include <stdio.h>

int main(void)
{
    int x = 3000;
    int y = 50;

    char *ptr0 = (char *)&x;
    int *ptr1 = &x;
    int *ptr2 = &y;

    printf("*ptr0 is: %d\n", *ptr0);
    printf("*ptr1 is: %d\n", *ptr1);


    printf("x before change is: %d\n",x);

    *ptr1 = 80;

    printf("x after change is: %d\n",x);
    printf("x address is: %p\n", ptr1);

    printf("y before change is: %d\n",y);

    *ptr2 = 100;

    printf("y after change is: %d\n",y);
    printf("y address is: %p\n", ptr2);

    return 0;
}