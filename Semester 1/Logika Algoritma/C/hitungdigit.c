#include <stdio.h>

int main() {
    int n, digit[20];
    int i = 0, total = 0;

    printf("Masukkan bilangan(max 20 digit): ");
    scanf("%d", &n);

    if (n == 0) {
        digit[i++] = 0;
        total = 0;
    } 
    else {
        if (n < 0) n = -n;
        while (n > 0) {
            digit[i] = n % 10;
            total += digit[i];
            n /= 10;
            i++;
        }
    }

    printf("Digit-digitnya: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d ", digit[j]);
    }
    printf("\nJumlah digit: %d\n", total);
}
