#include <stdio.h>

float ftoi (float);
float itocm (float);
float ctom (float);
int main() {
    float panjang, a, b, c;
    printf ("masukkan panjang(feet) : ");
    scanf ("%f", &panjang);

    a = ftoi(panjang);
    b = itocm(a);
    c = ctom(b);

    printf ("%.2f kaki = %.2f inch\n%.2f inch = %.2f cm\n%.2f cm = %.2f meter", panjang, a, a, b, b, c);
}
float ftoi (float x) {
    float hasil = x * 12;
    return hasil; 
}
float itocm (float x) {
    float hasil = x * 2.54;
    return hasil;
}
float ctom (float x) {
    float hasil = x / 100;
    return hasil;
}