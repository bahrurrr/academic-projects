#include <stdio.h>

int binarysearch(int arr[], int l, int r, int x);

int main() {
    int data[] = {2, 5, 8, 10, 14, 32, 35, 41, 67, 88, 90, 101, 109};
    int n = sizeof(data) / sizeof(data[0]);
    int cari = 10;

    printf("data: ");
    for(int i = 0; i < n; i++) printf("%d ", data[i]);
    printf("\ndata yang dicari: %d\n", cari);

    int hasil = binarysearch(data, 0, n - 1, cari);

    if (hasil == -1)
        printf("data tidak ditemukan di dalam array.\n");
    else
        printf("data %d berada pada indek ke\n%d\n", cari, hasil);

    return 0;
}

int binarysearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarysearch(arr, l, mid - 1, x);

        return binarysearch(arr, mid + 1, r, x);
    }

    return -1;
}