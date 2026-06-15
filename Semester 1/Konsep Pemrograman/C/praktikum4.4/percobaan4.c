#include <stdio.h>

int main()
{
    int i, n, j, hasil = 0;
    printf ("berapa  banyak bilangan triangular yang ingin anda tampilakan : ");
    scanf ("%d", &n);

    for (i = 0; i < n; i++)
    {
        hasil = 0;
        for (j = 0; j <= i; j++)
        {
            hasil += j;
        }
        printf ("%d ", hasil);
    }
    
    return 0;
}