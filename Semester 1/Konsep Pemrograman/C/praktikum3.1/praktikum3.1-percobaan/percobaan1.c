#include <stdio.h>

int main ()
{
    int angka, ganjil, genap;

    printf ("masukkan suatu bilangan : ");
    scanf ("%d", &angka);

    ganjil = angka % 2 != 0;

    printf ("bilangan yang diimput adalah %d\n", angka);
    if (ganjil) printf ("%d adalah bilangan ganjil", angka);
    else printf ("%d adalah bilangan genap", angka);

    return 0;
}