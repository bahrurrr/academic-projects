#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAXSTACK 100

typedef char ItemType;
typedef struct {
    char item[MAXSTACK];
    int count;
} Stack;

Stack tumpukan;

void InitializeStack(Stack *);
int Empty(Stack *);
int Full(Stack *);
void Push(ItemType, Stack *);
ItemType Pop(Stack *);
int drjt(char);
void konversi_cetak(char[], char[]);

typedef struct {
    int item[MAXSTACK];
    int count;
} IntStack;

void InitIntStack(IntStack *S) { S->count = 0; }

void PushInt(int x, IntStack *S) {
    if (S->count < MAXSTACK) {
        ++(S->count);
        S->item[S->count] = x;
    }
}

int PopInt(IntStack *S) {
    if (S->count == 0) return 0;
    int x = S->item[S->count];
    --(S->count);
    return x;
}

int hitung_postfix(char[]);

int main()
{
    char tampung[MAXSTACK], jawab;
    char postfix[MAXSTACK];

    puts("MENGUBAH NOTASI INFIX MENJADI POSTFIX & MENGHITUNG HASIL");
    puts("DENGAN MEMANFAATKAN STRUKTUR STACK");
    do {
        InitializeStack(&tumpukan);
        memset(postfix, 0, sizeof(postfix));
        fflush(stdin);

        puts("");
        printf("Masukan ekspresi dalam notasi infix   : ");
        fgets(tampung, sizeof(tampung), stdin);

        tampung[strcspn(tampung, "\n")] = 0;

        printf("postfix : ");
        konversi_cetak(tampung, postfix);
        puts("");

        int hasil = hitung_postfix(postfix);
        printf("hasil   : %d\n", hasil);

        fflush(stdin);
        printf("\nMau mencoba lagi (y/t) ? ");
        scanf(" %c", &jawab);
        while (getchar() != '\n');
    } while((jawab == 'y') || (jawab == 'Y'));

    return 0;
}

void InitializeStack(Stack *S) {
    S->count = 0;
}

int Empty(Stack *S) {
    return (S->count == 0);
}

int Full(Stack *S) {
    return (S->count == MAXSTACK);
}

void Push(ItemType x, Stack *S) {
    if (Full(S))
        printf("Stack penuh! Data tidak dapat masuk!");
    else {
        ++(S->count);
        S->item[S->count] = x;
    }
}

ItemType Pop(Stack *S) {
    ItemType x;
    if (Empty(S)) {
        return 0;
    }
    else {
        x = (S->item[S->count]);
        --(S->count);
        return x;
    }
}

int drjt(char x) {
    if (x == '(') return 0;
    else if((x == '+') || (x == '-')) return 1;
    else if ((x == '*') || (x == '/')) return 2;
    else if (x == '^') return 3;
    else return -1;
}

void konversi_cetak(char temp[], char postfix[]) {
    int i, pjg, valid = 1, idx = 0;
    char kar, smtr;

    pjg = strlen(temp);

    for (i = 0; i < pjg; i++) {
        kar = temp[i];

        switch (kar) {
            case '(':
                Push(kar, &tumpukan);
                break;

            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                printf("%c", kar);
                postfix[idx++] = kar;
                break;

            case '+': case '-': case '*': case '/': case '^':
                if((Empty(&tumpukan)) || ((drjt(kar) > drjt(tumpukan.item[tumpukan.count]))))
                    Push(kar, &tumpukan);
                else {
                    do {
                        smtr = Pop(&tumpukan);
                        printf("%c", smtr);
                        postfix[idx++] = smtr;
                    } while (drjt(kar) <= drjt(tumpukan.item[tumpukan.count]) && !Empty(&tumpukan));
                    Push(kar, &tumpukan);
                }
                break;

            case ')':
                while (tumpukan.item[tumpukan.count] != '(') {
                    smtr = Pop(&tumpukan);
                    printf("%c", smtr);
                    postfix[idx++] = smtr;
                }
                Pop(&tumpukan);
                break;

            case ' ': case '\n': case '\r':
                break;

            default:
                valid = 0;
                break;
        }
    }

    if ((valid != 0) && (!Empty(&tumpukan))) {
        while (!Empty(&tumpukan)) {
            smtr = Pop(&tumpukan);
            printf("%c", smtr);
            postfix[idx++] = smtr;
        }
    }

    postfix[idx] = '\0';
}

int hitung_postfix(char postfix[]) {
    IntStack evalStack;
    InitIntStack(&evalStack);

    int i, len = strlen(postfix);
    for (i = 0; i < len; i++) {
        char c = postfix[i];

        if (isdigit(c)) {
            PushInt(c - '0', &evalStack);
        }
        else {
            int angkaKanan = PopInt(&evalStack);
            int angkaKiri = PopInt(&evalStack);
            int res = 0;

            switch(c) {
                case '+': res = angkaKiri + angkaKanan; break;
                case '-': res = angkaKiri - angkaKanan; break;
                case '*': res = angkaKiri * angkaKanan; break;
                case '/': res = angkaKiri / angkaKanan; break;
                case '^': res = (int)pow(angkaKiri, angkaKanan); break;
            }

            PushInt(res, &evalStack);
        }
    }

    return PopInt(&evalStack);
}