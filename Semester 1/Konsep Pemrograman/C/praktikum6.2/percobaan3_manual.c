#include <stdio.h>

int main() {
    char nama[9999];
    int bahasa[9999];
    int mtk[9999];
    int digital[9999];
    float rata[9999];
    int i, n;

    printf ("berapa kali anda ingin memasukkan data : ");
    scanf ("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf ("masukkan nama mahasiswa : ");
        scanf ("%s", &nama[i]);
        printf ("masukkan nilai bahasa : ");
        scanf ("%d", &bahasa[i]);
        printf ("masukkan nilai matematika : ");
        scanf ("%d", &mtk[i]);
        printf ("masukkan nilai digital : ");
        scanf ("%d", &digital[i]);
    }

    for (i = 0; i < n; i++)
    {
        rata[i] = (bahasa[i] + mtk[i] + digital[i]) / 3.0;
    }
    
    puts ("\tNo. Mhs\t\tRata-rata");
    puts ("\t-------------------------");
    for (i = 0; i < n; i++)
    {
        printf ("\t   %d\t\t  %.2f\n", i+1, rata[i]);
    }
}