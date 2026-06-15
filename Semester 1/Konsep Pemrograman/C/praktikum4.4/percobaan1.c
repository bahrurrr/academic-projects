#include <stdio.h>

int main()
{
    int n, i, baris, kolom;
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
    
    return 0;
}