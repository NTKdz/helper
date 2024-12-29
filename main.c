#include <stdio.h>
#include "book.h"

int main()
{
    Book books[50];
    int n = 0;
    int choice;

    loadBooksFromFile(books, &n);

    do
    {
        printf("\n=========== MENU ===========\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma sach\n");
        printf("5. Cap nhat thong tin sach theo ma sach\n");
        printf("6. Tim kiem sach theo ten sach\n");
        printf("7. Thoat\n");
        printf("============================\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            inputBook(books, &n);
            break;
        case 2:
            printBook(books, n);
            break;
        case 3:
            addBook(books, &n);
            break;
        case 4:
            deleteBook(books, &n);
            break;
        case 5:
            updateBook(books, n);
            break;
        case 6:
            findBook(books, n);
            break;
        case 7:
            saveBooksToFile(books, n);
            break;
        default:
            printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (choice != 7);

    return 0;
}
