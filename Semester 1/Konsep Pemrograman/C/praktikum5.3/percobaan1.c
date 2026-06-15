#include <stdio.h>

int max (int, int);
int main() {
    int bil1, bil2, terbesar;
    printf ("masukkan bil pertama : ");
    scanf ("%d", &bil1);
    printf ("masukkan bil kedua : ");
    scanf ("%d", &bil2);

    terbesar = max(bil1, bil2);
    printf ("bilangan terbesar adalah %d", terbesar);
}
int max (int x, int y) {
    if (x > y) {
        return x;
    }
        else {
        return y;
    }
}