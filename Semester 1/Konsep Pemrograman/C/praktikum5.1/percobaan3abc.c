#include <stdio.h>
#include <math.h>

float kuadrat(float);
int main(){
    float n, hasil;
    printf ("bilangan yang akan dikuadrat : ");
    scanf ("%f", &n);

    hasil = kuadrat(n);
    printf("hasil kuadrat bilangan anda adalah %.2f", hasil);
}
float kuadrat(float x) {
    return pow(x, 2.0);
}