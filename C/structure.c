#include "stdio.h"
#include "string.h"

typedef unsigned char u8_t;
typedef unsigned short int u16_t;
typedef unsigned long int u32_t;

typedef struct
{
    u8_t book_id;
    u8_t book_name[30];
    u8_t book_author[30];
}book_t;

book_t strArr_books[10] =
{
    {100, "Hebta", "Ahmed mourad"},
    {150, "Harry potter", "J.K. Rowling"},
    {200, "Utopia", "Ahmed tawfik"}
};

int main(void)
{
    printf("The size of structure is: %d\n", sizeof(book_t));
    printf("The size of structure array is: %d\n", sizeof(strArr_books));

    strArr_books[3].book_id = 250;
    strcpy(strArr_books[3].book_name,"Fourty");
    strcpy(strArr_books[3].book_author, "Ahmed Elshoqairy");

    printf("Book1 ID is: %d\n",strArr_books[0].book_id);
    printf("Book1 name is: %s\n",strArr_books[0].book_name);
    printf("Book1 author is: %s\n",strArr_books[0].book_author);

    printf("Book2 ID is: %d\n",strArr_books[1].book_id);
    printf("Book2 name is: %s\n",strArr_books[1].book_name);
    printf("Book2 author is: %s\n",strArr_books[1].book_author);

    printf("Book3 ID is: %d\n",strArr_books[2].book_id);
    printf("Book3 name is: %s\n",strArr_books[2].book_name);
    printf("Book3 author is: %s\n",strArr_books[2].book_author);

    return 0;
}