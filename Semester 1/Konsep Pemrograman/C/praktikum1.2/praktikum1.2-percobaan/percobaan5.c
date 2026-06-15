#include <stdio.h>

int main()
{
    float bil1, hasil;

    printf ("tulis sebuah bilangan dan bilangan itu akan dikalikan 50 : ");
    scanf ("%2f", &bil1);

    hasil = bil1 * 50;

    printf ("hasilnya : %0.2f", hasil);

    return 0;

}