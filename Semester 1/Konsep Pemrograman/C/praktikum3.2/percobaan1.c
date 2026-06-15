#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, d, x1, x2, real, imag;

    printf ("masukkan bilangan pertama : ");
    scanf ("%f", &a);
    printf ("masukkan bilangan kedua : ");
    scanf ("%f", &b);
    printf ("masukkan bilangan ketiga : ");
    scanf ("%f", &c);

    d = (b * b) - (4 * a * c);

    if (d == 0)
    {
        x1 = x2 = -b / (2 * a);
        printf ("nilai x1 : %.2f\nnilai x2 : %.2f", x1, x2 );
    }
        else if (d > 0)
        {
            x1 = (-b + sqrt(d)) / (2 * a);
            x2 = (-b - sqrt(d)) / (2 * a);
            printf ("nilai x1 : %.2f\nnilai x2 : %.2f", x1, x2);
        }
            else
            {
            real = (-b / (2 * a));
            imag = (sqrt(-d) / (2 * a));
            printf ("nilai x1 : %.2f + %.2fi\nnilai x2 : %.2f - %.2fi", real, imag, real, imag);
            }

return 0;
}