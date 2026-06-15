#include <stdio.h>
#include <string.h>
#define max 10

typedef struct {
    char nrp[5];
    char nama[50];
    int nilai;
} mahasiswa;

typedef struct {
    mahasiswa item[max];
    int count;
} pqueue;

void inisialisasi(pqueue *);
void tambah(pqueue *, char[], char[], int);
void hapus(pqueue *);
void tampil(pqueue *);

int main() {
    pqueue q;

    inisialisasi(&q);

    tambah(&q, "01", "Andi", 70);
    tambah(&q, "02", "Budi", 85);
    tambah(&q, "03", "Candra", 80);
    hapus(&q);
    
    tambah(&q, "04", "Didik", 90);
    tambah(&q, "05", "Edi", 85);
    hapus(&q);
    hapus(&q);
    
    tambah(&q, "06", "Fanda", 75);
    hapus(&q);
    
    puts("");
    return 0;
}

void inisialisasi(pqueue *q) {
    q->count = 0;
}

void tambah(pqueue *q, char nrp[], char nama[], int nilai) {
    if (q->count == max) {
        printf("\nantrian penuh");
        return; 
    }

    int i = q->count - 1;

    while (i >= 0 && q->item[i].nilai < nilai) {
        q->item[i + 1] = q->item[i];
        i--;
    }

    strcpy(q->item[i + 1].nrp, nrp);
    strcpy(q->item[i + 1].nama, nama);
    q->item[i + 1].nilai = nilai;
    q->count++;
}

void hapus(pqueue *q) {
    if (q->count == 0) {
        printf("\nantrian kosong");
    } else {
        mahasiswa data = q->item[0];
        printf("\n* %s %s %d", data.nrp, data.nama, data.nilai);

        for (int i = 0; i < q->count - 1; i++) {
            q->item[i] = q->item[i + 1];
        }
        q->count--;
    }
}

void tampil(pqueue *q) {
    if (q->count == 0) {
        printf("\nantrian kosong");
        return;
    }
    for (int i = 0; i < q->count; i++) {
        printf("\nmahasiswa : %s %s %d", q->item[i].nrp, q->item[i].nama, q->item[i].nilai);
    }
}