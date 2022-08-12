#include <stdio.h>

int fact(int x);

int main(void)
{
    int var;

    printf("Enter the number: ");
    scanf("%d", &var);

    printf("The factorial is: %d", fact(var));

    return 0;
}