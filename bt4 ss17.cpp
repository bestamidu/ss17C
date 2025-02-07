#include <stdio.h>
#include <stdlib.h>


int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}


void reverseArray(int *arr, int n) {
    int *start = arr;
    int *end = arr + n - 1;
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}


void sortAscending(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}


void sortDescending(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*(arr + j) < *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

int searchElement(int *arr, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (*(arr + i) == key) return i;
    }
    return -1;
}

int main() {
    int *arr;
    int n, choice, key, searchResult;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Loi cap phat bo nho!\n");
        return 1;
    }

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    do {
        printf("\nMENU\n");
        printf("1. In ra cac phan tu la so chan\n");
        printf("2. In ra cac phan tu la so nguyen to\n");
        printf("3. Dao nguoc mang\n");
        printf("4. Sap xep mang\n");
        printf("5. Nhap vao mot phan tu va tim kiem phan tu trong mang\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Cac phan tu la so chan: ");
                for (int i = 0; i < n; i++) {
                    if (*(arr + i) % 2 == 0) printf("%d ", *(arr + i));
                }
                printf("\n");
                break;
                case 2:
                printf("Cac phan tu la so nguyen to: ");
                for (int i = 0; i < n; i++) {
                    if (isPrime(*(arr + i))) printf("%d ", *(arr + i));
                }
                printf("\n");
                break;
            case 3:
                reverseArray(arr, n);
                printf("Mang sau khi dao nguoc: ");
                for (int i = 0; i < n; i++) printf("%d ", *(arr + i));
                printf("\n");
                break;
            case 4:
                {
                    int sortChoice;
                    printf("\nMENU SAP XEP\n");
                    printf("1. Tang dan\n");
                    printf("2. Giam dan\n");
                    printf("Lua chon cua ban: ");
                    scanf("%d", &sortChoice);

                    switch (sortChoice) {
                        case 1:
                            sortAscending(arr, n);
                            printf("Mang sau khi sap xep tang dan: ");
                            break;
                        case 2:
                            sortDescending(arr, n);
                            printf("Mang sau khi sap xep giam dan: ");
                            break;
                        default:
                            printf("Lua chon khong hop le!\n");
                            break;
                    }

                    if (sortChoice == 1 || sortChoice == 2) {
                        for (int i = 0; i < n; i++) printf("%d ", *(arr + i));
                        printf("\n");
                    }
                }
                break;
            case 5:
                printf("Nhap phan tu can tim kiem: ");
                scanf("%d", &key);
                searchResult = searchElement(arr, n, key);
                if (searchResult != -1) {
                    printf("Tim thay phan tu %d tai vi tri %d.\n", key, searchResult);
                } else {
                    printf("Khong tim thay phan tu %d trong mang.\n", key);
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