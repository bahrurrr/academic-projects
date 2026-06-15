#include <stdio.h>
#include <string.h>
#define MAX 99

int pjgstr(char []);
char array[MAX];
int main() {
    int n, panjang;
    printf ("masukkan sebuah string : ");
    fgets (array, sizeof(array), stdin);
    array[strcspn (array, "\n")] = '\0';

    panjang = pjgstr(array);

    printf ("string anda adalah \"%s\"\n", array);
    printf ("panjang string anda adalah : %d", panjang);
}
int pjgstr(char s[]) {
    int n = 0;
    while (s[n] != '\0')
    {
        n++;
    }
    return n;
}