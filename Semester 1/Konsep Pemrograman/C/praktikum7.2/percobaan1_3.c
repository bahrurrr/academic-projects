#include <stdio.h>
#include <string.h>
#define max 99

char array[max];
void blkstr(char []);
int main() {
    int panjang;
    printf ("masukkan sebuah string : ");
    fgets (array, (sizeof(array)), stdin);
    array [strcspn (array, "\n")] = '\0';

    printf ("string anda adalah : \"%s\"\n", array);

    panjang = strlen(array);
    blkstr(array);

    printf ("panjang string anda adalah : %d\n", panjang);
    printf ("string anda jika dibalik : \"%s\"\n", array);
}
void blkstr(char s[]) {
    int pjg = strlen(s);
    char temp;
    for (int i = 0; i < pjg/2; i++)
    {
        temp = s[i];
        s[i] = s[pjg - 1 - i];
        s[pjg - 1 - i] = temp;
    }
}