#include <stdio.h>
#define max 10

void jumlah(int n, int a[max][max], int b[max][max], int c[max][max]);
void kurang(int n, int a[max][max], int b[max][max], int c[max][max]);
void kali(int n, int a[max][max], int b[max][max], int c[max][max]);

int m1[max][max];
int m2[max][max];
int hasil[max][max];

int main()
{
    int n, i, j;

    printf("masukkan ordo matriks (contoh: 2 untuk 2x2): ");
    scanf("%d", &n);

    printf("masukkan matrix pertama:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &m1[i][j]);
        }
    }

    printf("masukkan matrix kedua:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &m2[i][j]);
        }
    }

    jumlah(n, m1, m2, hasil);

    printf("\nhasil penjumlahan:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", hasil[i][j]);
        }
        printf("\n");
    }

    kurang(n, m1, m2, hasil);

    printf("\nhasil pengurangan:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", hasil[i][j]);
        }
        printf("\n");
    }

    kali(n, m1, m2, hasil);

    printf("\nhasil perkalian:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", hasil[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void jumlah(int n, int a[max][max], int b[max][max], int c[max][max])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void kurang(int n, int a[max][max], int b[max][max], int c[max][max])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

void kali(int n, int a[max][max], int b[max][max], int c[max][max])
{
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = 0;
            for (k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}