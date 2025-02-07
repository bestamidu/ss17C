#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char *ptr = str;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai\n");
        printf("4. Dem so luong chu so\n");
        printf("5. Dem so luong ky tu dac biet\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap chuoi: ");
                scanf(" %[^\n]s", str); 
                break;
            case 2:
                printf("Chuoi da nhap: %s\n", str);
                break;
            case 3:
                {
                    int count = 0;
                    while (*ptr != '\0') {
                        if ((*ptr >= 'a' && *ptr <= 'z') || (*ptr >= 'A' && *ptr <= 'Z')) {
                            count++;
                        }
                        ptr++;
                    }
                    printf("So luong chu cai: %d\n", count);
                    ptr = str; 
                }
                break;
            case 4:
                {
                    int count = 0;
                    while (*ptr != '\0') {
                        if (*ptr >= '0' && *ptr <= '9') {
                            count++;
                        }
                        ptr++;
                    }
                    printf("So luong chu so: %d\n", count);
                    ptr = str; 
                }
                break;
            case 5:
                {
                    int count = 0;
                    while (*ptr != '\0') {
                        if (!((*ptr >= 'a' && *ptr <= 'z') || (*ptr >= 'A' && *ptr <= 'Z') || (*ptr >= '0' && *ptr <= '9'))) {
                            count++;
                        }
                        ptr++;
                    }
                    printf("So luong ky tu dac biet: %d\n", count);
                    ptr = str; 
                }
                break;
            case 6:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 6);

    return 0;
}