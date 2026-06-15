#include <stdio.h>

int main()
{
    int n, i, baris, kolom;
    char jawab;

    do
    {
        printf ("cetak deretan 1 sampai n sebanyak n baris : ");
        scanf ("%d", &n);

        for (baris = 1; baris <= n; baris++)
        {
            for (kolom = 1; kolom <= n; kolom++)
            {
                printf ("%2d", kolom);
            }
            printf ("\n");
        }
        printf("Apakah anda ingin keluar (y/t)? ");
        scanf(" %c", &jawab);
    } while (jawab == 't');
    
}