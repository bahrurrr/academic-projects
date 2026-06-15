#include <stdio.h>
#include <string.h>
#define max 99

char array1[max];
char array2[max];
void bandingstr1(char [], char []);
int main() {
    printf ("masukkan string pertama : ");
    fgets (array1, sizeof(array1), stdin);
    array1[strcspn(array1, "\n")] = '\0';
    printf ("masukkan string kedua : ");
    fgets (array2, sizeof(array2), stdin);
    array2[strcspn(array2, "\n")] = '\0';

    bandingstr1(array1, array2);
}
void bandingstr1(char s[], char r[]) {
    int pjg1, pjg2;
    pjg1 = strlen(s);
    pjg2 = strlen(r);

    if (pjg1 != pjg2)
    {
        puts ("kedua string tidak sama");
        return;
    }
    for (int i = 0; i < pjg1; i++)
    {
        if (s[i] != r[i])
        {
            puts ("kedua string tidak sama");
            return;
        }
    }
    puts ("kedua string anda sama");
}