#include <stdio.h>

void nambah(int *, int *);
int main() {
    int nil1, nil2;

    printf("maukkan bil1 : ");
    scanf ("%d", &nil1);
    printf("maukkan bil2 : ");
    scanf ("%d", &nil2);
    
    nambah(&nil1, &nil2);
    printf ("hasil jika ditambah 2 : %d dan %d", nil1, nil2);
}
void nambah(int *x, int *y) {
    *x = *x + 2;
    *y = *y + 2;
}