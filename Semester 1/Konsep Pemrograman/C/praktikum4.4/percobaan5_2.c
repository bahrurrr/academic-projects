#include <stdio.h>

int main ()
{
    int n, kolom, baris;
    char jawab;
    do
    {
        printf ("cetak angka i sebanyak i kali, dari 1 sampai n : ");
        scanf ("%d", &n);

        for (baris = 1; baris <= n; baris++)
        {
            for (kolom = 1; kolom <= baris; kolom++)
            {
                printf ("%d", baris);
            }
            printf ("\n");
        }
        printf("Apakah anda ingin keluar (y/t)? ");
        scanf(" %c", &jawab);
    } while (jawab == 't');
    
    return 0;
}