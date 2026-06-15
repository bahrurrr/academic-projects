#include <stdio.h>

int main()
{
    char huruf;

    switch (huruf)
    {
    case 'x':
        printf ("sum = 0");
        break;
    case 'z':
        printf ("valid_flag = 1");
        break;
    case 'a':
        printf ("sum = 1");
        break;
    default:
        printf ("unknown letter %c", huruf);
        break;
    }

    return 0;
}