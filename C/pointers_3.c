#include <stdio.h>

int* func(void);

int main(void)
{
    int x = 800;
    //int* ptr; //wild pointer
    int* ptr = &x;
    int** ptr2 = &ptr;

    int *xptr = func(); //Dangling pointer

    printf("The value of pointer is: %p\n", ptr);
    printf("The value of variable in pointer is: %d\n", *ptr);

    printf("The value of x pointer is: %p\n", xptr);

    printf("The value of pointer 2 is: %p\n", ptr2);
    printf("The value of *pointer 2 is: %p\n", *ptr2);
    printf("The value of **pointer 2 is: %d\n", **ptr2);


    return 0;
}

int* func(void)
{
    int x = 100;

    return &x;
}