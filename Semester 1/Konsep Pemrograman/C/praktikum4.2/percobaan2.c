#include <stdio.h>

int main ()

{
    int i, total = 0, ke = 1;
    char n;

    printf ("masukkan bil ke-%d : ", ke);
    scanf ("%d", &i);
    printf ("mau memasukkan data lagi [y/t] ? ");
    scanf (" %c", &n);
    total += i;

    ke++;

    while (n == 'Y' || n == 'y')
    {
        printf ("masukkan bil ke-%d : ", ke);
        scanf ("%d", &i);
        printf ("mau memasukkan data lagi [y/t] ? ");
        scanf (" %c", &n);
        total = total + i;
    }
    
    printf ("total bilangan = %d", total);

    return 0;
}