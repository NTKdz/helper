
#include <stdio.h>
#include <string.h>
#include "book.h"
#include <stdbool.h>

bool isDuplicateName(Book books[], int n, const char* name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(books[i].bookName, name) == 0) {
            return true;
        }
    }
    return false;
}

void inputBook(Book book[], int *n) // Yeucau1
{
    printf("Nhap so luong sach muon them: \n");
    scanf("%d", n);
    getchar();

    for (int i = 0; i < *n; i++)
    {
        book[i].id = i + 1;
        printf("Moi ban nhap vao ten sach: \n");
        fgets(book[i].bookName, 100, stdin);
        book[i].bookName[strcspn(book[i].bookName, "\n")] = '\0';
        printf("Moi ban nhap vao ten tac gia: \n");
        fgets(book[i].author, 50, stdin);
        book[i].author[strcspn(book[i].author, "\n")] = '\0';
        printf("Moi ban nhap vao gia tien: \n");
        scanf("%lld", &book[i].price);
        getchar();
        printf("Moi ban nhap vao the loai: \n");
        fgets(book[i].category, 50, stdin);
        book[i].category[strcspn(book[i].category, "\n")] = '\0';
    }
}

void printBook(Book book[], int n)  //Yeucau 2
{

    printf("|_____________________________________________IN TOAN BO CAC SACH___________________________________________|\n");
    printf("| %-2s | %-30s | %-20s | %-20s | %-15s |\n", "Ma sach ", "Ten sach", "Gia tien", "Tac gia", "The loai");
    printf("|__________|________________________________|______________________|______________________|_________________|\n");
    for (int i = 0; i < n; i++) {
    printf("| %-8d | %-30s | %-20d | %-20s | %-15s |\n", book[i].id, book[i].bookName, book[i].price, book[i].author, book[i].category);
        }
        printf("\n");
    }

void addBook(Book book[], int *n) //Yeucau3
{
    getchar();
    book[*n].id = *n + 1;
    printf("Moi ban nhap vao ten sach: \n");
    fgets(book[*n].bookName, 100, stdin);
    book[*n].bookName[strcspn(book[*n].bookName, "\n")] = '\0';
    printf("Moi ban nhap vao ten tac gia: \n");
    fgets(book[*n].author, 50, stdin);
    book[*n].author[strcspn(book[*n].author, "\n")] = '\0';
    printf("Moi ban nhap vao gia tien: \n");
    scanf("%lld", &book[*n].price);
    getchar();
    printf("Moi ban nhap vao the loai: \n");
    fgets(book[*n].category, 50, stdin);
    book[*n].category[strcspn(book[*n].category, "\n")] = '\0';
    (*n)++;
}


void editBook(Book book[], int *n) // yeucau4
{
    int id, found = 0;
    int choice;

    do
    {
        printf("Nhap ID sach muon sua (nhap -1 de quay lai menu): ");
        scanf("%d", &id);

        if (id == -1)
        {
            printf("Quay lai menu chinh...\n");
            return;
        }

        for (int i = 0; i < *n; i++)
        {
            if (book[i].id == id)
            {
                found = 1;
                printf("\nThong tin hien tai cua sach:\n");
                printf("ID: %d\n", book[i].id);
                printf("Ten sach: %s\n", book[i].bookName);
                printf("Tac gia: %s\n", book[i].author);
                printf("Gia sach: %d\n", book[i].price);
                printf("The Loai: %s\n", book[i].category);

                printf("\nNhap thong tin moi:\n");
                printf("Ten sach moi: ");
                getchar();
                fgets(book[i].bookName, sizeof(book[i].bookName), stdin);
                book[i].bookName[strcspn(book[i].bookName, "\n")] = 0;
                printf("Tac gia moi: ");
                fgets(book[i].author, sizeof(book[i].author), stdin);
                book[i].author[strcspn(book[i].author, "\n")] = 0;
                printf("Gia moi: ");
                scanf("%d", &book[i].price);
                printf("The loai moi: ");
                getchar();
                fgets(book[i].category, sizeof(book[i].category), stdin);
                book[i].category[strcspn(book[i].category, "\n")] = 0;

                printf("\nSua thong tin sach thanh cong!\n");
                break;
            }
        }

        if (!found)
        {
            printf("\nKhong tim thay sach voi ID: %d\n", id);
        }

        do
        {
            printf("\n1. Nhap lai ID\n");
            printf("2. Quay lai menu chinh\n");
            printf("Lua chon cua ban: ");
            scanf("%d", &choice);

            if (choice == 2)
            {
                printf("Quay lai menu chinh...\n");
                return;
            }
            else if (choice != 1)
            {
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
            }
        } while (choice != 1 && choice != 2);

    } while (1);
}


