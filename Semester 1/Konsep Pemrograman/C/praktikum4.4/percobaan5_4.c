#include <stdio.h>

int main()
{
    int i, n, j, hasil = 0;
    char jawab;

    do
    {
    printf ("berapa kali anda ingin menampilakan bilangan triangular : ");
    scanf ("%d", &n);

    for (i = 0; i < n; i++)
    {
        hasil = 0;
        for (j = 0; j <= i; j++)
        {
            hasil += j;
        }
        printf ("%d ", hasil);
    }

    printf("\nApakah anda ingin keluar (y/t)? ");
    scanf(" %c", &jawab);
    } while (jawab == 't');
    
    return 0;
}