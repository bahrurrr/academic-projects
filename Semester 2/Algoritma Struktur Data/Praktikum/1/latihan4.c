#include <stdio.h>

void tambah (int [], int [], int [], int, int, int);
void kurang (int [], int [], int [], int, int, int);
void kali (int [], int [], int [], int, int, int);
void turunan (int [], int [], int);

int main() {
    int p1[] = {15, 0, 0, 1, 0, 5, 0, 8, 6};
    int p2[] = {10, 0, 2, 2, 3, 0, 0, 4, 0, 3};
    int p3[] = {5, 0, 1};
    int batas_p1 = sizeof(p1) / sizeof(p1[0]);
    int batas_p2 = sizeof(p2) / sizeof(p2[0]);
    int batas_p3 = sizeof(p3) / sizeof(p3[0]);
    int batasmaks, i;
    
    if (batas_p1 > batas_p2) {
        batasmaks = batas_p1;
    } else {
        batasmaks = batas_p2;
    }
    int hasiltbh[batasmaks];    
    int hasilkrg[batasmaks];
    int hasilkali[batas_p1 + batas_p3 - 1];
    int hasiltrn[batas_p2 - 1];

    tambah(p1, p2, hasiltbh, batas_p1, batas_p2, batasmaks);
    kurang(p1, p2, hasilkrg, batas_p1, batas_p2, batasmaks);
    kali(p1, p3, hasilkali, batas_p1, batas_p3, batas_p1 + batas_p3 - 1);
    turunan(p2, hasiltrn, batas_p2);
    
    printf ("Hasil dari P1 + P2 = ");
    for (i = 0; i < batasmaks; i++)
    {
        printf ("%d ", hasiltbh[i]);
    }
    puts ("");
    printf ("Hasil dari P1 - P2 = ");
    for (i = 0; i < batasmaks; i++)
    {
        printf ("%d ", hasilkrg[i]);
    }
    puts ("");
    printf ("Hasil dari P1 * P3 = ");
    for (i = 0; i < batas_p1 + batas_p3 - 1; i++)
    {
        printf ("%d ", hasilkali[i]);
    }
    puts ("");
    printf ("Hasil dari P2' = ");
    for (i = 0; i < batas_p2 - 1; i++)
    {
        printf ("%d ", hasiltrn[i]);
    }
    puts ("");
}
void tambah(int satu[], int dua[], int hasil[], int batas1, int batas2, int batasmaks) {
    int i;
    for (i = 0; i < batasmaks ; i++) {
        hasil[i] = 0;
    }
    for (i = 0; i < batasmaks; i++) {
        int nilai1 = 0, nilai2 = 0;
        if (i < batas1)
        {
            nilai1 = satu[i];
        }
        if (i < batas2)
        {
            nilai2 = dua[i];
        }
        hasil[i] = nilai1 + nilai2;
    }
}
void kurang(int satu[], int dua[], int hasil[], int batas1, int batas2, int batasmaks) {
    int i;

    for (i = 0; i < batasmaks; i++) {
        hasil[i] = 0;
    }
    for (i = 0; i < batasmaks; i++) {
        int nilai1 = 0, nilai2 = 0;
        if (i < batas1)
        {
            nilai1 = satu[i];
        }
        if (i < batas2)
        {
            nilai2 = dua[i];
        }
        hasil[i] = nilai1 - nilai2;
    }
}
void kali(int satu[], int tiga[], int hasil[], int batas1, int batas3, int batasmaks) {
    int i, j;

    for (i = 0; i < batasmaks; i++)
    {
        hasil[i] = 0;
    }
    for (i = 0; i < batas1; i++)
    {
        for (j = 0; j < batas3; j++)
        {
            hasil[i + j] += (satu[i] * tiga[j]);
        }
        
    }
}
void turunan(int dua[], int hasil[], int batas2) {
    int i;

    for (i = 1; i < batas2; i++)
    {
        hasil[i - 1] = dua[i] * i;
    }
}