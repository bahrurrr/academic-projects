#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

float radian(float);
int main(){
    float n, hasil;
    printf ("koversi derajar ke radian\nmasukkan derajat : ");
    scanf ("%f", &n);

    hasil = radian(n);
    printf ("hasil konversi nya adalah %f radian", hasil);
}
float radian(float n){
    return n / 180 * M_PI;
}