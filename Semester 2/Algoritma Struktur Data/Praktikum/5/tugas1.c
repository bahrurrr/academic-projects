#include <stdio.h>
#include <stdlib.h>

typedef struct simpul node;
struct simpul {
    int data;
    node *prev;
    node *next;
};

node *head = NULL;
node *tail = NULL;

node *buat_simpul(int);
void free_node(node *);
void sisip_terurut(int);
void hapus_simpul(int);
void tampilkan();

int main() {
    char pilihan;
    int nilai;

    do {
        printf("\noperasi double linked list (integer)\n");
        printf("a. sisip data terurut\n");
        printf("b. hapus data\n");
        printf("c. tampilkan list\n");
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
                printf("masukkan angka yang disisipkan: ");
                scanf("%d", &nilai);
                sisip_terurut(nilai);
                break;
            case 'B':
            case 'b':
                printf("masukkan angka yang dihapus: ");
                scanf("%d", &nilai);
                hapus_simpul(nilai);
                break;
            case 'C':
            case 'c':
                tampilkan();
                break;
            default:
                printf("pilihan tidak valid!\n");
        }
    } while (1);

    return 0;
}

node *buat_simpul(int x) {
    node *baru = (node *) malloc(sizeof(node));
    baru->data = x;
    baru->prev = NULL;
    baru->next = NULL;
    return baru;
}

void free_node(node *p) {
    free(p);
    p = NULL;
}

void sisip_terurut(int x) {
    node *baru = buat_simpul(x);

    if (head == NULL) {
        head = tail = baru;
        printf("berhasil menyisipkan %d\n", x);
        return;
    }

    node *temp = head;
    while (temp != NULL) {
        if (temp->data == x) {
            printf("simpul sudah ada (duplikat)!\n");
            free_node(baru);
            return;
        }
        temp = temp->next;
    }

    if (x < head->data) {
        baru->next = head;
        head->prev = baru;
        head = baru;
        printf("berhasil menyisip awal: %d\n", x);
        return;
    }

    node *current = head;
    while (current != NULL && current->data < x) {
        current = current->next;
    }

    if (current == NULL) {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
        printf("berhasil menyisip akhir: %d\n", x);
    } else {
        baru->next = current;
        baru->prev = current->prev;
        current->prev->next = baru;
        current->prev = baru;
        printf("berhasil menyisip %d sebelum %d\n", x, current->data);
    }
}

void hapus_simpul(int x) {
    if (head == NULL) {
        printf("list kosong!\n");
        return;
    }

    node *current = head;
    while (current != NULL && current->data != x) {
        current = current->next;
    }

    if (current == NULL) {
        printf("simpul tidak ada\n");
        return;
    }

    if (current == head) {
        head = head->next;
        if (head != NULL) head->prev = NULL;
        else tail = NULL;
        printf("berhasil hapus awal: %d\n", x);
    } else if (current == tail) {
        tail = tail->prev;
        tail->next = NULL;
        printf("berhasil hapus akhir: %d\n", x);
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        printf("berhasil hapus tengah: %d\n", x);
    }

    free_node(current);
}

void tampilkan() {
    node *temp = head;
    printf("isi list: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("null\n");
}