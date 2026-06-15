#include <stdio.h>
#include <math.h>

int main () {
    int angka, i, prima = 1;

    printf ("masukkan sebuah bilangan : ");
    scanf ("%d", &angka);

    if (angka <=1) {
        prima = 0;
    }
    else {
        for (i = 2; i <= sqrt(angka); i++)
        {
            if (angka % i == 0) {
                prima = 0;
                break;
            }
        }
    }
      
    if (prima) {
        printf("%d adalah bilangan prima.\n", angka);
    } 
    else {
        printf("%d bukan bilangan prima.\n", angka);
    }
    
return 0;
}