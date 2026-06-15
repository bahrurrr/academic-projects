#include <stdio.h>

int ganjil(int);
int main(){
    int n, hasil;
    printf ("masukkan suatu bilangan : ");
    scanf ("%d", &n);

    hasil = ganjil(n);
    if (hasil == 1)
    printf ("%d adalah bilangan ganjil", n);
    else
    printf ("%d adalah bilangan genap", n);
}
int ganjil(int n){
    if (n % 2 == 1)
    return 1;
    else
    return 0;
}