#include <stdio.h>

int main ()
{
    int i, j, n, total, faktor, hasil =1;
    printf ("masukkan sebuah bilangan : ");
    scanf ("%d", &n);

    for (i = 2; i <= n; i++)
    {
        faktor = 0;
        for (j = 1; j <= i; j++)
        {
            faktor += hasil;
        }
        hasil = faktor;
    }
    printf ("%d(faktorial dari %d)", faktor, n);
}