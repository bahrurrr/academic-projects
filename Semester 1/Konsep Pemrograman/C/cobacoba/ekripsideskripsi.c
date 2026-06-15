#include <stdio.h>
#include <string.h>
#define max 99

char arr[max];
void enkripsi(char *);
void deskripsi(char *);
int main() {
    printf ("masukkan sebuah string : ");
    fgets (arr, sizeof(arr), stdin);
    arr[strcspn(arr, "\n")] = '\0';

    enkripsi(arr);
    printf ("hasil enkripsi : %s\n", arr);
    deskripsi(arr);
    printf ("hasil deskripsi : %s\n", arr);
}
void enkripsi(char *a) {
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] >= 'A' && a[i] <= 'Z') {
            if (a[i] == 'X') a[i] = 'A';
            else if (a[i] == 'Y') a[i] = 'B';
            else if (a[i] == 'Z') a[i] = 'C';
            else a[i] += 3;
    }
        else if (a[i] >= 'a' && a[i] <= 'z') {
            if (a[i] == 'x') a[i] = 'a';
            else if (a[i] == 'y') a[i] = 'b';
            else if (a[i] == 'z') a[i] = 'c';
            else a[i] += 3;
    }
    else continue;
    }
}
void deskripsi(char *a) {
    for (int i = 0; a[i] != '\0'; i++) {
        if (a[i] >= 'A' && a[i] <= 'Z') {
            if (a[i] == 'A') a[i] = 'X';
            else if (a[i] == 'B') a[i] = 'Y';
            else if (a[i] == 'C') a[i] = 'Z';
            else a[i] -= 3;
        }
        else if (a[i] >= 'a' && a[i] <= 'z') {
            if (a[i] == 'a') a[i] = 'x';
            else if (a[i] == 'b') a[i] = 'y';
            else if (a[i] == 'c') a[i] = 'z';
            else a[i] -= 3;
        }
        else continue;
    }
}