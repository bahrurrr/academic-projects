#include <stdio.h>
#include <string.h>

typedef struct
{
    int jam, menit;
}waktu;
int hitungmenit(waktu);
int main() {
    waktu t1;
    waktu t2;
    int hasil1, hasil2, hasilakhir, akhir = 0;
    printf ("masukkan jam pertaman : ");
    scanf ("%d-%d", &t1.jam, &t1.menit);
    printf ("masukkan jam pertaman : ");
    scanf ("%d-%d", &t2.jam, &t2.menit);

    hasil1 = hitungmenit(t1);
    hasil2 = hitungmenit(t2);
    hasilakhir = hasil1 - hasil2;
    if (hasilakhir < 0)
    {
        akhir = akhir - hasilakhir;
        hasilakhir = akhir;
    }
    printf ("selisih menit anda %d", hasilakhir);
}
int hitungmenit(waktu w) {
    int x;
    w.jam = w.jam * 60;
    w.menit = w.menit + w.jam;
    x = w.menit;
    return x;
}