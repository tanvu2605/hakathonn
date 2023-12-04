#include <stdio.h>
#include <string.h>

struct Contact {
    int id;
    char name[50];
    char phone[12];
    char address[50];
    int status;
};

void printContact(struct Contact contact) {
    printf("ID: %d, Name: %s, Phone: %s, dia chi: %s, trang thai: %d\n", contact.id, contact.name, contact.phone, contact.address, contact.status);
}

void printContactList(struct Contact contactList[], int size) {
    for (int i = 0; i < size; ++i) {
        printContact(contactList[i]);
    }
}

void addContact(struct Contact contactList[], int *size) {
    struct Contact newContact;
    printf("Enter name, phone, dia chi: ");
    scanf("%s %s %s", newContact.name, newContact.phone, newContact.address);
    newContact.id = *size + 1;
    newContact.status = 1;
    contactList[(*size)++] = newContact;
    printf("da them lien he thanh cong!\n");
}

void updateContact(struct Contact contactList[], int size) {
    char searchName[50];
    printf("nhap ten can chinh sua: ");
    scanf("%s", searchName);

    for (int i = 0; i < size; ++i) {
        if (strcmp(contactList[i].name, searchName) == 0) {
            printf("nhap ten moi, phone, dia chi: ");
            scanf("%s %s %s", contactList[i].name, contactList[i].phone, contactList[i].address);
            printf("Contact updated successfully!\n");
            return;
        }
    }

    printf("khong tim thay lien he !\n");
}

void deleteContact(struct Contact contactList[], int *size) {
    char searchName[50];
    printf("chon ten de xoa: ");
    scanf("%s", searchName);

    for (int i = 0; i < *size; ++i) {
        if (strcmp(contactList[i].name, searchName) == 0) {
            contactList[i] = contactList[--(*size)];
            printf("Contact deleted successfully!\n");
            return;
        }
    }

    printf("khong tim thay lien lac!\n");
}
void bubbleSort(struct Contact contactList[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (strcmp(contactList[j].name, contactList[j + 1].name) > 0) {
                // Swap
                struct Contact temp = contactList[j];
                contactList[j] = contactList[j + 1];
                contactList[j + 1] = temp;
            }
        }
    } 
}
int main() {
    struct Contact contactList[100];
    int size = 2;

    contactList[0] = (struct Contact){1, "trong tan", "1234567890", "123 hoan kiem", 1};
    contactList[1] = (struct Contact){2, "viet hoang", "0987654321", "456 hai ba trung", 1};

    int choice;

    do {
        printf("\n*************MENU**************:\n1. in toan bo danh sach\n2. them moi lien lac\n3. chinh sua lien lac\n4. xoa lien lac\n0. Exit\n nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (int i = 0; i < size; ++i) {
                    printContact(contactList[i]);
                }
                break;
            case 2:
                {
                    struct Contact newContact;
                    printf("Enter name, phone, dia chi: ");
                    scanf("%s %s %s", newContact.name, newContact.phone, newContact.address);
                    newContact.id = size + 1;
                    newContact.status = 1;
                    contactList[size++] = newContact;
                    printf("lien lac duoc them thanh cong!\n");
                }
                break;
            case 3:
                {
                    char searchName[50];
                    printf("Enter the name to update: ");
                    scanf("%s", searchName);

                    int found = 0;
                    for (int i = 0; i < size; ++i) {
                        if (strcmp(contactList[i].name, searchName) == 0) {
                            printf("Enter new name, phone, dia chi: ");
                            scanf("%s %s %s", contactList[i].name, contactList[i].phone, contactList[i].address);
                            printf("lien lac duoc them thanh cong!\n");
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("lien lac khong tim thay!\n");
                    }
                }
                break;
            case 4:
                {
                    char searchName[50];
                    printf("chon ten can xoa: ");
                    scanf("%s", searchName);

                    int found = 0;
                    for (int i = 0; i < size; ++i) {
                        if (strcmp(contactList[i].name, searchName) == 0) {
                            contactList[i] = contactList[--size];
                            printf("lien lac duoc xoa thanh cong!\n");
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("lien lac khong tim thay!\n");
                    }
                }
                break;
              case 5:
              	{
				  
                bubbleSort(contactList, size);
                printf("danh ba duoc sap xep thanh cong!\n");
            	}
                break;
            
            case 0:
                printf("ket thuc!\n");
                break;
            default:
                printf("vui long lua chon lai menu o tren.\n");
        }
    } while (choice != 0);

    return 0;
}

