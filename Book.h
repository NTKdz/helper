#ifndef BOOK_H
#define BOOK_H

typedef struct
{
    int id;
    char bookName[100];
    char author[50];
    long long price;
    char category[50];
} Book;

void inputBook(Book book[], int *n);
void printBook(Book book[], int n);
void addBook(Book book[], int *n);
void editBook(Book book[], int *n);
void deleteBook(Book book[], int *n);
void findBook(Book book[], int n);
void aarrangeBook(Book book[], int n);
void saveBooksToFile(Book book[], int n);
void loadBooksFromFile(Book book[], int *n);

#endif