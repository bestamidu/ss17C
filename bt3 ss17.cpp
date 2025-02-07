#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void reverseString(char *str) {
    int len = strlen(str);
    char *start = str;
    char *end = str + len - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int countWords(char *str) {
    int count = 0;
    int inWord = 0;
    while (*str != '\0') {
        if (isspace(*str)) {
            if (inWord) {
                count++;
                inWord = 0;
            }
        } else {
            inWord = 1;
        }
        str++;
    }
    if (inWord) {
        count++;
    }
    return count;
}

int main() {
    char *str;
    char str2[100];
    int choice;
    int size = 100; 

   
    str = (char *)malloc(size * sizeof(char));
    if (str == NULL) {
        printf("Lỗi cấp phát bộ nhớ!\n");
        return 1;
    }

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap chuoi khac, so sanh chuoi do voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap chuoi: ");
                scanf(" %[^\n]s", str); 
                break;
            case 2:
                {
                    char temp[100];
                    strcpy(temp, str);
                    reverseString(temp);
                    printf("Chuoi dao nguoc: %s\n", temp);
                }
                break;
            case 3:
                printf("So luong tu trong chuoi: %d\n", countWords(str));
                break;
            case 4:
                printf("Nhap chuoi khac: ");
                scanf(" %[^\n]s", str2);
                if (strlen(str2) < strlen(str)) {
                    printf("Chuoi ngan hon chuoi ban dau.\n");
                } else if (strlen(str2) > strlen(str)) {
                    printf("Chuoi dai hon chuoi ban dau.\n");
                } else {
                    printf("Hai chuoi co do dai bang nhau.\n");
                }
                break;
            case 5:
                {
                    char *ptr = str;
                    while (*ptr != '\0') {
                        if (islower(*ptr)) {
                            *ptr = toupper(*ptr);
                        }
                        ptr++;
                    }
                    printf("Chuoi in hoa: %s\n", str);
                }
                break;
            case 6:
                printf("Nhap chuoi khac: ");
                scanf(" %[^\n]s", str2);

              
                if (strlen(str) + strlen(str2) + 1 > size) {
                
                    size = strlen(str) + strlen(str2) + 1;
                    str = (char *)realloc(str, size * sizeof(char));
                    if (str == NULL) {
                        printf("Lỗi cấp phát lại bộ nhớ!\n");
                        return 1;
                    }
                }

                strcat(str, str2);
                printf("Chuoi sau khi them: %s\n", str);
                break;
            case 7:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 7);

    free(str); 

    return 0;
}