#include <stdio.h>

int main()
{
    int n, i, pembagi, prima, hitung = 1;
    printf ("berapa kali anda ingin menampilka bilangan prima : ");
    scanf ("%d", &n);

    for (i = 2; hitung <= n; i++)
    {
        prima = 1;
        for (pembagi = 2; pembagi <= i/2; pembagi++)
        {
            if (i % pembagi == 0)
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
    
    return 0;
}