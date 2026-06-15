#include <stdio.h>
#define max 10

typedef struct {
    int item[max];
    int front;
    int rear;
    int count;
} queue;

void inisialisasi(queue *);
void tambah(queue *, int);
int hapus(queue *);
void tampil(queue *);
void keluartengah(queue *, int);

int main() {
    queue q;
    int pilihan, nomor_mobil, mobil_keluar;

    inisialisasi(&q);

    do {
        printf("\n\nsimulasi parkir");
        printf("\n1. mobil masuk");
        printf("\n2. mobil keluar (depan)");
        printf("\n3. mobil keluar (tengah)");
        printf("\n4. selesai");
        printf("\nmasukkan pilihan (1-4): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                if (q.count == max) {
                    printf("\nantrian penuh");
                } else {
                    printf("masukkan nomor mobil: ");
                    scanf("%d", &nomor_mobil);
                    tambah(&q, nomor_mobil);
                    printf("\nmobil %d masuk", nomor_mobil);
                }
                break;
                
            case 2:
                if (q.count == 0) {
                    printf("\nantrian kosong");
                } else {
                    mobil_keluar = hapus(&q);
                    printf("\nmobil %d keluar dari depan.", mobil_keluar);
                }
                break;
                
            case 3:
                if (q.count == 0) {
                    printf("\nantrian kosong");
                } else {
                    printf("masukkan nomor mobil yang ingin keluar: ");
                    scanf("%d", &nomor_mobil);
                    keluartengah(&q, nomor_mobil);
                }
                break;
                
            case 4:
                printf("\nsimulasi selesai\n");
                break;
                
            default:
                printf("\npilihan tidak valid, silakan pilih 1-4");
        }

        if (pilihan != 4) {
            printf("\n\nkondisi parkiran");
            tampil(&q);
        }

    } while (pilihan != 4);

    return 0;
}

void inisialisasi(queue *q) {
    q->front = q->rear = -1;
    q->count = 0;
}

void tambah(queue *q, int item) {
    if ((q->rear == max - 1 && q->front == 0) || (q->rear + 1 == q->front)) {
        return; 
    }

    if (q->rear == max - 1)
        q->rear = 0;
    else
        q->rear++;

    q->item[q->rear] = item;
    q->count++;

    if (q->front == -1)
        q->front = 0;
}

int hapus(queue *q) {
    int data;

    if (q->front == -1) {
        return 0;
    } else {
        data = q->item[q->front];
        q->count--;

        if (q->front == q->rear)
            q->front = q->rear = -1;
        else {
            if (q->front == max - 1)
                q->front = 0;
            else
                q->front++;
        }
    }
    return data;
}

void tampil(queue *q) {
    if (q->count == 0) {
        printf("\nparkiran kosong");
        return;
    }
    int idx = q->front;
    for (int i = 0; i < q->count; i++) {
        printf("\nmobil : %d", q->item[idx]);
        idx = (idx + 1) % max; 
    }
}

void keluartengah(queue *q, int target_mobil) {
    queue temp;
    inisialisasi(&temp);
    int ketemu = 0;
    int jumlah_awal = q->count;

    for (int i = 0; i < jumlah_awal; i++) {
        int mobil_keluar = hapus(q);
        
        if (mobil_keluar == target_mobil) {
            printf("\nmobil %d keluar\n", target_mobil);
            ketemu = 1;
        } else {
            tambah(&temp, mobil_keluar);
        }
    }

    if (!ketemu) {
        printf("\nmobil %d tidak ditemukan", target_mobil);
    }

    while (temp.count > 0) {
        int mobil_masuk = hapus(&temp);
        tambah(q, mobil_masuk);
    }
}