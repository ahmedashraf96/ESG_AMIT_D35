#include "stdio.h"
//#include "D:\Documents\AMIT\Embedded systems group2\C\Preprocessor code\Header_folder\preprocessor.h" //Absolute path
#include "../Header_folder/preprocessor.h" //Relative path


#define x 100
#define y 200

#define ADD(num1, num2)   (num1 + num2)

#define PRINT_MY_NAME()   do\
                          {\
                            printf("My name ");\
                            printf("is: ");\
                            printf("Ahmed");\
                          }while(0)

int main(void)
{
    u16_t z = ADD(x,y);

    printf("%d\n", z);


    if(z > 100)
        PRINT_MY_NAME();
    else
        /*Do nothing*/

    return 0;
}