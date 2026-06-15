#include <stdio.h>

void printarray(int arr[], int n);
void shellsort(int arr[], int n, int asc);

int main() {
    int data[] = {58, 78, 97, 48, 67, 86, 6, 57, 76, 95};
    int n = sizeof(data) / sizeof(data[0]);
    int arr[10];
    int i;

    printf("array awal: ");
    printarray(data, n);

    for(i = 0; i < n; i++) arr[i] = data[i];
    shellsort(arr, n, 1);
    printf("shell sort (asc) : ");
    printarray(arr, n);

    for(i = 0; i < n; i++) arr[i] = data[i];
    shellsort(arr, n, 0);
    printf("shell sort (desc): ");
    printarray(arr, n);

    return 0;
}

void printarray(int arr[], int n) {
    int i;
    for(i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void shellsort(int arr[], int n, int asc) {
    int gap, i, j, temp;
    for(gap = n / 2; gap > 0; gap /= 2) {
        for(i = gap; i < n; i += 1) {
            temp = arr[i];
            for(j = i; j >= gap && (asc ? (arr[j - gap] > temp) : (arr[j - gap] < temp)); j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}