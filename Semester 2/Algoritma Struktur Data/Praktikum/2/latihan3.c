#include <stdio.h>
#include <string.h>
#define max 1000

typedef struct {
    char huruf[max];
    int count;
}stack;
void inisialisasi(stack *);
void push(stack *, char);
int pop(stack *);
void balikstring(stack *, char []);
int main() {
    stack tumpukan;
    char kalimat[max];
    int pjg;

    puts ("PEMBALIK STRING");
    printf ("masukkan sebuah kalimat: ");
    fgets (kalimat, sizeof(kalimat), stdin);
    kalimat[strcspn(kalimat, "\n")] = '\0';

    inisialisasi(&tumpukan);
    balikstring(&tumpukan, kalimat);
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
int pop(stack *s) {
    if (s->count == 0) {
        printf ("string masih kosong");
        return '\0';
    } else {
        s->count--;
        return s->huruf[s->count];
    }
}
void balikstring(stack *s, char x[]) {
    int i = 0;
    while (x[i] != '\0') {
        push(s, x[i]);
        i++;
    }
    printf("Hasil: ");
    while (s->count != 0) {
        printf("%c", pop(s));
    }
}