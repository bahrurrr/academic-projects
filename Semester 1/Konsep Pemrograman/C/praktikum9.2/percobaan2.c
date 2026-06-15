#include <stdio.h>
#include <string.h>

struct uang
{
    int jumlah;
    float hargatotal, bayar, bayarakhir, hargasatuan, diskon, pajak, jumlahharga;
};
struct daftar
{
    char jenis[10];
    char kode;
    struct uang data;
};
void input(struct daftar[], int);
void nota(struct daftar[], int);
int main() {
    int n;
    struct daftar beli[4];
    printf ("\t\tToko LARIS\n\t\tDaftar Harga\n");
    puts ("------------------------------------------------");
    printf ("Ukuran Baju\tNama Ukuran\tharga per Potong\n");
    puts ("------------------------------------------------");
    printf ("     S\t\tSmall\t\tRp.36.000,-\n     M\t\tMedium\t\tRp.43.000,-\n     L\t\tLarge\t\tRp.62.000,-\n");
    puts ("------------------------------------------------\n\n");
    puts ("Dapatkan diskon 20%% untuk pembelian lebih dari 10 potong...");
    printf ("Jangan lupa, pajaknya ya...<10%% x <harga-diskon>\n\n");
    printf ("Berapa jumlah data <maks 3> ? ");
    scanf ("%d", &n);

    input(beli, n);
    nota(beli, n);
}
void input(struct daftar beli[], int a) {
    int i, count = 1;
    for (i = 0; i < a; i++) {
        printf ("\nData ke-%d\n", count++);
        do {
            printf ("Ukuran [S/M/L] : ");
            scanf(" %c", &beli[i].kode);

            if (beli[i].kode=='S' || beli[i].kode=='s') {
                strcpy(beli[i].jenis, "Small");
                beli[i].data.hargasatuan = 36000;
                break;
            }
            else if (beli[i].kode=='M' || beli[i].kode=='m') {
                strcpy(beli[i].jenis, "Medium");
                beli[i].data.hargasatuan = 43000;
                break;
            }
            else if (beli[i].kode=='L' || beli[i].kode=='l') {
                strcpy(beli[i].jenis, "Large");
                beli[i].data.hargasatuan = 62000;
                break;
            }
            printf("Kode ukuran tidak valid! Ulangi.\n");
        } while (1);

        printf ("Jumlah Beli    : ");
        scanf ("%d", &beli[i].data.jumlah);

        beli[i].data.hargatotal = beli[i].data.jumlah * beli[i].data.hargasatuan;
        if (beli[i].data.jumlah > 10)
            beli[i].data.diskon = beli[i].data.hargatotal * 0.2;
        else
            beli[i].data.diskon = 0;
        beli[i].data.jumlahharga = beli[i].data.hargatotal - beli[i].data.diskon;
    }
}
void nota(struct daftar beli [], int a) {
    int i, count = 1;
    float pajak, totalbayar = 0;
    puts ("Nota Belanja Anda :");
    printf ("\n\t\t\tToko LARIS\n\n");
    puts ("========================================================================");
    printf ("No\tNama Ukuran\tHarga Satuan\tQty\tDiskon\t\tJumlah Harga\n");
    puts ("========================================================================");
    for (i = 0; i < a; i++)
    {
        printf ("%d\t%s\t\tRp %.2f\t%d\tRp %.2f\tRp %.2f\n", 
            count++, 
            beli[i].jenis, 
            beli[i].data.hargasatuan, 
            beli[i].data.jumlah, 
            beli[i].data.diskon, 
            beli[i].data.jumlahharga
        );
        totalbayar += beli[i].data.jumlahharga;
    }
    puts ("==============================================================");
    printf ("Jumlah Bayar   Rp %.2f\n", totalbayar);
    pajak = totalbayar * 0.1;
    totalbayar += pajak; 
    printf ("Pajak 10%%      Rp %.2f\n", pajak);
    printf ("TOTAL BAYAR    Rp %.2f\n\n", totalbayar);
    puts ("\t\t\tTERIMA KASIH ATAS KUNJUNGAN ANDA");
}