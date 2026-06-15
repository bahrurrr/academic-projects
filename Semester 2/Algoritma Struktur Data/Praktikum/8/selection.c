#include <stdio.h>

void swap(int *a, int *b);
void printarray(int arr[], int n);
void selectionsort(int arr[], int n, int asc);

int main() {
    int data[] = {58, 78, 97, 48, 67, 86, 6, 57, 76, 95};
    int n = sizeof(data) / sizeof(data[0]);
    int arr[10];
    int i;

    printf("array awal: ");
    printarray(data, n);

    for(i = 0; i < n; i++) arr[i] = data[i];
    selectionsort(arr, n, 1);
    printf("selection sort (asc) : ");
    printarray(arr, n);

    for(i = 0; i < n; i++) arr[i] = data[i];
    selectionsort(arr, n, 0);
    printf("selection sort (desc): ");
    printarray(arr, n);

    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printarray(int arr[], int n) {
    int i;
    for(i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void selectionsort(int arr[], int n, int asc) {
    int i, j, extremeidx;
    for(i = 0; i < n - 1; i++) {
        extremeidx = i;
        for(j = i + 1; j < n; j++) {
            if(asc ? (arr[j] < arr[extremeidx]) : (arr[j] > arr[extremeidx])) {
                extremeidx = j;
            }
        }
        swap(&arr[extremeidx], &arr[i]);
    }
}