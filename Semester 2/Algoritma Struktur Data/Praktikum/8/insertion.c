#include <stdio.h>

void printarray(int arr[], int n);
void insertionsort(int arr[], int n, int asc);

int main() {
    int data[] = {58, 78, 97, 48, 67, 86, 6, 57, 76, 95};
    int n = sizeof(data) / sizeof(data[0]);
    int arr[10];
    int i;

    printf("array awal: ");
    printarray(data, n);

    for(i = 0; i < n; i++) arr[i] = data[i];
    insertionsort(arr, n, 1);
    printf("insertion sort (asc) : ");
    printarray(arr, n);

    for(i = 0; i < n; i++) arr[i] = data[i];
    insertionsort(arr, n, 0);
    printf("insertion sort (desc): ");
    printarray(arr, n);

    return 0;
}

void printarray(int arr[], int n) {
    int i;
    for(i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void insertionsort(int arr[], int n, int asc) {
    int i, j, key;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && (asc ? (arr[j] > key) : (arr[j] < key))) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}