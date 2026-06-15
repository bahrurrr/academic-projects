#include <stdio.h>
#include <string.h>
#define max 99
char asal[max];
char tujuan[max];

int main() {
    printf ("masukkan sebuah string : ");
    fgets (asal, sizeof(asal), stdin);
    asal[strcspn(asal, "\n")] = '\0';

    strcpy(tujuan, asal);

    printf("string anda adalah : \"%s\"\n", asal);
    puts ("string anda setelah di copy ke array lain");
    printf("ini string anda di array lain : \"%s\"", tujuan);
}