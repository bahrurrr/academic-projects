#include <stdio.h>
#include <string.h>
#define max 99

char array1[max];
char array2[max];
int bandingstr2(char [], char []);
int main() {
    int hasil;
    printf ("masukkan string pertama : ");
    fgets (array1, sizeof(array1), stdin);
    array1[strcspn(array1, "\n")] = '\0';
    printf ("masukkan string kedua : ");
    fgets (array2, sizeof(array2), stdin);
    array2[strcspn(array2, "\n")] = '\0';

    hasil = bandingstr2(array1, array2);

    if (hasil == -1)
    {
        puts ("string pertama lebih kecil dari string kedua");
    }
    else if (hasil == 0)
    {
        puts ("kedua string sama (NON CASE SENSITIVE)");
    }
    else if (hasil == 1)
    {
        puts ("string pertama lebih besar dari string kedua");
    }
}
int bandingstr2(char s[], char r[]) {
    int i = 0, pjg1, pjg2;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] -= 32;
        }
    }
    for (i = 0; s[i] != '\0'; i++)
    {
        if (r[i] >= 'a' && r[i] <= 'z')
        {
            r[i] -= 32;
        }
    }
    for (i = 0; s[i] != '\0' && r[i] != '\0'; i++)
    {
        if (s[i] < r[i])
        {
            return -1;
        }
        else if (s[i] > r[i])
        {
            return 1;
        }
    }
    pjg1 = strlen(s);
    pjg2 = strlen(r);
    if (pjg1 > pjg2)
    return 1;
    else if (pjg1 < pjg2)
    return -1;
    else return 0;
}