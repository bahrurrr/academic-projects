#include <stdio.h>

int main ()
{
    float rate, rupiah, dollar;
    rate = 11090.00;

    printf ("masukkan nominal dollar : ");
    scanf ("%f", &dollar);

    rupiah = rate * dollar;

    printf ("nilai rupiah anda adalah Rp. %0.2f", rupiah);

    return 0;
}