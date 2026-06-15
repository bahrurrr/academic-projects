#include <stdio.h>

int pascal(int baris, int kolom);

int main() {
    int baris;
    printf("masukkan jumlah baris segitiga pascal (misal: 6): ");
    scanf("%d", &baris);

    for (int i = 0; i < baris; i++) {
        for(int space = 0; space < baris - i; space++) {
            printf("  ");
        }
        for (int j = 0; j <= i; j++) {
            printf("%4d", pascal(i, j));
        }
        printf("\n");
    }
    return 0;
}

int pascal(int baris, int kolom) {
    if (kolom == 0 || kolom == baris) {
        return 1;
    } else {
        return pascal(baris - 1, kolom - 1) + pascal(baris - 1, kolom);
    }
}