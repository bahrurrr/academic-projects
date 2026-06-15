#include <stdio.h>

void swap(int *a, int *b);
void printarray(int arr[], int n);
int partition(int arr[], int low, int high, int asc);
void quicksort(int arr[], int low, int high, int asc);

int main() {
    int data[] = {58, 78, 97, 48, 67, 86, 6, 57, 76, 95};
    int n = sizeof(data) / sizeof(data[0]);
    int arr[10];
    int i;

    printf("array awal: ");
    printarray(data, n);

    for(i = 0; i < n; i++) arr[i] = data[i];
    quicksort(arr, 0, n - 1, 1);
    printf("quick sort (asc) : ");
    printarray(arr, n);

    for(i = 0; i < n; i++) arr[i] = data[i];
    quicksort(arr, 0, n - 1, 0);
    printf("quick sort (desc): ");
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

int partition(int arr[], int low, int high, int asc) {
    int pivot = arr[high];
    int i = (low - 1);
    int j;
    
    for(j = low; j <= high - 1; j++) {
        if(asc ? (arr[j] < pivot) : (arr[j] > pivot)) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high, int asc) {
    if(low < high) {
        int pi = partition(arr, low, high, asc);
        quicksort(arr, low, pi - 1, asc);
        quicksort(arr, pi + 1, high, asc);
    }
}