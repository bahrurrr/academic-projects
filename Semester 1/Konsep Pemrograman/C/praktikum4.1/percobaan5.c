#include <stdio.h>

int main ()
{
    int  i, n, ganjil;
    printf ("masukkan berapa bilangan ganjil yang ingin anda tampilkan : ");
    scanf ("%d", &n);

    for (i = 1; i <= n; i++)
    {
        ganjil = (2 * i) - 1;
        
        printf ("%d ", ganjil);
    }
    
return 0;
}