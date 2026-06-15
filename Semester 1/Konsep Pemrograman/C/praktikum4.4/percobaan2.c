#include <stdio.h>

int main()
{
    int i, n, baris, kolom;

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
    
    return 0;
}