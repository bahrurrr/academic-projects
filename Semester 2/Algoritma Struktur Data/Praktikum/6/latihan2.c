#include <stdio.h>

void kombinasi(char arr[], int n, int panjang, int index);

int main() {
    int n;
    printf("jumlah karakter = ");
    scanf("%d", &n);
    
    char arr[10];
    kombinasi(arr, n, n, 0);
    
    printf("\nbuild successful\n");
    return 0;
}

void kombinasi(char arr[], int n, int panjang, int index) {
    if (index == panjang) {
        for (int i = 0; i < panjang; i++) {
            printf("%c", arr[i]);
        }
        printf(" ");
        return;
    }
    
    for (int i = 0; i < n; i++) {
        arr[index] = 'a' + i; 
        kombinasi(arr, n, panjang, index + 1);
    }
}