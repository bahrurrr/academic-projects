#include <stdio.h>

int main ()
{
    char n;

    printf ("ketik sembarang kalimat : ");

    for (;;)
    {
        scanf ("%c", &n);
        if (n == '\n') break;
        else
        printf ("%c\n", n);
    }
    
    return 0;
}