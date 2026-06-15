#include <stdio.h>

void triangular(int);
int main(){
    int i, n;
    printf ("masukkan bilangan : ");
    scanf ("%d", &n);

    triangular(n);
}
void triangular(int n){
    int i, hasil = 0;
    for (i = 1;i <= n; i++){
        hasil += i;
    }
    printf ("hasil triangular dari %d adalah %d", n, hasil);
}