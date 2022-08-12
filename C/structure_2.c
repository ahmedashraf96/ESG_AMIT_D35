#include "stdio.h"

typedef unsigned char u8_t;
typedef unsigned short int u16_t;
typedef unsigned long int u32_t;

typedef struct 
{
    u8_t employee_id;
    u8_t employee_name[20];
    u32_t employee_salary;
}employee_t;

employee_t emp1 = {20, "Omar", 6565}, emp2 = {10, "Mostafa", 2000}, emp3;

employee_t* ptr_emp = &emp2;

employee_t print_structure(employee_t* localStr_emp, u8_t employee_idx);

employee_t print_structure(employee_t* localStr_emp, u8_t employee_idx)
{
    employee_t localStr_2 = {200, "Mohanad", 3000};

    printf("Employee %d id is: %d\n", employee_idx, localStr_emp -> employee_id);
    printf("Employee %d name is: %s\n", employee_idx, localStr_emp -> employee_name);
    printf("Employee %d salary is: %ld\n", employee_idx, localStr_emp -> employee_salary);

    return localStr_2;
}

int main(void)
{

    emp3 = print_structure(&emp2, 2);

    print_structure(&emp3, 3);

    return 0;
}