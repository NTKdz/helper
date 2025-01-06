#include <stdio.h>
#include <string.h>
#include "account.h"

// Save client information to a binary file
void saveClientToFile(Client client[], int m) {
    FILE *file = fopen("clients.bin", "wb");
    if (file) {
        fwrite(client, sizeof(Client), m, file);
        fclose(file);
    }
}

// Load client information from a binary file
void loadClientFromFile(Client client[], int *m) {
    FILE *file = fopen("clients.bin", "rb");
    if (file) {
        *m = 0;
        while (fread(&client[*m], sizeof(Client), 1, file)) {
            (*m)++;
        }
        fclose(file);
    }
}

// Save admin account to a binary file
void saveAdminToFile(Admin *admin) {
    FILE *file = fopen("accounts.bin", "wb");
    if (file) {
        fwrite(admin, sizeof(Admin), 1, file);
        fclose(file);
    }
}

// Load admin account from a binary file
void loadAdminFromFile(Admin *admin) {
    FILE *file = fopen("accounts.bin", "rb");
    if (file) {
        fread(admin, sizeof(Admin), 1, file);
        fclose(file);
    } else {
        // Default admin account
        strcpy(admin->username, "admin");
        strcpy(admin->password, "admin123");
        saveAdminToFile(admin);  // Save default admin to file
    }
}

void printfclient(Client client[], int m) {
    for (int i = 0; i < m; i++) {
        printf("ID: %d, Name: %s, Phone: %s, Date: %s, Category: %s\n",
               client[i].id, client[i].clientname, client[i].phonenumber, client[i].date, client[i].category);
    }
}

void addclient(Client client[], int *m) {
    printf("Enter client ID: ");
    scanf("%d", &client[*m].id);
    printf("Enter client name: ");
    scanf("%s", client[*m].clientname);
    printf("Enter client phone number: ");
    scanf("%s", client[*m].phonenumber);
    printf("Enter client date: ");
    scanf("%s", client[*m].date);
    printf("Enter client category: ");
    scanf("%s", client[*m].category);

    (*m)++;
    printf("Khach hang da duoc them thanh cong!\n");
}
