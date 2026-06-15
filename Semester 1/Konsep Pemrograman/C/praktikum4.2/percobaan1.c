#include <stdio.h>

int main ()
{
    char n;
    printf ("ketik huruf X (x besar) : ");
    scanf (" %c", &n);

    while (n != 'X')
    {
        printf ("anda memasukkan %c\n", n);

        printf ("ketik huruf X (x besar) untuk berhenti : ");
        scanf (" %c", &n);
    }
    printf ("terimaksih telah memasukkan %c\n", n);

return 0;
}