void deleteBook(Book book[], int *n) //Yeucau5
{
    int position;
    printf("Moi ban nhap vao vi tri muon xoa:");
    if (scanf("%d", &position)!=1){
        printf("Lỗi: Vui lòng nhập một số nguyên hợp lệ!\n");
        while (getchar() != '\n'); 
        return;
    }
    int findIndex = -1;
    for (int i = 0; i < *n; i++)
    {
        if (book[i].id == position)
        {
            findIndex = i;
            printf("Da xoa sach thanh cong !");
            break;
        }
    }
    if (findIndex == -1)
    {
        printf("Khong tim thay sach de xoa\n");
        fflush(stdin);
    }
    else
    {
        for (int i = findIndex; i < *n - 1; i++)
        {
            book[i] = book[i + 1];
        }
        (*n)--;
    }
}

void findBook(Book book[], int n) //Yeucau6
 {
   char search[1000];
    printf("Nhap ten sach ma ban muon tim: ");
    scanf(" %[^\n]", search);
    bool found = false;

    printf("|_____________________________________________THONG TIN SACH TIM DUOC________________________________________|\n");
    printf("| %-8s | %-30s | %-20s | %-20s | %-15s |\n", "Ma sach", "Ten sach", "Gia tien", "Tac gia", "The loai");
    printf("|__________|________________________________|______________________|______________________|_________________|\n");

    for (int i = 0; i < n; i++)
    {
        if (strstr(book[i].bookName, search) != NULL)
        {
            printf("| %-8d | %-30s | %-20d | %-20s | %-15s |\n", book[i].id, book[i].bookName, book[i].price, book[i].author, book[i].category);
            found = true;
        }
    }

    if (!found)
    {
        printf("| Khong tim thay sach co chuoi '%s' trong ten!                                                           |\n", search);
    }

    printf("|___________________________________________________________________________________________________________|\n");
}

void aarrangeBook(Book book[], int n) //Yeucau7
 {
int sortOption;
    printf("Chon cach sap xep:\n");
    printf("1. Sap xep theo gia tang dan\n");
    printf("2. Sap xep theo gia giam dan\n");
    printf("Lua chon cua ban: ");
    scanf("%d", &sortOption);

    if (sortOption != 1 && sortOption != 2)
    {
        printf("Lua chon khong hop le. Vui long nhap lai.\n");
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            bool condition = (sortOption == 1) ? (book[j].price > book[j + 1].price)
                                               : (book[j].price < book[j + 1].price);
            if (condition)
            {
                Book temp = book[j];
                book[j] = book[j + 1];
                book[j + 1] = temp;
            }
        }
    }

    printf("Danh sach sau khi sap xep:\n");
    printBook(book, n);

}





void saveBooksToFile(Book book[], int n) //yeucau8
{
    FILE *file = fopen("books.bin", "wb");
    if (file)
    {
        fwrite(&n, sizeof(int), 1, file);
        fwrite(book, sizeof(Book), n, file);
        fclose(file);
        printf("Da luu thong tin sach vao file.\n");
    }
    else
    {
        printf("Khong the mo file de luu.\n");
    }
}

void loadBooksFromFile(Book books[], int *n)
{
    FILE *file = fopen("books.bin", "rb");
    if (file)
    {
        fread(n, sizeof(int), 1, file);
        fread(books, sizeof(Book), *n, file);
        fclose(file);
        printf("Da tai thong tin sach tu file.\n");
    }
    else
    {
        printf("Khong the mo file de doc.\n");
        *n = 0;
    }
}
