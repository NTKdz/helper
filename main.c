#include <stdio.h>
#include "book.h"
#include "account.h"
#include <string.h>
#include <stdlib.h>
#include <conio.h>

void showMenu();
void showAdminMenu();
void loadAdminFromFile(Admin *admin);
void saveAdminToFile(Admin *admin);

int main()
{
    Client clients[50];
    Book books[50];
    int n = 0;
    int m = 0;
    int choice0, choice1, choice2;
    Admin admin;

    loadAdminFromFile(&admin); // Load admin info from file
    loadBooksFromFile(books, &n);
    loadClientFromFile(clients, &m);

    do
    {
        printf("=================== Quan li thu vien ===================\n");
        printf("[1]. Admin\n");
        printf("[2]. Exit\n");
        printf("=======================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice0);
        system("cls");

        switch (choice0)
        {
        case 1:
        {
            char username[50], password[50];

            while (1)
            {
                printf("*** Login Admin ***\n");
                printf("Account Admin: ");
                scanf("%s", username);

                // Check if username matches
                if (strcmp(username, admin.username) == 0)
                {
                    break;
                }
                else
                {
                    printf("Tai khoan khong dung. Vui long nhap lai !!\n");
                }
            }

            while (1)
            {
                printf("Password: ");
                int i = 0;
                char ch;
                while ((ch = _getch()) != '\r')
                { // Using _getch to hide password input
                    if (ch == '\b')
                    {
                        if (i > 0)
                        {
                            i--;
                            printf("\b \b");
                        }
                    }
                    else
                    {
                        password[i] = ch;
                        i++;
                        printf("*");
                    }
                }
                password[i] = '\0'; // Null-terminate the password string
                if (strcmp(password, admin.password) == 0)
                {
                    break;
                }
                else
                {
                    printf("\nMat khau khong dung. Vui long nhap lai !!\n");
                }
            }
            system("cls");

            do
            {
                printf("==================== Quan li ====================\n");
                printf("1. Quan li sach\n");
                printf("2. Quan li khach hang\n");
                printf("3. Thoat\n");
                printf("=================================================\n");
                printf("Enter your choice: ");
                scanf("%d", &choice2);
                system("cls");

                switch (choice2)
                {
                case 1:

                    do
                    {
                        showMenu();
                        scanf("%d", &choice1);

                        switch (choice1)
                        {
                        case 1:
                            do
                            {
                                printf("\n=== Nhap thong tin sach ===\n");
                                inputBook(books, &n);
                                printf("\n1. Quay lai menu chinh\n");
                                printf("2. Tiep tuc nhap thong tin sach\n");
                                printf("Lua chon cua ban: ");
                                scanf("%d", &choice1);
                            } while (choice1 == 2);
                            choice1 = 0;
                            break;
                        case 2:
                            do
                            {
                                printf("\n=== Thong tin cac sach ===\n");
                                printBook(books, n);
                                printf("\n1. Quay lai menu chinh\n");
                                printf("Lua chon cua ban: ");
                                scanf("%d", &choice1);
                            } while (choice1 != 1);
                            choice1 = 0;
                            break;
                        case 3:
                            do
                            {
                                printf("\n=== Them sach vao vi tri ===\n");
                                addBook(books, &n);
                                printf("\n1. Quay lai menu chinh\n");
                                printf("2. Tiep tuc them sach\n");
                                printf("Lua chon cua ban: ");
                                scanf("%d", &choice1);
                            } while (choice1 == 2);
                            choice1 = 0;
                            break;
                        case 4:
                            do
                            {
                                printf("\n=== Sua thong tin sach ===\n");
                                editBook(books, &n);
                                printf("\n1. Quay lai menu chinh\n");
                                printf("2. Sua thong tin sach khac\n");
                                printf("Lua chon cua ban: ");
                                scanf("%d", &choice1);
                            } while (choice1 == 2);
                            choice1 = 0;
                            break;
                        case 5:
                            do
                            {
                                printf("\n=== Xoa sach ===\n");
                                deleteBook(books, &n);
                                printf("\n1. Quay lai menu chinh\n");
                                printf("2. Xoa sach khac\n");
                                printf("Lua chon cua ban: ");
                                scanf("%d", &choice1);
                            } while (choice1 == 2);
                            choice1 = 0;
                            break;
                        case 6:
                            do
                            {
                                printf("\n=== Tim kiem sach theo ten ===\n");
                                findBook(books, n);
                                printf("\n1. Quay lai menu chinh\n");
                                printf("2. Tim sach khac\n");
                                printf("Lua chon cua ban: ");
                                scanf("%d", &choice1);
                            } while (choice1 == 2);
                            choice1 = 0;
                            break;
                        case 7:
                            printf("\n=== Sap xep sach theo gia ===\n");
                            aarrangeBook(books, n);
                            break;
                        case 8:
                            printf("\n=== Luu thong tin vao file ===\n");
                            saveBooksToFile(books, n);
                            break;
                        case 9:
                            printf("\nReturning to main menu...\n");
                            break;
                        default:
                            printf("Invalid choice! Please try again.\n");
                        }
                    } while (choice1 != 9);
                    break;

                case 2:
                    do
                    {
                        printf("\n=========== QUAN LI KHACH HANG ===========\n");
                        printf("1. Hien thi danh sach khach hang\n");
                        printf("2. Them khach hang\n");
                        printf("3. Quay lai menu quan li\n");
                        printf("==========================================\n");
                        printf("Lua chon cua ban: ");
                        scanf("%d", &choice1);

                        switch (choice1)
                        {
                        case 1:
                            printf("\nDanh sach khach hang:\n");
                            printfclient(clients, m);
                            break;
                        case 2:
                            printf("\nThem khach hang:\n");
                            addclient(clients, &m);
                            break;
                        case 3:
                            break;
                        default:
                            printf("Invalid choice! Please try again.\n");
                        }
                    } while (choice1 != 3);
                    break;

                case 3:
                    printf("\nExiting Admin Menu...\n");
                    break;

                default:
                    printf("Invalid choice! Please try again.\n");
                }
            } while (choice2 != 3);
            break;
        }

        case 2:
            printf("Exiting Program...\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }

    } while (choice0 != 2);

    return 0;
}

void showMenu()
{
    printf("\n=========== MENU ===========\n");
    printf("1. Nhap thong tin sach\n");
    printf("2. Hien thi thong tin sach\n");
    printf("3. Them sach vao vi tri\n");
    printf("4. Sua thong tin sach\n");
    printf("5. Xoa sach theo ma\n");
    printf("6. Tim sach theo ten\n");
    printf("7. Sap xep sach theo gia\n");
    printf("8. Luu thong tin vao file\n");
    printf("9. Quay lai menu chinh\n");
    printf("============================\n");
    printf("Lua chon cua ban: ");
}