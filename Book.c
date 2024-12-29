#include "Book.h"

void inputBook(Book book[], int *n) {
    printf("Nhap so luong sach muon them: \n");
    scanf("%d", n);
    getchar();
    for (int i = 0; i < *n; i++) {
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

void printBook(Book book[], int n) {
    printf("In toan bo cac sach: \n");
    for (int i = 0; i < n; i++) {
        printf("Ma sach: %d\n", book[i].id);
        printf("Ten sach: %s\n", book[i].bookName);
        printf("Gia tien: %lld\n", book[i].price);
        printf("Tac gia: %s\n", book[i].author);
        printf("The loai: %s\n", book[i].category);
    }
    printf("\n");
}

void addBook(Book book[], int *n) {
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

void deleteBook(Book book[], int *n) {
    int idToDelete;
    printf("Nhap ma sach muon xoa: ");
    scanf("%d", &idToDelete);

    int index = -1;
    for (int i = 0; i < *n; i++) {
        if (book[i].id == idToDelete) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Khong tim thay ma sach de xoa.\n");
        return;
    }

    for (int i = index; i < *n - 1; i++) {
        book[i] = book[i + 1];
    }
    (*n)--;
    printf("Da xoa sach thanh cong.\n");
}

void updateBook(Book book[], int n) {
    int idToUpdate;
    printf("Nhap ma sach muon cap nhat: ");
    scanf("%d", &idToUpdate);

    int index = -1;
    for (int i = 0; i < n; i++) {
        if (book[i].id == idToUpdate) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Khong tim thay ma sach de cap nhat.\n");
        return;
    }

    getchar();
    printf("Nhap ten sach moi: \n");
    fgets(book[index].bookName, 100, stdin);
    book[index].bookName[strcspn(book[index].bookName, "\n")] = '\0';
    printf("Nhap ten tac gia moi: \n");
    fgets(book[index].author, 50, stdin);
    book[index].author[strcspn(book[index].author, "\n")] = '\0';
    printf("Nhap gia tien moi: \n");
    scanf("%lld", &book[index].price);
    getchar();
    printf("Nhap the loai moi: \n");
    fgets(book[index].category, 50, stdin);
    book[index].category[strcspn(book[index].category, "\n")] = '\0';

    printf("Da cap nhat thong tin sach thanh cong.\n");
}

void findBook(Book book[], int n) {
    char searchName[100];
    getchar();
    printf("Nhap ten sach can tim: ");
    fgets(searchName, 100, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(book[i].bookName, searchName)) {
            printf("Ma sach: %d\n", book[i].id);
            printf("Ten sach: %s\n", book[i].bookName);
            printf("Gia tien: %lld\n", book[i].price);
            printf("Tac gia: %s\n", book[i].author);
            printf("The loai: %s\n", book[i].category);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay sach voi ten da nhap.\n");
    }
}

void saveBooksToFile(Book book[], int n) {
    FILE *file = fopen("books.dat", "wb");
    if (!file) {
        printf("Khong the mo file de luu.\n");
        return;
    }
    fwrite(&n, sizeof(int), 1, file);
    fwrite(book, sizeof(Book), n, file);
    fclose(file);
    printf("Da luu thong tin sach thanh cong.\n");
}

void loadBooksFromFile(Book books[], int *n) {
    // FILE *file = fopen("books.dat", "rb");
    // if (!file) {
    //     printf("Khong the mo file de doc.\n");
    //     *n = 0;
    //     return;
    // }
    // fread(n, sizeof(int), 1, file);
    // fread(books, sizeof(Book), *n, file);
    // fclose(file);
    printf("Da doc thong tin sach thanh cong.\n");
}
