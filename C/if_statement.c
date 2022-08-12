#include <stdio.h>

int main(void)
{
    int student_grade;

    scanf("%d", &student_grade);

    if(student_grade < 0)
    {
        printf("The student degree is: Invalid!");
    }
    else if((student_grade <= 49))
    {
        printf("The student degree is: Failed");
    }
    else if((student_grade <= 70))
    {
        printf("The student degree is: Passed");
    }
    else if((student_grade <= 80))
    {
        printf("The student degree is: Good");
    }
    else if((student_grade <= 90))
    {
        printf("The student degree is: Very good");
    }
    else if(student_grade <= 100)
    {
       printf("The student degree is: Excellent"); 
    }
    else
    {
        printf("The student degree is: Invalid!");
    }
    
    return 0;
}