#include <stdio.h>

void urutkan_data(int data[], int n);
void pencarian_biner(int data[], int n, int key);

int main() {
    int data[] = {58, 78, 97, 48, 67, 86, 6, 57, 76, 95};
    int n = 10;
    
    urutkan_data(data, n);
    pencarian_biner(data, n, 76);
    
    return 0;
}

void urutkan_data(int data[], int n) {
    int i, j, sementara;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                sementara = data[j];
                data[j] = data[j + 1];
                data[j + 1] = sementara;
            }
        }
    }
}

void pencarian_biner(int data[], int n, int key) {
    int bawah = 0, atas = n - 1, tengah;
    
    while (bawah <= atas) {
        tengah = bawah + (atas - bawah) / 2;
        
        if (data[tengah] == key) {
            printf("data ditemukan pada indeks %d\n", tengah);
            return;
        } else if (data[tengah] < key) {
            bawah = tengah + 1;
        } else {
            atas = tengah - 1;
        }
    }
    printf("data tidak ditemukan\n");
}