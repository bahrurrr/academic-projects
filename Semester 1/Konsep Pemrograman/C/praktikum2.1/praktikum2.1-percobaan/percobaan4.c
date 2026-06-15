#include <stdio.h>

int main ()
{
    int a, b, c, d, hasil1, hasil2, hasil3, hasil4, hasil5, hasil6;

    printf ("masukkan bilangan anda(a) : ");
    scanf ("%d", &a);
    printf ("masukkan bilangan anda(b) : ");
    scanf ("%d", &b);
    printf ("masukkan bilangan anda(c) : ");
    scanf ("%d", &c);
    printf ("masukkan bilangan anda(d) : ");
    scanf ("%d", &d);

    hasil1 = a % b;
    hasil2 = a - c;
    hasil3 = a + b;
    hasil4 = a / d;
    hasil5 = a / d * d + a % d;
    hasil6 = a % d / d * a - c;

    printf ("a %% b = %d\n", hasil1);
    printf ("a - c = %d\n", hasil2);
    printf ("a + b = %d\n", hasil3);
    printf ("a / d = %0.2f\n", hasil4);
    printf ("a / d * d + a %% d = %0.2f\n", hasil5);
    printf ("a %% d / d * a - c = %0.2f\n", hasil6);

    return 0;
}