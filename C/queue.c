#include "stdio.h"
#include "typedefs.h"

u8_t head_pointer = 0;
u8_t current_pointer = 0;
u8_t queue_arr[5];

void queue_insert(u8_t data);
void queue_getData(u8_t* recv_data);

int main(void)
{
    u8_t x;

    queue_insert(10);
    queue_insert(20);
    queue_insert(30);
    queue_insert(40);
    queue_insert(50);

    queue_insert(60);
    queue_insert(70);

    queue_getData(&x);
    printf("The data received is: %d\n", x);
    queue_getData(&x);
    printf("The data received is: %d\n", x);
    queue_getData(&x);
    printf("The data received is: %d\n", x);
    queue_getData(&x);
    printf("The data received is: %d\n", x);
    queue_getData(&x);
    printf("The data received is: %d\n", x);

    queue_getData(&x);
    printf("The data received is: %d\n", x);

    return 0;
}

void queue_insert(u8_t data)
{
    if(current_pointer == 5)
    {
        printf("Queue is full!\n");
    }
    else
    {
        queue_arr[current_pointer] = data;
        current_pointer++;
    }

    return;
}

void queue_getData(u8_t* recv_data)
{
    if( (current_pointer == head_pointer) && (head_pointer == 0) )
    {
        printf("Queue is empty!\n");
    }
    else
    {
        *recv_data = queue_arr[head_pointer];
        head_pointer++;
    }

    if( (current_pointer == head_pointer) && (head_pointer != 0) )
    {
        printf("Resetting the queue!\n");
        head_pointer = 0;
        current_pointer = 0;
    }
    else
    {
        /*Do nothing*/
    }

    return;
}