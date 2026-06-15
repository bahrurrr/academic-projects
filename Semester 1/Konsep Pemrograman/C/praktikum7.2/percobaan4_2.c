#include <stdio.h>
#include <string.h>
#define max 99

char arr1[max];
char arr2[max];
int main() {
    printf ("masukkan string 1 : ");
    fgets (arr1, sizeof(arr1), stdin);
    arr1[strcspn(arr1, "\n")] = '\0';
    printf ("masukkan string 2 : ");
    fgets (arr2, sizeof(arr2), stdin);
    arr2[strcspn(arr2, "\n")] = '\0';

    int hsl = strcmpi(arr1, arr2);
    if (hsl < 0) {
        puts ("sting 1 lebih kecil dari string 2");
    }
    else if (hsl > 0) {
        puts ("string 1 lebih besar dari string 2");
    }
    else puts ("kedua string sama");
}