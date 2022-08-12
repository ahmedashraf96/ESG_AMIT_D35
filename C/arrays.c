#include <stdio.h>

void printArray(int* pArr, int size);
int* getArray(void);

int arr[] = {10, 20, 30, 40, 50, 60};

int main(void)
{
    int looping_var;
    int* ptr = NULL;
    
    printf("The size of arr is: %d\n", sizeof(arr));
    printf("The location value is: %d\n", arr[5]);

    for(looping_var = 0; looping_var < 6; looping_var++)
    {
        printf("%d ", arr[looping_var]);
    }

    printf("\nAddress of array is: %p\n", arr);
    printf("Address of array is: %p\n", ptr);

    printArray(arr, 6);

    ptr = getArray();

    printf("\n");

    for(looping_var = 0; looping_var < 6; looping_var++)
    {
        printf("%d ", ptr[looping_var]);
    }

    return 0;
}

void printArray(int* pArr, int size)
{
    int looping_var;

    for(looping_var = 0; looping_var < size; looping_var++)
    {
        printf("%d ", *(pArr + looping_var));
    }

    return;
}

int* getArray(void)
{
    arr[0] = 200;
    arr[4] = 1000;

    return arr;
}