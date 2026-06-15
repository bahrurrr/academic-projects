#include <stdio.h>

int main ()
{
    int angka;
    char huruf;

    printf ("masukkan sebuah angka : ");
    scanf ("%d", &angka);

    printf ("masukkan sebuah huruf : ");
    scanf (" %c", &huruf);

    //menampilkan angka dan huruf anda
    printf ("angka yang anda masukkan : %d\n", angka);
    printf ("huruf yang anda masukkan : %c", huruf);

    return 0;
}