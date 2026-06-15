#include <stdio.h>

int main ()
{
    float F, C;

    printf ("masukkkan suhu Celcius : ");
    scanf ("%f", &C);

    F = C * 1.8 + 32;

    printf ("hasil konversinya adalah %0.2fF", F);

    return 0;
}