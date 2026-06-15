#include <stdio.h>

float mutasi(int, int);
float kombinasi (int, int);
int main() {
    int n, r;
    float tasi, nasi;
    printf ("masukkan bil 1 : ");
    scanf ("%d", &n);
    printf ("masukkan bil 2 : ");
    scanf ("%d", &r);

    tasi = mutasi(n, r);
    nasi = kombinasi(n, r);

    printf ("hasil permutasi dari 2 bilangan anda : %.2f\n", tasi);
    printf ("hasil kombinasi dari 2 bilangan anda : %.2f", nasi);

}
float mutasi(int x, int y) {
    int faktorialx = 1, i, a, faktoriala = 1;
    float z;

    for (i = x; i >= 1; i--)
    {
        faktorialx = faktorialx * i;
    }
    a = x - y;
    for (i = a; i >= 1; i--)
    {
        faktoriala = faktoriala * i;
    }
    
    z = faktorialx / faktoriala;
    return z;
}
float kombinasi(int x, int y) {
    int faktorialx = 1, i, a, faktoriala = 1, faktorialy = 1;
    float s;

    for (i = x; i >= 1; i--)
    {
        faktorialx *= i;
    }
    for (i = y; i >= 1; i--)
    {
        faktorialy *= i;
    }
    a = x - y;
    for (i = a; i >= 1; i--)
    {
        faktoriala *= i;
    }

    s = faktorialx / (faktorialy * faktoriala);
    return s;
}