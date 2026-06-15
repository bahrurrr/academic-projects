#include <stdio.h>

int main() {
    int i, n;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf ("masukkan input anda : ");
    scanf ("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf ("%d\n", array[i]);
    }
    
}