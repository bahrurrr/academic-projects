#include <stdio.h>

int main ()
{
    char n;
    int k = 0, s = 0, kecil = 0, besar = 0, angka = 0;

    printf ("ketikkan sembarang kalimat : ");
   do
   {
    scanf ("%c", &n);
    if (n == ' ') s++;
    if (n != '\n') k++;
    if (n >= 'a' && n <= 'z') kecil++;
    if (n >= 'A' && n <= 'Z') besar++;
    if (n >= '0' && n <= '9') angka++;
   }
   while (n != '\n');
  
    printf ("jumlah karakter : %d\n", k);
    printf ("jumlah spasi : %d\n", s);
    printf ("julah karakter kecil : %d\n", kecil);
    printf ("jumlah karakter besar : %d\n", besar);
    printf ("julah angka : %d\n", angka);

    return 0;
}