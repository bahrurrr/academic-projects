#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

float cari(int, int);
int main(){
    int sudut, panjang;
    float hasil;
    
    printf ("besar sudut BAC dalam derajat : ");
    scanf ("%d", &sudut);
    printf ("masukkan panjang sisi AB dalam meter : ");
    scanf ("%d", &panjang);

    hasil = cari(sudut, panjang);
    printf ("panjang sisi AB adalah : %.2fm", hasil);
}
float cari (int x, int y) {
    float radian, total;

    radian = x * (M_PI / 180);
    total = y * radian;

    return total;
}