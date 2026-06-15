#include <stdio.h>

int main()
{
    int i, n, hasil;
    printf ("masukkan bilangan triangular yang anda inginkan : ");
    scanf ("%d", &n);

    for (i = n; i >= 1 ; i-- )
    {
        if (i == n)
        {
            printf ("%d", i);
        } else
        printf (" + %d", i); 
    }

    return 0;
}