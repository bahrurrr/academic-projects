#include <stdio.h>

int main ()
{
    float nominal, diskon;

    printf ("masukkan nominal belanja : ");
    scanf ("%f",&nominal);

    diskon = nominal;
    if (nominal >= 100000)
        {diskon -= nominal * 0.05;

        printf ("nominal belanja anda : %0.2f\n", nominal);
        printf ("anda mendapat diskon sebesar : %.2f\n", diskon);
        printf ("harga setelah diskon : %0.2f", diskon);
        }
            else
            {
            printf ("nominal belanja anda : %0.2f\nanda tidak mendapat diskon", nominal);
            }

    return 0;
}