#include <stdio.h>
#include <math.h>

int main ()
{
    float gajibersih, gajikotor, pokok, sisa, pajak, tunsumis, tunanak, thr, trans, asuransi;
    int anak, masuk, masa;
    
    printf ("masukkan nominal gaji pokok(Rp) : ");
    scanf ("%f", &pokok);
    printf ("jumlah anak : ");
    scanf ("%d", &anak);
    printf ("berapa masa kerja anda(tahun) : ");
    scanf ("%d", &masa);
    printf ("berapa kali masuk kerja per bulan : ");
    scanf ("%d", &masuk);

    tunsumis = pokok * 0.1;
    tunanak = (pokok * 0.05) * anak;
    pajak = (pokok + tunsumis + tunanak) * 0.15;
    sisa = (pokok + tunanak + tunsumis) - pajak;
    thr = 5000 * masa;
    trans = 3000 * masuk;
    asuransi = 20000;
    gajikotor = pokok + tunsumis + tunanak;
    gajibersih = sisa + thr + trans - asuransi;

    printf ("gaji pokok : %0.2f\n", pokok);
    printf ("tunjangan suami/istri : %0.2f\n", tunsumis);
    printf ("tunjangan anak : %0.2f\n", tunanak);
    printf ("gaji kotor : %0.2f\n", gajikotor);
    printf ("thr : %0.2f\n", thr);
    printf ("bantuan transport : %0.2f\n", trans);
    printf ("dipotong pajak : %0.2f\n", pajak);
    printf ("dipotong asuransi : %0.2f\n", asuransi);
    printf ("gajibersih : %0.2f\n", gajibersih);

    return 0;
}