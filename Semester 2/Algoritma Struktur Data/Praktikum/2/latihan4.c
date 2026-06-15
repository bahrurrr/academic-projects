#include <stdio.h>
#include <string.h>
#define max 1000

typedef struct {
    char huruf[max];
    int count;
}stack;
void inisialisasi(stack *);
void push(stack *, char);
char pop(stack *);
int validasi(stack *, char []);
int main() {
    stack tumpukan;
    char kalimat[max];
    char balik[max];
    int hasil, i = 0;

    puts ("PEMBALIK STRING");
    printf ("masukkan sebuah kalimat: ");
    fgets (kalimat, sizeof(kalimat), stdin);
    kalimat[strcspn(kalimat, "\n")] = '\0';

    inisialisasi(&tumpukan);
    hasil = validasi(&tumpukan, balik);
    
    printf("kalimat: %s\n", kalimat);

    if (hasil == 1) {
        printf ("Kalimat terssebut adalah palindrom");
    } else {
        printf ("Kalimat terssebut bukan palindrom");
    }
}
void inisialisasi(stack *s) {
    s->count = 0;
}
void push(stack *s, char x) {
    if (s->count == max) {
        printf ("stack sudah penuh");
    } else {
        s->huruf[s->count] = x;
        s->count++;
    }
}
char pop(stack *s) {
    if (s->count == 0) {
        printf ("string masih kosong");
        return '\0';
    } else {
        s->count--;
        return s->huruf[s->count];
    }
}
int validasi(stack *s, char x[]) {
    int i = 0, j = 0;
    while (x[i] != '\0') {
        push(s, x[i]);
        i++;
    }
    while (x[j] != '\0') {
        if (x[j] != pop(s)) {
            return 0;
        }
        j++;
    }

    return 1;
}