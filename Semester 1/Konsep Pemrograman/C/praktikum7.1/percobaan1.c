#include <stdio.h>
#include <string.h>
#define MAX 20

char string[MAX];
int main() {
    printf ("masukkan isi string anda : ");
    fgets (string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';

    int jumlah = strlen(string);
    //int jumlah = sizeof(string) / sizeof(string[0]);

    printf ("%d\n", jumlah);
    printf ("%s", string);
}