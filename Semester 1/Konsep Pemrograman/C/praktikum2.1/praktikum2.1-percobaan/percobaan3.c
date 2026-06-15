#include <stdio.h>

int main ()
{
    int input, sisa, seratus, limapuluh, duapuluh, sepuluh, lima, dua, satu, ratus;

    printf ("masukkan nominal anda(Rp) = ");
    scanf ("%d", &input);

    sisa = input;
    seratus = sisa / 100000;  sisa = sisa - (seratus * 100000);
    limapuluh = sisa / 50000; sisa = sisa - (limapuluh * 50000);
    duapuluh = sisa / 20000;  sisa = sisa - (duapuluh * 20000);
    sepuluh = sisa / 10000;   sisa = sisa - (sepuluh * 10000);
    lima = sisa / 5000;       sisa = sisa - (lima * 5000);
    dua = sisa / 2000;        sisa = sisa - (dua * 2000);
    satu = sisa / 1000;       sisa = sisa - (satu * 1000);
    ratus = sisa / 100;       sisa = sisa - (ratus * 100);

    if (seratus > 0) printf ("%d lembar 100000\n", seratus);
    if (limapuluh > 0) printf ("%d lembar 50000\n", limapuluh);
    if (duapuluh > 0) printf ("%d lembar 20000\n", duapuluh);
    if (sepuluh > 0) printf ("%d lembar 10000\n", sepuluh);
    if (lima > 0) printf ("%d lembar 5000\n", lima);
    if (dua > 0) printf ("%d lembar 2000\n", dua);
    if (satu > 0) printf ("%d lembar 1000\n", satu);
    if (ratus > 0) printf ("%d koin 100\n", ratus);
    
    return 0;
}