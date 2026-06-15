#include <stdio.h>
#include <math.h>

int main ()
{
    int input, panjang, tinggi;
    float volume, luas;
    
    printf ("1. menghitung volume kubus\n2. menghitung luas lingkaran\n3. menghitung volume silinder\nmasukkan pilihan anda : ");
    scanf ("%d", &input);
    
    switch (input)
    {
    case 1:
        printf ("masukkan panjang kubus : ");
        scanf ("%d", &panjang);

        volume = pow(panjang, 3);
        printf ("volume kubus adalah %.2f", volume);
        break;
    case 2:
        printf ("masukkan panjang jari-jari lingkaran : ");
        scanf ("%d", &panjang);

        luas = 3.14 * (panjang * panjang);
       printf ("luas lingkaran adalah %.2f", luas);
        break;
    case 3:
        printf ("masukkan panjang jari-jari silinder : ");
        scanf ("%d", &panjang);
        printf ("masukkan panjang tinggi silinder : ");
        scanf ("%d", &tinggi);

        volume = 3.14 * (panjang * panjang) * tinggi;
        printf ("volume tabung adalah %.2f", volume);
        break;
    default:
    printf ("pilihan salah");
        break;
    }

    return 0;
}