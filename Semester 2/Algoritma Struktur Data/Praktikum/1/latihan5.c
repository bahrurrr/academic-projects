#include <stdio.h>
#include <math.h>

typedef struct {
    float real;
    float imag;
} kompleks;

kompleks tambah(kompleks k1, kompleks k2);
kompleks kurang(kompleks k1, kompleks k2);
kompleks kali(kompleks k1, kompleks k2);
kompleks bagi(kompleks k1, kompleks k2);

int main() {
    kompleks k1, k2, hasil;
    char ops;
    
    printf("Masukkan nilai real dan imaginer pertama [real, imaginer] : ");
    scanf("%f, %f", &k1.real, &k1.imag);
    
    printf("Masukkan nilai real dan imaginer kedua [real, imaginer] : ");
    scanf("%f, %f", &k2.real, &k2.imag);
    
    printf("Ingin anda apakan dua bagian itu [+, -, *, /] : ");
    scanf(" %c", &ops);

    switch (ops) {
        case '+':
            hasil = tambah(k1, k2);
            printf("Hasil: %.2f + %.2fi\n", hasil.real, hasil.imag);
            break;
        case '-':
            hasil = kurang(k1, k2);
            printf("Hasil: %.2f + %.2fi\n", hasil.real, hasil.imag);
            break;
        case '*':
            hasil = kali(k1, k2);
            printf("Hasil: %.2f + %.2fi\n", hasil.real, hasil.imag);
            break;
        case '/':
            hasil = bagi(k1, k2);
            printf("Hasil: %.2f + %.2fi\n", hasil.real, hasil.imag);
            break;
        default:
            printf("Error : operator tidak diketahui\n");
            break;
    }
}
kompleks tambah(kompleks k1, kompleks k2) {
    kompleks hasil;
    hasil.real = k1.real + k2.real;
    hasil.imag = k1.imag + k2.imag;
    return hasil;
}
kompleks kurang(kompleks k1, kompleks k2) {
    kompleks hasil;
    hasil.real = k1.real - k2.real;
    hasil.imag = k1.imag - k2.imag;
    return hasil;
}
kompleks kali(kompleks k1, kompleks k2) {
    kompleks hasil;
    hasil.real = (k1.real * k2.real) - (k1.imag * k2.imag);
    hasil.imag = (k1.real * k2.imag) + (k1.imag * k2.real); 
    return hasil;
}
kompleks bagi(kompleks k1, kompleks k2) {
    kompleks hasil;
    float penyebut = pow(k2.real, 2) + pow(k2.imag, 2); 
    
    hasil.real = ((k1.real * k2.real) + (k1.imag * k2.imag)) / penyebut;
    hasil.imag = ((k1.imag * k2.real) - (k1.real * k2.imag)) / penyebut; 
    return hasil;
}