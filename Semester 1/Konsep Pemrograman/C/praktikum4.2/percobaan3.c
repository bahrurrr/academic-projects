#include <stdio.h>

int main ()

{
    int i, total = 0, ke = 1, max, min;
    float rata;
    char n;

    printf ("masukkan bil ke-%d : ", ke);
    scanf ("%d", &i);
    printf ("mau memasukkan data lagi [y/t] ? ");
    scanf (" %c", &n);
    total += i;
    max = i;
    min = i;

    while (n == 'Y' || n == 'y')
    {
        ke++;
        printf ("masukkan bil ke-%d : ", ke);
        scanf ("%d", &i);
        printf ("mau memasukkan data lagi [y/t] ? ");
        scanf (" %c", &n);
        total = total + i;
        if (i > max) max = i;
        if (i < min) min = i;
    }
    
    rata = (float) total / ke;
    printf ("total bilangan = %d\n", total);
    printf ("rata-rata dari bilangan anda = %.2f\n", rata);
    printf ("nilai maksimum angka anda = %d\n", max);
    printf ("nilai minimum angka anda = %d\n", min);

    return 0;
}