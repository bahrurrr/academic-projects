#include <stdio.h>

int main() {
    int i, n, a = 0, b = 1, c, hitung;
    printf ("masukkan jumlah fubonacci yang ingin ditampilkan : ");
    scanf ("%d", &n);

    for (i = 0; i <= n; i++)
    {
        if (i == 0)
        {
            printf ("0 ");
        }
        if (i == 1)
        {
            printf ("1 ");
        }
        if (i >= 2)
        {
            c = a + b;
            a = b;
            b = c;

            printf ("%d ", c);
        }
    }
}