#include <stdio.h>

int main ()
{
    char n;
    int k = 0, s = 0;

    printf ("ketikkan sembarang kalimat : ");
   do
   {
    scanf ("%c", &n);
    if (n == ' ') s++;
    if (n != '\n') k++;
   }
   while (n != '\n');
  
    printf ("jumlah karakter : %d\n", k);
    printf ("jumlah spasi %d\n", s);
    return 0;
}