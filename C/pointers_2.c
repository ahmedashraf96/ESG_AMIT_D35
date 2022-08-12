#include <stdio.h>

int main(void)
{
    int x = 1000000;
    int y = 100000;
    char* ptr = (char*)&x;
    int* xptr = &x;
    int* yptr = &y;
    int z = xptr - yptr;

    xptr += 4;
    yptr += 8;

    printf("The address of x pointer is: %p\n", xptr);
    printf("The address of y pointer is: %p\n", yptr);

    printf("The value of z is: %d\n", z);

    printf("The address of first byte of x is: %p\n", ptr);
    printf("The first byte of x is: %d\n", *ptr);

    ptr++;

    printf("The address of second byte of x is: %p\n", ptr);
    printf("The second byte of x is: %d\n", *ptr);

    ptr++;

    printf("The address of third byte of x is: %p\n", ptr);
    printf("The third byte of x is: %d\n", *ptr);

    ptr ++;

    printf("The address of fourth byte of x is: %p\n", ptr);
    printf("The fourth byte of x is: %d\n", *ptr);


    return 0;
}