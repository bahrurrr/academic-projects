#include <stdio.h>

void printarray(int arr[], int n);
void merge(int arr[], int l, int m, int r, int asc);
void mergesort(int arr[], int l, int r, int asc);

int main() {
    int data[] = {58, 78, 97, 48, 67, 86, 6, 57, 76, 95};
    int n = sizeof(data) / sizeof(data[0]);
    int arr[10];
    int i;

    printf("array awal: ");
    printarray(data, n);

    for(i = 0; i < n; i++) arr[i] = data[i];
    mergesort(arr, 0, n - 1, 1);
    printf("merge sort (asc) : ");
    printarray(arr, n);

    for(i = 0; i < n; i++) arr[i] = data[i];
    mergesort(arr, 0, n - 1, 0);
    printf("merge sort (desc): ");
    printarray(arr, n);

    return 0;
}

void printarray(int arr[], int n) {
    int i;
    for(i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void merge(int arr[], int l, int m, int r, int asc) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int arr1[n1], arr2[n2];

    for(i = 0; i < n1; i++) arr1[i] = arr[l + i];
    for(j = 0; j < n2; j++) arr2[j] = arr[m + 1 + j];

    i = 0; 
    j = 0; 
    k = l;
    while(i < n1 && j < n2) {
        if(asc ? (arr1[i] <= arr2[j]) : (arr1[i] >= arr2[j])) {
            arr[k++] = arr1[i++];
        } else {
            arr[k++] = arr2[j++];
        }
    }
    while(i < n1) arr[k++] = arr1[i++];
    while(j < n2) arr[k++] = arr2[j++];
}

void mergesort(int arr[], int l, int r, int asc) {
    if(l < r) {
        int m = l + (r - l) / 2;
        mergesort(arr, l, m, asc);
        mergesort(arr, m + 1, r, asc);
        merge(arr, l, m, r, asc);
    }
}