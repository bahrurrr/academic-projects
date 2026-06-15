#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct simpul node;
struct simpul {
    int data;
    node *prev;
    node *next;
};

node *front = NULL;
node *rear = NULL;

node *buat_simpul(int);
void free_node(node *);
void enqueue(int);
int dequeue();
void shift();
void tampilkan_queue();

int main() {
    char pilihan;
    char desimal[50];

    printf("masukkan bilangan desimal (cth: 12345): ");
    scanf("%s", desimal);

    for (int i = 0; i < strlen(desimal); i++) {
        enqueue(desimal[i] - '0'); 
    }

    do {
        printf("\noperasi queue shift bilangan\n");
        printf("a. tampilkan antrean (queue)\n");
        printf("b. lakukan shift (geser)\n");
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
                tampilkan_queue();
                break;
            case 'B':
            case 'b':
                shift();
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

void enqueue(int x) {
    node *baru = buat_simpul(x);
    if (rear == NULL) {
        front = rear = baru;
        return;
    }
    rear->next = baru;
    baru->prev = rear;
    rear = baru;
}

int dequeue() {
    if (front == NULL) return -1;
    node *hapus = front;
    int nilai = hapus->data;
    
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    } else {
        front->prev = NULL;
    }
    
    free_node(hapus);
    return nilai;
}

void shift() {
    if (front == NULL) {
        printf("queue kosong!\n");
        return;
    }
    int nilai = dequeue();
    enqueue(nilai);
    printf("shift berhasil dilakukan.\n");
    tampilkan_queue();
}

void tampilkan_queue() {
    node *temp = front;
    printf("isi queue (depan ke belakang): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}