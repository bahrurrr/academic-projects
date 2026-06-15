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
    int data;

    printf ("mobil awal:");
    inisialisasi(&q);
    tambah(&q, 1);
    tambah(&q, 2);
    tambah(&q, 3);
    tambah(&q, 4);
    tambah(&q, 5);
    tambah(&q, 6);
    tambah(&q, 7);
    tambah(&q, 8);
    tambah(&q, 9);
    tampil(&q);
    puts("");

    printf ("\nproses penambahan mobil:");
    tambah(&q, 10);
    tampil(&q);
    printf ("\nmobil %d masuk\n", q.item[q.rear]);

    printf ("\nproses keluarnya mobil pertama:");
    int mobil_keluar = hapus(&q);
    tampil(&q);
    printf ("\nmobil %d keluar\n", mobil_keluar);
    puts("");

    printf ("proses mobil keluar dari tengah:");
    keluartengah(&q, 5);
    tampil(&q);
    puts("");
}
void inisialisasi(queue *q) {
    q->front = q->rear = -1;
    q->count = 0;
}
void tambah(queue *q, int item)
{
    if ((q->rear == max - 1 && q->front == 0) || (q->rear + 1 == q->front))
    {
        printf("\nAntrian Penuh");
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

    if (q->front == -1)
    {
        printf("\nAntrian Kosong");
        return 0;
    }
    else
    {
        data = q->item[q->front];
        q->count--;

        if (q->front == q->rear)
            q->front = q->rear = -1;
        else
        {
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
        printf("\nParkiran Kosong");
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