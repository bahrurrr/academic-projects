#include <stdio.h>

int main ()
{
    int  i, n;
    printf ("masukkan bilangan anda : ");
    scanf ("%d", &n);

    for (i = 1; i <= n; i++)
    {
        if (i > 1)
        {
           printf ("*%d", i);
        }
        else
        printf ("%d", i); 
    }
    
return 0;
}