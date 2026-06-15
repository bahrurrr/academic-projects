#include <stdio.h>
#include <stdlib.h>

typedef struct simpul node;
struct simpul {
    int data;
    node *next;
};

node *head = NULL;

node *buat_simpul(int);
void free_node(node *);
void cetak_list();
void sisip_awal(int);
void sisip_akhir(int);
void sisip_sebelum(int, int);
void hapus_awal();
void hapus_akhir();
void hapus_tengah(int);

int main() {
    char pilihan;
    int nilai;

    do {
        printf("\noperasi singel linked list\n");
        printf("a. operasi sisip terurut\n");
        printf("b. operasi hapus\n");
        printf("c. tampilkan list\n");
        printf("x. keluar\n");
        printf("pilih menu: ");
        scanf(" %c", &pilihan);

        switch (pilihan) {
            case 'A':
            case 'a': {
                printf("masukkan nilai yang disisipkan: ");
                scanf("%d", &nilai);

                if (head == NULL || nilai < head->data) {
                    sisip_awal(nilai);
                    printf("menggunakan sisip awal\n");
                } 
                else if (head->data == nilai) {
                    printf("pesan: simpul sudah ada (duplikat)\n");
                } 
                else {
                    node *before = head;
                    while (before->next != NULL && before->next->data < nilai) {
                        before = before->next;
                    }

                    if (before->next == NULL) {
                        sisip_akhir(nilai);
                        printf("menggunakan sisip akhir.\n");
                    } 
                    else if (before->next->data == nilai) {
                        printf("pesan: simpul sudah ada (duplikat)\n");
                    } 
                    else {
                        sisip_sebelum(nilai, before->next->data);
                        printf("menggunakan sisip sebelum simpul tertentu\n");
                    }
                }
                break;
            }

            case 'B':
            case 'b': {
                printf("masukkan nilai yang dihapus: ");
                scanf("%d", &nilai);

                if (head == NULL) {
                    printf("list kosong!\n");
                } 
                else if (head->data == nilai) {
                    hapus_awal();
                    printf("menggunakan hapus awal list\n");
                } 
                else {
                    node *before = head;
                    while (before->next != NULL && before->next->data != nilai) {
                        before = before->next;
                    }

                    if (before->next == NULL) {
                        printf("data tidak ditemukan!\n");
                    } 
                    else if (before->next->next == NULL) {
                        hapus_akhir();
                        printf("menggunakan hapus akhir list\n");
                    } 
                    else {
                        hapus_tengah(nilai);
                        printf("menggunakan hapus simpul tengah\n");
                    }
                }
                break;
            }

            case 'C':
            case 'c': {
                cetak_list();
                break;
            }

            case 'X':
            case 'x':
                printf("keluar dari program\n");
                break;

            default:
                printf("pilihan tidak valid!\n");
        }
    } while (pilihan != 'x' && pilihan != 'X');

    return 0;
}

node *buat_simpul(int x) {
    node *baru = (node *) malloc(sizeof(node));
    baru->data = x;
    baru->next = NULL;
    return baru;
}

void free_node(node *p) {
    free(p);
    p = NULL;
}

void cetak_list() {
    node *p = head;
    printf("isi list: ");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void sisip_awal(int x) {
    node *baru = buat_simpul(x);
    baru->next = head;
    head = baru;
}

void sisip_akhir(int x) {
    node *baru = buat_simpul(x);
    if (head == NULL) { 
        head = baru; 
        return; 
    }
    
    node *tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = baru;
}

void sisip_sebelum(int x, int target) {
    node *baru = buat_simpul(x);
    node *before = head;
    while (before->next != NULL && before->next->data != target) {
        before = before->next;
    }
    baru->next = before->next;
    before->next = baru;
}

void hapus_awal() {
    if (head == NULL) return;
    node *hapus = head;
    head = hapus->next;
    free_node(hapus);
}

void hapus_akhir() {
    if (head == NULL) return;
    if (head->next == NULL) { 
        hapus_awal(); 
        return; 
    }
    
    node *hapus = head, *before = NULL;
    while (hapus->next != NULL) {
        before = hapus;
        hapus = hapus->next;
    }
    before->next = NULL;
    free_node(hapus);
}

void hapus_tengah(int x) {
    node *hapus = head, *before = NULL;
    while (hapus != NULL && hapus->data != x) {
        before = hapus;
        hapus = hapus->next;
    }
    if (hapus != NULL) {
        before->next = hapus->next;
        free_node(hapus);
    }
}