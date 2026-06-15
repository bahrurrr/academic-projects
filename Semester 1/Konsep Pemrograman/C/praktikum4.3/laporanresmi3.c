#include <stdio.h>

int main()
{
    int total = 0, n, digit, asli;
    printf ("masukkan suatu bilangan : ");
    scanf  ("%d", &n);

    asli = n;

    while (n > 0)
    {
        digit = n % 10;
        total += digit;
        n = n / 10;
    }
    printf ("jumlah angka dari bilangan %d = %d", asli, total);

    return 0;
}