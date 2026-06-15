#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct simpul node;
struct simpul {
    int nrp;
    char nama[50];
    char kelas[20];
    node *next;
};

node *head = NULL;

node *buat_simpul(int, char*, char*);
void free_node(node *);
void cetak_list();
void sisip_awal(int, char*, char*);
void sisip_akhir(int, char*, char*);
void sisip_sebelum(int, char*, char*, int);
void hapus_awal();
void hapus_akhir();
void hapus_tengah(int);
void update_data(int, char*, char*);

int main() {
    char pilihan;
    int nrp;
    char nama[50], kelas[20];

    do {
        printf("\noperasi linked list mahasiswa\n");
        printf("a. operasi sisip terurut nrp\n");
        printf("b. operasi hapus\n");
        printf("c. update data\n");
        printf("d. tampilkan list\n");
        printf("x. keluar\n");
        printf("pilih menu: ");
        scanf(" %c", &pilihan);

        switch (pilihan) {
            case 'A':
            case 'a': {
                printf("masukkan nrp: ");
                scanf("%d", &nrp);
                getchar(); 
                printf("masukkan nama: ");
                fgets(nama, 50, stdin);
                nama[strcspn(nama, "\n")] = 0; 
                printf("masukkan kelas: ");
                fgets(kelas, 20, stdin);
                kelas[strcspn(kelas, "\n")] = 0;

                if (head == NULL || nrp < head->nrp) {
                    sisip_awal(nrp, nama, kelas);
                    printf("menggunakan sisip awal\n");
                } 
                else if (head->nrp == nrp) {
                    printf("pesan: nrp sudah ada (duplikat)\n");
                } 
                else {
                    node *before = head;
                    while (before->next != NULL && before->next->nrp < nrp) {
                        before = before->next;
                    }

                    if (before->next == NULL) {
                        sisip_akhir(nrp, nama, kelas);
                        printf("menggunakan sisip akhir\n");
                    } 
                    else if (before->next->nrp == nrp) {
                        printf("pesan: nrp sudah ada (duplikat)\n");
                    } 
                    else {
                        sisip_sebelum(nrp, nama, kelas, before->next->nrp);
                        printf("menggunakan sisip sebelum nrp tertentu\n");
                    }
                }
                break;
            }

            case 'B':
            case 'b': {
                printf("masukkan nrp yang dihapus: ");
                scanf("%d", &nrp);

                if (head == NULL) {
                    printf("list kosong!\n");
                } 
                else if (head->nrp == nrp) {
                    hapus_awal();
                    printf("menggunakan hapus awal list\n");
                } 
                else {
                    node *before = head;
                    while (before->next != NULL && before->next->nrp != nrp) {
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
                        hapus_tengah(nrp);
                        printf("menggunakan hapus simpul tengah\n");
                    }
                }
                break;
            }

            case 'C':
            case 'c': {
                printf("masukkan nrp yang ingin diupdate: ");
                scanf("%d", &nrp);
                getchar();
                printf("masukkan nama baru: ");
                fgets(nama, 50, stdin);
                nama[strcspn(nama, "\n")] = 0;
                printf("masukkan kelas baru: ");
                fgets(kelas, 20, stdin);
                kelas[strcspn(kelas, "\n")] = 0;
                
                update_data(nrp, nama, kelas);
                break;
            }

            case 'D':
            case 'd': {
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

node *buat_simpul(int n, char* nm, char* kl) {
    node *baru = (node *) malloc(sizeof(node));
    baru->nrp = n;
    strcpy(baru->nama, nm);
    strcpy(baru->kelas, kl);
    baru->next = NULL;
    return baru;
}

void free_node(node *p) {
    free(p);
    p = NULL;
}

void cetak_list() {
    node *p = head;
    printf("\ndata mahasiswa\n");
    while (p != NULL) {
        printf("nrp: %d | nama: %s | kelas: %s\n", p->nrp, p->nama, p->kelas);
        p = p->next;
    }
    printf("\n");
}

void sisip_awal(int n, char* nm, char* kl) {
    node *baru = buat_simpul(n, nm, kl);
    baru->next = head;
    head = baru;
}

void sisip_akhir(int n, char* nm, char* kl) {
    node *baru = buat_simpul(n, nm, kl);
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

void sisip_sebelum(int n, char* nm, char* kl, int target) {
    node *baru = buat_simpul(n, nm, kl);
    node *before = head;
    while (before->next != NULL && before->next->nrp != target) {
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
    while (hapus != NULL && hapus->nrp != target) {
        before = hapus;
        hapus = hapus->next;
    }
    if (hapus != NULL) {
        before->next = hapus->next;
        free_node(hapus);
    }
}

void update_data(int n, char* nm, char* kl) {
    node *p = head;
    while (p != NULL && p->nrp != n) {
        p = p->next;
    }
    if (p != NULL) {
        strcpy(p->nama, nm);
        strcpy(p->kelas, kl);
        printf("data nrp %d berhasil diupdate.\n", n);
    } else {
        printf("nrp tidak ditemukan!\n");
    }
}