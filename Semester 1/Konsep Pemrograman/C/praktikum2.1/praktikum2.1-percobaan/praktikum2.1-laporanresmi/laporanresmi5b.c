#include <stdio.h>

int main ()
{
    int x1, x2, x3;

    x1 = (2 + 3) - 10 * 2;
    x2 = (2 + 3) - (10 * 2);
    x3 = 10 % 3 * 2 + 1;

    printf ("nilai (1)x adalah %d\n", x1);
    printf ("nilai (2)x adalah %d\n", x2);
    printf ("nilai (3)x adalah %d\n", x3);

    return 0;
}