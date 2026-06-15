#include <stdio.h>
#include <string.h>
#define max 99

int arr[max], n;
void baca(int *, int *); 
void cari(int *, int, int);
int main() {
    int nilai, pjg;
    baca(arr, &n);

    printf ("masukkan sebuah nilai : ");
    scanf ("%d", &nilai);

    cari(arr, nilai, n);
}
void baca(int *a, int *b) {
    int n, i;
    do {
    printf("berapa banyak elemen yang ingin anda input (max %d) : ", max);
    scanf ("%d", b);
    }
    while (*b < 1 || *b > max);
        for (i = 0; i < *b; i++)
        {
            printf ("array indeks [%d] : ", i);
            scanf ("%d", a + i);
        }
}
void cari(int *a, int b, int c) {
    int i = 0;
    while (i < c)
    {
        if(b == a[i]) {
            puts ("nilai anda ada di array");
            return;
        }
        i++;
    }
    puts ("nilai anda tidak ada di array");
}