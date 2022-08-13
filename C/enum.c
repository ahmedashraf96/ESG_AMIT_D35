#include "stdio.h"

typedef enum
{
    saturday = 1,
    sunday,
    monday,
    tuesday,
    wednesday = 10,
    thursday,
    friday
}days_t;

int main(void)
{
    days_t day_obj = friday;

    printf("The size of enum: %d\n", sizeof(days_t));
    printf("The day value is: %d\n", day_obj);

    return 0;
}