#include <stdio.h>

int main ()
{
    int i,n;
    printf ("masukkan batas bilangan ganjil kecuali kelipatan 3 yang ingin ditampilkan  : ");
    scanf ("%d", &n);

    for (i = 1; i <= n; i += 2)
    {
        if (i % 3 == 0)
        {
            continue;
        }
        
        printf ("%d ", i);
    }
    
    return 0;
}