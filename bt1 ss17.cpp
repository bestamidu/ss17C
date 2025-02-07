#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, choice, sum = 0, max;
    int *arr;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int)); 

    if (arr == NULL) {
        printf("Cap phat bo nho that bai!\n");
        return 1;
    }

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nMENU\n");
        printf("1. Hien thi cac phan tu trong mang\n");
        printf("2. Tinh do dai mang\n");
        printf("3. Tinh tong cac phan tu trong mang\n");
        printf("4. Hien thi phan tu lon nhat\n");
        printf("5. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Cac phan tu trong mang la: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 2:
                printf("Do dai mang la: %d\n", n);
                break;
            case 3:
                for (int i = 0; i < n; i++) {
                    sum += arr[i];
                }
                printf("Tong cac phan tu trong mang la: %d\n", sum);
                sum = 0;
                break;
            case 4:
                max = arr[0];
                for (int i = 1; i < n; i++) {
                    if (arr[i] > max) {
                        max = arr[i];
                    }
                }
                printf("Phan tu lon nhat trong mang la: %d\n", max);
                break;
            case 5:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 5);

     free(arr);

    return 0;
}