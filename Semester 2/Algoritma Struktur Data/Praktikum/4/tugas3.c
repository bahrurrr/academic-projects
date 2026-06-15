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
void push(int);
int pop();
void konversi(int, int);

int main() {
    char pilihan;
    int desimal;

    do {
        printf("\noperasi stack konversi basis\n");
        printf("a. desimal ke biner\n");
        printf("b. desimal ke oktal\n");
        printf("c. desimal ke heksadesimal\n");
        printf("x. keluar\n");
        printf("pilih menu: ");
        scanf(" %c", &pilihan);

        if (pilihan == 'x' || pilihan == 'X') {
            printf("keluar dari program\n");
            break;
        }

        if (pilihan == 'a' || pilihan == 'A' || 
            pilihan == 'b' || pilihan == 'B' || 
            pilihan == 'c' || pilihan == 'C') {
            printf("masukkan bilangan desimal: ");
            scanf("%d", &desimal);
        }

        switch (pilihan) {
            case 'A':
            case 'a':
                konversi(desimal, 2);
                break;
            case 'B':
            case 'b':
                konversi(desimal, 8);
                break;
            case 'C':
            case 'c':
                konversi(desimal, 16);
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
    baru->next = NULL;
    return baru;
}

void free_node(node *p) {
    free(p);
    p = NULL;
}

void push(int x) {
    node *baru = buat_simpul(x);
    baru->next = head;
    head = baru;
}

int pop() {
    if (head == NULL) return -1;
    node *hapus = head;
    int nilai = hapus->data;
    head = hapus->next;
    free_node(hapus);
    return nilai;
}

void konversi(int angka, int basis) {
    if (angka == 0) {
        push(0);
    } else {
        while (angka > 0) {
            push(angka % basis);
            angka = angka / basis;
        }
    }
    
    printf("hasil: ");
    while (head != NULL) {
        int hasil = pop();
        if (hasil < 10) {
            printf("%d", hasil);
        } else {
            printf("%c", hasil + 55); 
        }
    }
    printf("\n");
}