#ifndef ACCOUNT_H
#define ACCOUNT_H

// Define Client struct
typedef struct {
    int id;
    char clientname[100];
    char phonenumber[50];
    char date[50];
    char category[50];
} Client;

// Define Admin struct
typedef struct {
    char username[50];
    char password[50];
} Admin;

// Function prototypes for Client management
void addclient(Client client[], int *m);
void deleteclient(Client client[], int *m);
void findclient(Client client[], int m);
void printfclient(Client client[], int m);
void saveClientToFile(Client client[], int m);
void loadClientFromFile(Client client[], int *m);
void updateClient(Client client[], int m);

// Function prototypes for Admin management
void saveAdminToFile(Admin *admin);
void loadAdminFromFile(Admin *admin);

#endif
