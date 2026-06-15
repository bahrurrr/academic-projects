#include <stdio.h>

void rotasi(int *, int *, int *);
int main() {
    int a,b, c;
    printf ("masukkan 3 nilai(a b c) : ");
    scanf ("%d %d %d", &a, &b, &c);

    printf ("nilai awal anda\na = %d\nb = %d\nc = %d\n", a, b, c);
    rotasi(&a, &b, &c);
    printf ("nilai anda sekarang\na = %d\nb = %d\nc = %d", a, b, c);
    
}
void rotasi(int *d, int *e, int *f) {
    int temp;
    temp = *f;
    *f = *e;
    *e = *d;
    *d = temp;
}