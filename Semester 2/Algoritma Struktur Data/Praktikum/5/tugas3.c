#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct simpul node;
struct simpul {
    int nrp;
    char nama[50];
    char kelas[10];
    node *prev;
    node *next;
};

node *head = NULL;
node *tail = NULL;

node *buat_simpul(int, char*, char*);
void free_node(node *);
void sisip_mhs(int, char*, char*);
void hapus_mhs(int);
void update_mhs(int);
void tampilkan_mhs();

int main() {
    char pilihan;
    int nrp;
    char nama[50], kelas[10];

    do {
        printf("\noperasi data mahasiswa (double linked list)\n");
        printf("a. sisip mahasiswa (terurut nrp)\n");
        printf("b. hapus mahasiswa (berdasar nrp)\n");
        printf("c. update mahasiswa (berdasar nrp)\n");
        printf("d. tampilkan data\n");
        printf("x. keluar\n");
        printf("pilih menu: ");
        scanf(" %c", &pilihan);

        if (pilihan == 'x' || pilihan == 'X') {
            printf("keluar dari program\n");
            break;
        }

        switch (pilihan) {
            case 'A':
            case 'a':
                printf("nrp: "); scanf("%d", &nrp);
                printf("nama: "); scanf(" %[^\n]", nama);
                printf("kelas: "); scanf(" %[^\n]", kelas);
                sisip_mhs(nrp, nama, kelas); 
                break;
            case 'B':
            case 'b':
                printf("masukkan nrp yang akan dihapus: ");
                scanf("%d", &nrp);
                hapus_mhs(nrp); 
                break;
            case 'C':
            case 'c':
                printf("masukkan nrp yang akan diupdate: ");
                scanf("%d", &nrp);
                update_mhs(nrp); 
                break;
            case 'D':
            case 'd':
                tampilkan_mhs();
                break;
            default:
                printf("pilihan tidak valid!\n");
        }
    } while (1);

    return 0;
}

node *buat_simpul(int nrp, char *nama, char *kelas) {
    node *baru = (node *) malloc(sizeof(node));
    baru->nrp = nrp;
    strcpy(baru->nama, nama);
    strcpy(baru->kelas, kelas);
    baru->prev = NULL;
    baru->next = NULL;
    return baru;
}

void free_node(node *p) {
    free(p);
    p = NULL;
}

void sisip_mhs(int nrp, char *nama, char *kelas) {
    node *baru = buat_simpul(nrp, nama, kelas);

    if (head == NULL) {
        head = tail = baru;
        printf("data pertama berhasil ditambahkan.\n");
        return;
    }

    if (nrp < head->nrp) {
        baru->next = head;
        head->prev = baru;
        head = baru;
        printf("data berhasil ditambahkan di awal.\n");
        return;
    }

    node *current = head;
    while (current != NULL && current->nrp < nrp) {
        if (current->nrp == nrp) {
            printf("nrp sudah ada!\n");
            free_node(baru);
            return;
        }
        current = current->next;
    }

    if (current == NULL) {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    } else {
        baru->next = current;
        baru->prev = current->prev;
        current->prev->next = baru;
        current->prev = baru;
    }
    printf("data mahasiswa berhasil disisipkan.\n");
}

void hapus_mhs(int nrp) {
    if (head == NULL) return;

    node *current = head;
    while (current != NULL && current->nrp != nrp) {
        current = current->next;
    }

    if (current == NULL) {
        printf("mahasiswa dengan nrp %d tidak ditemukan.\n", nrp);
        return;
    }

    if (current == head) {
        head = head->next;
        if (head != NULL) head->prev = NULL;
        else tail = NULL;
    } else if (current == tail) {
        tail = tail->prev;
        tail->next = NULL;
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    free_node(current);
    printf("data mahasiswa nrp %d berhasil dihapus.\n", nrp);
}

void update_mhs(int nrp) {
    node *current = head;
    while (current != NULL) {
        if (current->nrp == nrp) {
            printf("masukkan nama baru: ");
            scanf(" %[^\n]", current->nama);
            printf("masukkan kelas baru: ");
            scanf(" %[^\n]", current->kelas);
            printf("data mahasiswa berhasil diupdate!\n");
            return;
        }
        current = current->next;
    }
    printf("mahasiswa dengan nrp %d tidak ditemukan.\n", nrp);
}

void tampilkan_mhs() {
    node *temp = head;
    if (temp == NULL) {
        printf("data mahasiswa kosong.\n");
        return;
    }
    printf("\n--- data mahasiswa ---\n");
    while (temp != NULL) {
        printf("nrp   : %d\n", temp->nrp);
        printf("nama  : %s\n", temp->nama);
        printf("kelas : %s\n\n", temp->kelas);
        temp = temp->next;
    }
}