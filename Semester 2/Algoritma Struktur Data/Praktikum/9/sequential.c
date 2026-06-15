#include <stdio.h>

void pencarian_sekuensial(int data[], int n, int key);

int main() {
    int data[] = {58, 78, 97, 48, 67, 86, 6, 57, 76, 95};
    int n = 10;
    
    pencarian_sekuensial(data, n, 48);
    
    return 0;
}

void pencarian_sekuensial(int data[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (data[i] == key) {
            printf("data ditemukan pada indeks %d\n", i);
            return;
        }
    }
    printf("data tidak ditemukan\n");
}