#include <stdio.h>
#include <string.h>

struct pesan {
    char kode;
    char jenis[20];
    int harga;
    int jumlah;
    long subtotal;
};

void proses_transaksi(struct pesan [], int);

int main() {
    struct pesan ayam[50];
    char lagi = 'y';
    int i = 0;
    int j;
    long total_kotor = 0;
    long pajak = 0;
    long total_bayar = 0;
    int banyak_pesanan = 0;

    puts("Toko GFC - Gerobak Fried Chicken");
    puts("--------------------------------");
    puts("DAFTAR HARGA");
    printf("Kode\tJenis\tHarga Per Potong\n");
    printf("D\tDada\tRp. 5000.00\n");
    printf("P\tPaha\tRp. 4000.00\n");
    printf("S\tSayap\tRp. 3000.00\n");
    puts("--------------------------------");
    puts("Harga belum termasuk pajak : 10%%\n");

    do {
        printf("Pesanan ke-%d\n", i + 1);
        printf("Jenis [D/P/S] : ");
        scanf(" %c", &ayam[i].kode);
        printf("Jumlah        : ");
        scanf("%d", &ayam[i].jumlah);

        proses_transaksi(ayam, i);

        i++;
        banyak_pesanan++;

        printf("Ada lagi <y/t> ? ");
        scanf(" %c", &lagi);
        printf("\n");

    } while (lagi == 'y' || lagi == 'Y');

    printf("\nNota Belanja Anda :\n");
    printf("\t\tGEROBAK FRIED CHICKEN\n");
    printf("==============================================================\n");
    printf("No\tJenis Potong\tHarga Satuan\tQty\tJumlah Harga\n");
    printf("==============================================================\n");

    for (j = 0; j < banyak_pesanan; j++) {
        printf("%d\t    %s\t  Rp. %d\t %d\t  Rp. %ld\n", 
            j + 1, 
            ayam[j].jenis, 
            ayam[j].harga, 
            ayam[j].jumlah, 
            ayam[j].subtotal);
        total_kotor += ayam[j].subtotal;
    }

    printf("==============================================================\n");
    
    pajak = total_kotor / 10;
    total_bayar = total_kotor + pajak;

    printf("Jumlah Bayar\tRp. %ld\n", total_kotor);
    printf("Pajak 10%%\tRp. %ld\n", pajak);
    printf("TOTAL BAYAR\tRp. %ld\n", total_bayar);
    printf("\nTERIMA KASIH ATAS KUNJUNGAN ANDA\n");
}

void proses_transaksi(struct pesan p[], int idx) {
    if (p[idx].kode == 'D' || p[idx].kode == 'd') {
        strcpy(p[idx].jenis, "DADA");
        p[idx].harga = 5000;
    } 
    else if (p[idx].kode == 'P' || p[idx].kode == 'p') {
        strcpy(p[idx].jenis, "PAHA");
        p[idx].harga = 4000;
    } 
    else if (p[idx].kode == 'S' || p[idx].kode == 's') {
        strcpy(p[idx].jenis, "SAYAP");
        p[idx].harga = 3000;
    } 
    else {
        printf("Kode Salah! Dianggap Sayap.\n");
        strcpy(p[idx].jenis, "SAYAP");
        p[idx].harga = 3000;
    }

    p[idx].subtotal = (long)p[idx].harga * p[idx].jumlah;
}