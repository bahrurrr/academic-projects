#include <stdio.h>

int main()
{
    int i,n;

    printf ("Masukkan batas bilangan ganjil kecuali 7 & 11 yang ingin ditampilkan: ");
    scanf ("%d", &n);

    for (i = 1; i <= n && i <= 100; i += 2)
    {
        if (i % 7 == 0 || i % 11 == 0)
        {
            continue;
        }

        printf ("%d ", i);
    }
    
    return 0;
}