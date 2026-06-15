#include <stdio.h>

int main ()
{
    float bil1, bil2, hasil;
    printf ("masukkan bilangan pertama : ");
    scanf ("%f", &bil1);

    printf ("masukkan bilangan kedua : ");
    scanf ("%f", &bil2);

    if (bil2 != 0)
    {
        hasil = bil1 / bil2;
        printf ("hasil pembagiannya adalah %.3f\n", hasil);
    }
        else
        {
            printf ("(division by zero)");
        }

return 0;
}