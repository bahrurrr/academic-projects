#include <stdio.h>
#include <string.h>
#define max 100

typedef struct {
    char huruf[max];
    int count;
} stack;
void inisialisasi_stack(stack *);
char pop(stack *);
void push(stack *, char);
int main() {
    stack tumpukan;
    inisialisasi_stack(&tumpukan);
    char kata[] = "EAS*Y*QUE***ST***IO*N***";
    int panjang = strlen(kata);

    printf ("Hasil program:\n");
    for (int i = 0; i < panjang - 1; i++)
    {
        if (kata[i] != '*') {
            push(&tumpukan, kata[i]);
        } else {
            char huruf = pop(&tumpukan);
            if (huruf != '\0') {
                printf ("%c ", huruf);
            }  
        }
    }
}
void inisialisasi_stack(stack *s) {
    s->count = 0;
}
void push(stack *s, char item) {
    if (s->count == max) {
        printf ("maaf stack sudah penuh");
    } else {
        s->huruf[s->count] = item;
        ++(s->count);
    }
}
char pop(stack *s) {
    if (s->count == 0) {
        printf ("stack masih kosong");
        return '\0';
    } else {
        --(s->count);
        return s->huruf[s->count];
    }
}