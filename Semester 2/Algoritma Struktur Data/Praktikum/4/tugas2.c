#include <stdio.h>
#include <stdlib.h>

typedef struct simpul node;
struct simpul {
    int koef;
    int pangkat;
    node *next;
};

node *head = NULL;

node *buat_simpul(int, int);
void free_node(node *);
void cetak_list();
void sisip_awal(int, int);
void sisip_akhir(int, int);
void sisip_sebelum(int, int, int);
void hapus_awal();
void hapus_akhir();
void hapus_tengah(int);

int main() {
    char pilihan;
    int koef, pangkat;

    do {
        printf("\noperasi polinomial\n");
        printf("a. operasi sisip terurut (pangkat)\n");
        printf("b. operasi hapus\n");
        printf("c. tampilkan polinomial\n");
        printf("x. keluar\n");
        printf("pilih menu: ");
        scanf(" %c", &pilihan);

        switch (pilihan) {
            case 'A':
            case 'a': {
                printf("masukkan koefisien: ");
                scanf("%d", &koef);
                printf("masukkan pangkat: ");
                scanf("%d", &pangkat);

                if (head == NULL || pangkat > head->pangkat) {
                    sisip_awal(koef, pangkat);
                    printf("menggunakan sisip awal\n");
                } 
                else if (head->pangkat == pangkat) {
                    printf("pesan: pangkat sudah ada\n");
                } 
                else {
                    node *before = head;
                    while (before->next != NULL && before->next->pangkat > pangkat) {
                        before = before->next;
                    }

                    if (before->next == NULL) {
                        sisip_akhir(koef, pangkat);
                        printf("menggunakan sisip akhir\n");
                    } 
                    else if (before->next->pangkat == pangkat) {
                        printf("pesan: pangkat sudah ada\n");
                    } 
                    else {
                        sisip_sebelum(koef, pangkat, before->next->pangkat);
                        printf("menggunakan sisip di tengah\n");
                    }
                }
                break;
            }

            case 'B':
            case 'b': {
                printf("masukkan pangkat yang dihapus: ");
                scanf("%d", &pangkat);

                if (head == NULL) {
                    printf("list kosong!\n");
                } 
                else if (head->pangkat == pangkat) {
                    hapus_awal();
                    printf("menggunakan hapus awal list\n");
                } 
                else {
                    node *before = head;
                    while (before->next != NULL && before->next->pangkat != pangkat) {
                        before = before->next;
                    }

                    if (before->next == NULL) {
                        printf("pangkat tidak ditemukan!\n");
                    } 
                    else if (before->next->next == NULL) {
                        hapus_akhir();
                        printf("menggunakan hapus akhir list\n");
                    } 
                    else {
                        hapus_tengah(pangkat);
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

node *buat_simpul(int k, int p) {
    node *baru = (node *) malloc(sizeof(node));
    baru->koef = k;
    baru->pangkat = p;
    baru->next = NULL;
    return baru;
}

void free_node(node *p) {
    free(p);
    p = NULL;
}

void cetak_list() {
    node *p = head;
    printf("polinomial: ");
    while (p != NULL) {
        printf("%dx^%d ", p->koef, p->pangkat);
        if (p->next != NULL) printf("+ ");
        p = p->next;
    }
    printf("\n");
}

void sisip_awal(int k, int p) {
    node *baru = buat_simpul(k, p);
    baru->next = head;
    head = baru;
}

void sisip_akhir(int k, int p) {
    node *baru = buat_simpul(k, p);
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

void sisip_sebelum(int k, int p, int target) {
    node *baru = buat_simpul(k, p);
    node *before = head;
    while (before->next != NULL && before->next->pangkat != target) {
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

void hapus_tengah(int target) {
    node *hapus = head, *before = NULL;
    while (hapus != NULL && hapus->pangkat != target) {
        before = hapus;
        hapus = hapus->next;
    }
    if (hapus != NULL) {
        before->next = hapus->next;
        free_node(hapus);
    }
}