#include <stdio.h>
#include <math.h>

int main()
{
    int x, hasil;

    printf ("masukkan nilai x untuk 3x^2 5x + 6 : ");
    scanf ("%d", &x);

    //rumus
    hasil = 3 * (x * x) - 5 * x + 6;

    printf ("hasilnya adalah %d", hasil);

    return 0;
}