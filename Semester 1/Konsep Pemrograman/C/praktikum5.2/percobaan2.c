#include <stdio.h>

long faktorial(int);
int main(){
    int n;
    long hasil;
    printf ("bilangan yang difaktorial : ");
    scanf ("%d", &n);

    hasil = faktorial(n);
    printf ("hasil faktorial dari %d adalah %ld", n, hasil);
}
long faktorial(int x){
    long hasil = 1;
    for (int i = x; i >= 1; i--)
    {
        hasil = hasil * i;
    }
    return hasil;
    
}