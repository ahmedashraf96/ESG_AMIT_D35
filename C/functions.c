#include <stdio.h>

void printMyName(void); //Header
void add_1(void);
void add_2(int x, int y);
int add_3(int x, int y);
void bitwise(unsigned char number, unsigned char bit_number);

int main(void)
{
    printMyName(); //Calling

    add_1();

    bitwise(20, 2);

    return 0;
}

void printMyName(void) //Body
{
    printf("Ahmed\n");
}


void add_1(void)
{
    int x = 10;
    int y = 20;
    printf("%d\n", x+y);

    add_2(50, 60);

    printf("%d\n", add_3(40, 80));

    return;
}

void add_2(int x, int y)
{
    printf("%d\n", x+y);
    return;
}

int add_3(int x, int y)
{
    int z = x+y;
    return z;
}

void bitwise(unsigned char number, unsigned char bit_number)
{
    number ^= (1 << bit_number);

    printf("%d\n", number);

    return;
}
