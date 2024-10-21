#include <stdio.h>
#include <string.h>

struct Customer {
    char name[50];
    char phoneNumber[11];
    float usage;
    float totalBill;
};

struct Customer customers[100];

int customerCount = 0;
void addRecord();
void viewRecords();
void modifyRecord();
void searchRecord();
void deleteRecord();

int main(void)
{
    printf("Hello, World!\n");
    return 0;
}
void addRecord() {
    if (customerCount < 100) {
        printf("\nEnter name: ");
        scanf("%[^\n]s", customers[customerCount].name);
        printf("\nEnter phone number: ");
        scanf("\ns", customers[customerCount].phoneNumber);
        printf("\nEnter usage: (in minutes) ");
        scanf("%f", &customers[customerCount].usage);
        customers[customerCount].totalBill = customers[customerCount].usage * 5;
        customerCount++;
    }
    else {
        printf("\nToo many records! Contact Admin for help.");
    }
}
void viewRecords() {
    printf("\nName\tPhone Number\tUsage(min)\tTotal Bill(huf)\n");
    for (int i = 0; i < customerCount; i++) {
        printf("%s\t%s\t%.2f\t\t%.2f\n", customers[i].name, customers[i].phoneNumber, customers[i].usage, customers[i].totalBill);
    }
}

void modifyRecord(char phoneNumber[]) {
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].phoneNumber, phoneNumber) == 0) {
            printf("\nEnter new usage in minutes for %s: ", customers[i].name);
            scanf("%f", &customers[i].usage);
            customers[i].totalBill = customers[i].usage * 5;
            printf("\n Record modified\n");
            return;
        }
    }
    printf("\nRecord not found");
}
void searchRecord(char phoneNumber[]) {
    printf("\nName\tPhone Number\tUsage(min)\tTotal Bill(huf)\n");
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].phoneNumber, phoneNumber) == 0) {
            printf("%s\t%s\t%.2f\t\t%.2f\n", customers[i].name, customers[i].phoneNumber,customers[i].usage,customers[i].totalBill);
            return;
        }
    }
}
void deleteRecord(char phoneNumber[]) {
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].phoneNumber, phoneNumber)==0) {
            for (int j = i; j < customerCount - 1; j++) {
                customers[j] = customers[j + 1];
            }
            customerCount--;
            printf("\nRecord deleted");
            return;
        }
    }
    printf("\nRecord not found\n");
}