#include <stdio.h>
#define MAKS 9999

int main() {
    int array[MAKS];
    int i, n, max;

    printf ("berapa kali anda ingin input : ");
    scanf ("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf ("nilai ke-%d : ", i+1);
        scanf ("%d", &array[i]);
        max = array[0];

        if (max <= array[i])
        {
            max = array[i];
        }
    }
    printf ("nilai tertingginya adalah : %d", max);
}