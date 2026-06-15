#include <stdio.h>

int main ()
{
    int jumlah, jm3, sm3, biaya1, biaya2;
   
    printf ("masukkan jumlah tiket yang ingin anda beli : ");
    scanf ("%d", &jumlah);

    biaya1 = jumlah * 50000;
    jm3 = jumlah / 3; sm3 = jumlah % 3;
    biaya2 = (jm3 * 2 * 50000) + (sm3 * 50000);
     
    if (jumlah <= 2) printf ("biaya untuk %d tiket adalah : %d", jumlah, biaya1);
    else printf ("biaya untuk %d tiket adalah : %d", jumlah, biaya2);

    return 0;

}