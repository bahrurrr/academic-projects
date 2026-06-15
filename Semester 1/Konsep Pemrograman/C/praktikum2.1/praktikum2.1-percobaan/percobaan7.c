#include <stdio.h>
#include <math.h>

int main ()
{
    float jari, pi, luas;

    printf ("menghitung luas lingkaran\nmasukkan panjang jari-jari : ");
    scanf ("%f", &jari);

    //perhitungan
    pi = 3.14f;
    luas = pi * pow(jari,2);

    printf ("luas lingkaranya adalah %0.2f", luas);

    return 0;
}