#include <stdio.h>

int main (void)
{
    float bil1, bil2, jumlah, rata, kuadratbil1, kuadratbil2;

    //input dari user
    printf ("masukkan bilangan pertama : ");
    scanf ("%f", &bil1);
    
    printf ("masukkan bilangan kedua : ");
    scanf ("%f", &bil2);

    //jumlah
    jumlah = bil1 + bil2;

    //rata-rata
    rata = jumlah / 2;

    //kuadrat
    kuadratbil1 = bil1 * 2;
    kuadratbil2 =  bil2 * 2;

    //tampilan ke user
    printf ("jumlah = %0.2f\n", jumlah);
    printf ("rata-rata = %0.2f\n", rata);
    printf ("kuadrat bilangan 1 = %0.2f\n", kuadratbil1);
    printf ("kuadrat bilangan 2 : %0.2f\n", kuadratbil2);

    return 0;

}