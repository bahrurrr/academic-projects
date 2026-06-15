#include <stdio.h>

int main()
{
    int bil;

    printf ("masukkan sembarang bilangan : ");
    scanf ("%d", &bil);

    if (bil >= 1 && bil <= 100)
    {
        printf ("%d ada dalam range 1-100", bil);
    }
    else
    {
        printf ("%d di luar range 1-100", bil);
    }
    
return 0;
}