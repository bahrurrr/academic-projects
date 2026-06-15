#include <stdio.h>
#include <string.h>
#define max 99

char string[max];
int main() {
    printf ("masukkan sebuah string : ");
    fgets (string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';

    int panjang = strlen(string);

    printf ("string anda adalah : \"%s\"\n", string);
    printf ("panjang string anda : %d", panjang);
}