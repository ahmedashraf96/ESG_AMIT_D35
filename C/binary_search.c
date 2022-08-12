#include <stdio.h>

int main(void)
{
    int max = 0, min = 0, mid = 0;
    int key = 0;
    int arr[] = {10, 20, 30, 40, 50, 60};
    int flag = 0;

    printf("Enter a key value to search for it: ");
    scanf("%d", &key);

    max = 5;

    while(min <= max)
    {
        mid = (max + min) / 2;

        if(arr[mid] == key)
        {
            flag = 1;
            break;
        }
        else if(arr[mid] < key)
        {
            min = mid + 1;
        }
        else if(arr[mid] > key)
        {
            max = mid - 1;
        }
        else
        {
            /*Do nothing*/
        }
    }

    if(flag == 1)
    {
        printf("Element is found!, Index: %d\n", mid);
    }
    else
    {
        printf("Element is not found!");
    }

    return 0;
}