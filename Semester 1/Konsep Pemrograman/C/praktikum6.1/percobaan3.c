#include <stdio.h>
#define MAKS 10
int main() {
    int A[MAKS] [MAKS];
    int B[MAKS] [MAKS];
    int C[MAKS] [MAKS];
    int i, j, baris, kolom;

    puts ("masukkan ordo matrix yang dipisah koma (2, 2): ");
    printf ("masukkan baris matrix : ");
    scanf ("%d", &baris);
    printf ("masukkan kolom matrix : ");
    scanf ("%d", &kolom);

    printf("\nmasukkan elemen-elemen matriks A:\n");
    for (i = 0; i < baris; i++) {
        for (j = 0; j < kolom; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    printf("\nmasukkan elemen-elemen matriks B:\n");
    for (i = 0; i < baris; i++) {
        for (j = 0; j < kolom; j++) {
            printf("B[%d][%d] = ", i, j);
            scanf("%d", &B[i][j]);
        }
    }
    for (i = 0; i < baris; i++) {
        for (j = 0; j < kolom; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("\nisi matriks A:\n");
    for (i = 0; i < baris; i++) {
        for (j = 0; j < kolom; j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
    printf("\nisi matriks b :\n");
    for (i = 0; i < baris; i++) {
        for (j = 0; j < kolom; j++) {
            printf("%d\t", B[i][j]);
        }
        printf("\n");
    }
    printf("\nhasil matrix A + matrix B :\n");
    for (i = 0; i < baris; i++) {
        for (j = 0; j < kolom; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }
}