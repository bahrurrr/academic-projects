#include <stdio.h>

void urutkan_data(int data[], int n);
void sekuensial_berurutan(int data[], int n, int key);

int main() {
    int data[] = {58, 78, 97, 48, 67, 86, 6, 57, 76, 95};
    int n = 10;
    
    urutkan_data(data, n);
    sekuensial_berurutan(data, n, 50);
    
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

void sekuensial_berurutan(int data[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (data[i] > key) {
            printf("pencarian berhenti di indeks %d\n", i);
            printf("data tidak ditemukan\n");
            return;
        }
        if (data[i] == key) {
            printf("data ditemukan pada indeks %d\n", i);
            return;
        }
    }
    printf("data tidak ditemukan\n");
}