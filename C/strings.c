#include "stdio.h"
#include "string.h"

int main(void)
{
    unsigned char str1[] = {'A', 'h', 'm', 'e', 'd', '\0'};
    unsigned char str2[] = "Mohamed";
    unsigned char* str_ptr = "Mohanad";

    printf("Your first name is: %s\n", str1);
    printf("Your second name is: %s\n", str2);
    printf("Your third name is: %s\n", str_ptr);

    strcpy(str1, "Loay");
    //strcpy(str_ptr, "Mahmoud");

    //str_ptr[5] = 'A';    

    printf("Your first name is: %s\n", str1);
    printf("Your second name is: %s\n", str2);
    printf("Your third name is: %s\n", str_ptr);

    return 0;
}