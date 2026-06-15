#include <stdio.h>
#include <string.h>
#define max 99
char asal[max];
char tujuan[max];
void copystr(char [], char []);
int main() {
    printf ("masukkan sebuah string : ");
    fgets (asal, sizeof(asal), stdin);
    asal[strcspn(asal, "\n")] = '\0';

    copystr(asal, tujuan);
    printf("string anda adalah : \"%s\"\n", asal);
    puts ("string anda setelah di copy ke array lain");
    printf("ini string anda di array lain : \"%s\"", tujuan);
}
void copystr(char a[], char t[]) {
    int pjg, i;
    pjg = strlen(a);
    for (i = 0; i < pjg; i++)
    {
        t[i] = a[i];
    }
    t[pjg] = '\0';
}