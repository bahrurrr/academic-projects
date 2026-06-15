#include <stdio.h>
#include <math.h>

int main ()
{
    float a, b, c, D, diskriminan;

    printf ("masukkan nilai a : ");
    scanf ("%f", &a);
    printf ("masukkan nilai b : ");
    scanf ("%f", &b);
    printf ("masukkan nilai C : ");
    scanf ("%f", &c);

    D = diskriminan;
    D = pow(b,2) - 4 * (a *c);
    
    printf ("nilai diskriminannya adalah %0.1f", D);
    if (D > 0) printf (" akar realnya berbeda\n");
    if (D == 0) printf (" akar real kembar\n");
    if (D < 0) printf (" akarnya imajiner");

    return 0;
}