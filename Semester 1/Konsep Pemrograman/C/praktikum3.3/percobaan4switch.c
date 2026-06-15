#include <stdio.h>

int main ()
{
    int input;
    printf ("pilih hari yang anda inginkan\n1. senin\n2. selasa\n3. rabu\n4. kamis\n5. jum'at\n6. sabtu\n7. minggu\n");
    printf ("masukkan pilihan anda : ");
    scanf ("%d", &input);

    switch (input)
    {
    case 1:
        printf ("pilihan anda = senin\n");
        break;
    case 2:
        printf ("pilihan anda = selasa\n");
        break;
    case 3:
        printf ("pilihan anda = rabu\n");
        break;
    case 4:
        printf ("pilihan anda = kamis\n");
        break;
    case 5:
        printf ("pilihan anada = jum'at\n");
        break;
    case 6:
        printf ("pilihan anda = sabtu\n");
        break;
    case 7:
        printf ("pilihan nada = minggu\n");
        break;
    default:
    printf ("invalid number\n");
    }
return 0;
}