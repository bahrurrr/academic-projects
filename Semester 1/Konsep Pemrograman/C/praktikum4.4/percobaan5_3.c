#include <stdio.h>

int main()
{
    int n, i, j, prima, hitung;
    char jawab;

    do
    {
    printf ("berapa kali anda ingin menampilka bilangan prima : ");
    scanf ("%d", &n);

    hitung = 1;
    for (i = 2; hitung <= n; i++)
    {
        prima = 1;
        for (j = 2; j <= i/2; j++)
        {
            if (i % j == 0)
            {
                prima = 0;
                break;
            }
        }
        if (prima == 1)
        {
            hitung++;
            printf ("%d ", i);
        }
    }
    printf("\nApakah anda ingin keluar (y/t)? ");
    scanf(" %c", &jawab);
    } while (jawab == 't');
    
    return 0;
}