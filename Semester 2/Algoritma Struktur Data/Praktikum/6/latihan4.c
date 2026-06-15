#include <stdio.h>

void menarahanoi(int n, char asal, char tujuan, char perantara);

int main() {
    int n = 4;
    printf("jumlah disk: %d\n", n);
    printf("langkah-langkah nya adalah dengan :\n");
    
    menarahanoi(n, 'a', 'c', 'b');
    
    return 0;
}

void menarahanoi(int n, char asal, char tujuan, char perantara) {
    if (n == 1) {
        printf("pindahkan disc 1 dari pasak %c ke pasak %c\n", asal, tujuan);
        return;
    }
    
    menarahanoi(n - 1, asal, perantara, tujuan);
    
    printf("pindahkan disc %d dari pasak %c ke pasak %c\n", n, asal, tujuan);
    
    menarahanoi(n - 1, perantara, tujuan, asal);
}