#include <stdio.h>

int main()
{
    int input;

    printf ("pilih hari yang anda inginkan\n1. senin\n2. selasa\n3. rabu\n4. kamis\n5. jum'at\n6. sabtu\n7. minggu\n");
    printf ("masukkan pilihan anda : ");
    scanf ("%d", &input);

    if (input == 1)
    {
        printf ("pilihan anda = senin\n");
    }
    else if (input == 2)
    {
        printf ("pilihan anda = selasa\n");
    }
    else if (input == 3)
    {
        printf ("pilihan anda = rabu\n");
    }
    else if (input == 4)
    {
        printf ("pilihan anda = kamis\n");
    }
    else if (input == 5)
    {
        printf ("pilihan anda = jum'at\n");
    }
    else if (input == 6)
    {
        printf ("pilihan anda = sabtu\n");
    }
    else if (input == 7)
    {
        printf ("pilihan anda = minggu\n");
    }
    else
    {
        printf ("invalis number");
    }
return 0;
}