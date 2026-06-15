#include <stdio.h>
#define max 1000

typedef int itemtype;

typedef struct {
    itemtype item[max];
    int count;
} stack;

void inisialisasi(stack *);
void push(stack *, itemtype);
itemtype pop(stack *);
void konversi(stack *, itemtype, int);

int main() {
    stack tumpukan;
    itemtype bilangan;
    int input;
    char jawab;

    do {
        inisialisasi(&tumpukan);

        printf("Konversi desimal ke:\n");
        printf("1. Biner\n2. Octal\n3. Hexa\n");
        printf("Konversi ke (1/2/3): ");
        scanf("%d", &input);

        printf("Masukkan bilangan desimal: ");
        scanf("%d", &bilangan);

        if (input == 1) {
            printf("Hasil konversi desimal %d ke biner: ", bilangan);
            konversi(&tumpukan, bilangan, 2);
        }
        else if (input == 2) {
            printf("Hasil konversi desimal %d ke octal: ", bilangan);
            konversi(&tumpukan, bilangan, 8);
        }
        else if (input == 3) {
            printf("Hasil konversi desimal %d ke hexa: ", bilangan);
            konversi(&tumpukan, bilangan, 16);
        }
        else {
            printf("Input salah");
        }

        printf("\nApakah ingin konversi lagi (y/n): ");
        scanf(" %c", &jawab);

    } while (jawab == 'y' || jawab == 'Y');

    return 0;
}
void inisialisasi(stack *s) {
    s->count = 0;
}
void push(stack *s, itemtype x) {
    if (s->count == max) {
        printf("Stack penuh");
    } else {
        s->item[s->count] = x;
        s->count++;
    }
}
itemtype pop(stack *s) {
    if (s->count == 0) {
        return -1;
    } else {
        s->count--;
        return s->item[s->count];
    }
}
void konversi(stack *s, itemtype x, int basis) {
    int hasil;
    char digit[] = "0123456789ABCDEF";

    if (x == 0) {
        printf("0");
        return;
    }
    while (x != 0) {
        push(s, x % basis);
        x = x / basis;
    }
    while (s->count != 0) {
        hasil = pop(s);
        printf("%c", digit[hasil]);
    }
}