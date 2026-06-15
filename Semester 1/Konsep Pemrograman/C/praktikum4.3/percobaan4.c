#include <stdio.h>

int main()
{
    int i,n, nilai, min, max, no = 1, total = 0;
    float rata;

    printf ("masukkan jumlah mahasiswa : ");
    scanf ("%d", &n);

    printf ("nilai ke-%d : ", no);
    scanf ("%d", &nilai);
    min = nilai;
    max = nilai;
    total = nilai;
    no++;
    
    for (i = 2; i <= n; i++)
    {
        printf ("nilai ke-%d : ", no);
        scanf ("%d", &nilai);
        if (nilai < min) min = nilai;
        if (nilai > max) max = nilai;
        total += nilai;
        no++;
    }
    rata = (float)total / n;
    
    printf ("nilai minimal : %d\n", min);
    printf ("nilai maksimal : %d\n", max);
    printf ("nilai rata-rata : %.2f\n", rata);

    return 0;
}