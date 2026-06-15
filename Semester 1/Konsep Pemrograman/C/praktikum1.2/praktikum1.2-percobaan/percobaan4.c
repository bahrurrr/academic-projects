#include <stdio.h>

int main ()
{
    int var1, var2, jumlah;
    //isikan 2 bilangan
    printf ("isikan bilangan bulat pertama : ");
    scanf ("%d", &var1);

    printf ("isikan  bilangan bulat kedua : ");
    scanf ("%d", &var2);

    jumlah = var1 + var2;

    //hasilnya
    printf ("hasil dari penjumlahan : %d", jumlah);

    return 0;
}