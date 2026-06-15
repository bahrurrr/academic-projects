/* implementasi algoritma utk mengubah infix menjadi postfix */
#include <stdio.h>
#include <string.h>

#define maxstack 100

typedef char itemtype;

typedef struct {
    char item[maxstack]; /* array yg berisi data tumpukan */
    int count; /* menunjukkan indeks data paling atas dari stack */
} stack;

stack tumpukan;

void inisialisasi(stack *s);
int kosong(stack *s);
int penuh(stack *s);
void push(itemtype x, stack *s);
itemtype pop(stack *s);
int derajat(char x);
void konversi_cetak(char temp[]);

int main() {
    char tampung[maxstack], jawab;

    puts("mengubah notasi infix menjadi postfix");
    puts("dengan memanfaatkan struktur stack");

    do {
        inisialisasi(&tumpukan);
        
        puts("");
        printf("masukan ekspresi dalam notasi infix: ");
        scanf(" %[^\n]s", tampung); 

        printf("ungkapan postfixnya = ");
        konversi_cetak(tampung);
        puts("\n");

        printf("mau mencoba lagi (y/t) ? ");
        scanf(" %c", &jawab);

    } while ((jawab == 'y') || (jawab == 'y'));

    return 0;
}

void inisialisasi(stack *s) {
    s->count = 0;
}

int kosong(stack *s) {
    return (s->count == 0);
}

int penuh(stack *s) {
    return (s->count == maxstack);
}

void push(itemtype x, stack *s) {
    if (penuh(s)) {
        // stack penuh
        printf("stack penuh! data tidak dapat masuk!");
    } else {
        ++(s->count);
        s->item[s->count] = x;
    }
}

itemtype pop(stack *s) {
    itemtype x;
    if (kosong(s)) {
        // stack kosong
        printf("stack kosong!");
        return 0;
    } else {
        x = s->item[s->count];
        --(s->count);
        return x;
    }
}

int derajat(char x) {
    if (x == '(') {
        return 0;
    } else if ((x == '+') || (x == '-')) {
        // menentukan derajat operator
        return 1;
    } else if ((x == '*') || (x == '/')) {
        return 2;
    } else if (x == '^') {
        return 3;
    } else {
        // invalid operator
        return -1;
    }
}

void konversi_cetak(char temp[]) {
    int i, pjg, valid = 1;
    char kar, smtr;

    pjg = strlen(temp);

    for (i = 0; i < pjg; i++) {
        kar = temp[i];
        
        if (kar == ' ') continue;

        switch (kar) {
            // if kar '(' -> push ke dalam tumpukan
            case '(':
                push(kar, &tumpukan);
                break;

            // if kar operand -> langsung ditulis
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
            case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
                printf("%c", kar);
                break;

            /* if kar = operator -> jika tumpukan kosong atau derajad
               kar lbh tinggi dibandingderajad ujung tumpukan, push
               operator ke dalam tumpukan.
               jika tidak, pop ujung tumpukan dan tulis;
               ulangi pembandingan kar dengan ujung tumpukan.
               kemudian kar di-push */
            case '+': case '-': case '*': case '/': case '^':
                if ((kosong(&tumpukan)) || (derajat(kar) > derajat(tumpukan.item[tumpukan.count]))) {
                    push(kar, &tumpukan);
                } else {
                    do {
                        smtr = pop(&tumpukan);
                        printf("%c", smtr);
                    } while (!kosong(&tumpukan) && (derajat(kar) <= derajat(tumpukan.item[tumpukan.count])));
                    push(kar, &tumpukan);
                }
                break;

            /* if kar = ')' -> pop dan tulis semua isi tumpukan sampai
               ujung tumpukan = '('. pop juga tanda'('
               ini, tetapi tidak usah ditulis */
            case ')':
                while (!kosong(&tumpukan) && tumpukan.item[tumpukan.count] != '(') {
                    smtr = pop(&tumpukan);
                    printf("%c", smtr);
                }
                pop(&tumpukan); 
                break;

            default:
                // selain dari kar yang diijinkan
                valid = 0;
                puts(" invalid statemen ");
                break;
        } // end of switch-case
    } // end of looping for

    /* jika statemen valid, akhir notasi infix telah tercapai,
       sedangkan tumpukan masih belum kosong, pop semua isi tumpukan
       dan tulis hasilnya */
    if ((valid != 0) && (!kosong(&tumpukan))) {
        while (!kosong(&tumpukan)) {
            smtr = pop(&tumpukan);
            printf("%c", smtr);
        }
    }
}