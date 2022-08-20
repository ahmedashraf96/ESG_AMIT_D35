#include "stdio.h"
#include "typedefs.h"

u8_t stack_pointer = 0;
u8_t stack_arr[5];

void stack_push(u8_t data);
void stack_pop(u8_t* pop_data);

int main(void)
{
    u8_t x;

    stack_push(10);
    stack_push(20);
    stack_push(30);
    stack_push(40);
    stack_push(50);

    stack_push(60);
    stack_push(70);

    stack_pop(&x);
    printf("The popped data is: %d\n", x);
    stack_pop(&x);
    printf("The popped data is: %d\n", x);
    stack_pop(&x);
    printf("The popped data is: %d\n", x);
    stack_pop(&x);
    printf("The popped data is: %d\n", x);
    stack_pop(&x);
    printf("The popped data is: %d\n", x);

    stack_pop(&x);
    printf("The popped data is: %d\n", x);

    return 0;
}

void stack_push(u8_t data)
{
    if(stack_pointer == 5)
    {
        printf("Stack is Full!\n");
    }
    else
    {
        stack_arr[stack_pointer] = data;
        stack_pointer++;
    }

    return;
}

void stack_pop(u8_t* pop_data)
{
    if(stack_pointer == 0)
    {
        printf("The stack is empty!\n");
    }
    else
    {
        stack_pointer--;
        *pop_data = stack_arr[stack_pointer];
    }

    return;
}