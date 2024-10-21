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
void viewPayment();
void searchRecord();
void deleteRecord();
void displayMenu()
{
    printf("\n1. Add New Record\n");
    printf("2. View List of Records\n");
    printf("3. Modify Record\n");
    printf("4. View Payment\n");
    printf("5. Search Record\n");
    printf("6. Delete Record\n");
    printf("7. Exit\n");
}

int main(void)
{
    int choice;
    char phoneNumber[11];
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
            break;
            case 2:
                viewRecords();
            break;
            case 3:
                printf(
                    "\nEnter phone number to modify record: ");
            scanf("%s", phoneNumber);
            modifyRecord(phoneNumber);
            break;
            case 4:
                printf(
                    "\nEnter phone number to view payment: ");
            scanf("%s", phoneNumber);
            viewPayment(phoneNumber);
            break;
            case 5:
                printf(
                    "\nEnter phone number to search record: ");
            scanf("%s", phoneNumber);
            searchRecord(phoneNumber);
            break;
            case 6:
                printf(
                    "\nEnter phone number to delete record: ");
            scanf("%s", phoneNumber);
            deleteRecord(phoneNumber);
            break;
            case 7:
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
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
    printf("\nName\tPhone Number\tUsage(min)\tTotal Bill($)\n");
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].phoneNumber, phoneNumber) == 0) {
            printf("%s\t%s\t%.2f\t\t%.2f\n", customers[i].name, customers[i].phoneNumber, customers[i].usage, customers[i].totalBill);
            return;
        }
    }
    printf("\nRecord not found!\n");
}

void viewPayment(char phoneNumber[])
{
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].phoneNumber, phoneNumber)
            == 0) {
            printf("\nTotal Bill for %s: $%.2f\n",
                   customers[i].name,
                   customers[i].totalBill);
            return;
            }
    }
    printf("\nRecord not found!\n");
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