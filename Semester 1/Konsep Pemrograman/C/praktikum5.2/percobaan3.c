#include <stdio.h>
#include <math.h>

int prima(int);
int main(){
    int n, hasil;
    printf ("cek bilangan prima : ");
    scanf ("%d", &n);

    hasil = prima(n);
    if (hasil == 1)
    printf ("%d adalah bilangan prima", n);
    else 
    printf ("%d bukan bilangan prima", n);
}
int prima(int n){
    if (n < 2)
    return 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        return 0;
    }
    return 1;
}