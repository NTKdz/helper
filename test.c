#include <stdio.h>
#include <string.h>

typedef struct {
    char username[50];
    char password[50];
} Account;

void createSampleAdminAccount() {
    FILE *file = fopen("accounts.bin", "wb");
    if (!file) {
        printf("Khong the mo hoac tao file accounts.bin!\n");
        return;
    }

    // Tạo tài khoản admin mẫu
    Account admin = {"admin", "admin123"};

    // Ghi tài khoản vào file
    fwrite(&admin, sizeof(Account), 1, file);
    fclose(file);

    printf("Tai khoan admin da duoc tao thanh cong trong file accounts.bin.\n");
}

int main() {
    createSampleAdminAccount();
    return 0;
}
