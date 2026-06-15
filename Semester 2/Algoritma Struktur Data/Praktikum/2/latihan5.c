#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
void konversi_cetak(char []);
int cek_infix(char []);

int main()
{
    char tampung[MAXSTACK], jawab;

    puts("MENGUBAH NOTASI INFIX MENJADI POSTFIX");
    puts("DENGAN MEMANFAATKAN STRUKTUR STACK");
    do {
        InitializeStack(&tumpukan);
        fflush(stdin);
        puts("");
        printf("Masukan ekspresi dalam notasi infix : ");
        fgets(tampung, sizeof(tampung), stdin);

        if (cek_infix(tampung)) {
            printf("Ungkapan postfixnya = ");
            konversi_cetak(tampung);
            puts("");
        }

        fflush(stdin);
        printf("\nMau mencoba lagi (y/t) ? ");
        scanf(" %c", &jawab);
        while (getchar() != '\n');
    } while((jawab == 'y') || (jawab == 'Y'));

    return 0;
}

int cek_infix(char temp[])
{
    int i, pjg = strlen(temp);
    int kurung = 0;
    int prev_type = -1;
    char c;

    for (i = 0; i < pjg; i++) {
        c = temp[i];

        if (c == ' ' || c == '\n' || c == '\r') continue;

        if (isdigit(c)) {
            if (prev_type == 3 || prev_type == 0) {
                printf("Output : Notasi infix salah, operator tidak lengkap\n");
                return 0;
            }
            prev_type = 0;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            if (prev_type == -1 || prev_type == 2) {
                printf("Output : Notasi infix salah, operand tidak lengkap\n");
                return 0;
            }
            prev_type = 1;
        }
        else if (c == '(') {
            if (prev_type == 0 || prev_type == 3) {
                printf("Output : Notasi infix salah, operator tidak lengkap\n");
                return 0;
            }
            prev_type = 2;
            kurung++;
        }
        else if (c == ')') {
            if (prev_type == 1 || prev_type == 2) {
                printf("Output : Notasi infix salah, operand tidak lengkap\n");
                return 0;
            }
            prev_type = 3;
            kurung--;

            if (kurung < 0) {
                printf("Output : Notasi infix salah, kurung tidak lengkap\n");
                return 0;
            }
        }
    }

    if (kurung != 0) {
        printf("Output : Notasi infix salah, kurung tidak lengkap\n");
        return 0;
    }

    if (prev_type == 1) {
        printf("Output : Notasi infix salah, operand tidak lengkap\n");
        return 0;
    }

    return 1;
}

void InitializeStack(Stack *S)
{
    S->count = 0;
}

int Empty(Stack *S)
{
    return (S->count == 0);
}

int Full(Stack *S)
{
    return (S->count == MAXSTACK);
}

void Push(ItemType x, Stack *S)
{
    if (Full(S))
        printf("Stack penuh! Data tidak dapat masuk!");
    else {
        ++(S->count);
        S->item[S->count] = x;
    }
}

ItemType Pop(Stack *S)
{
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

int drjt(char x)
{
    if (x == '(')
        return 0;
    else if((x == '+') || (x == '-'))
        return 1;
    else if ((x == '*') || (x == '/'))
        return 2;
    else if (x == '^')
        return 3;
    else
        return -1;
}

void konversi_cetak(char temp[])
{
    int i, pjg, valid = 1;
    char kar, smtr;

    pjg = strlen(temp) - 1;

    for (i = 0; i < pjg; i++)
    {
        kar = temp[i];

        switch (kar) {
            case '(':
                Push(kar, &tumpukan);
                break;

            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                printf("%c", kar);
                break;

            case '+': case '-': case '*': case '/': case '^':
                if((Empty(&tumpukan)) || ((drjt(kar) > drjt(tumpukan.item[tumpukan.count]))))
                    Push(kar, &tumpukan);
                else {
                    do {
                        smtr = Pop(&tumpukan);
                        printf("%c", smtr);
                    } while (drjt(kar) <= drjt(tumpukan.item[tumpukan.count]) && !Empty(&tumpukan));
                    Push(kar, &tumpukan);
                }
                break;

            case ')':
                while (tumpukan.item[tumpukan.count] != '(') {
                    smtr = Pop(&tumpukan);
                    printf("%c", smtr);
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

    if ((valid != 0) && (!Empty(&tumpukan)))
    {
        while (!Empty(&tumpukan)) {
            smtr = Pop(&tumpukan);
            printf("%c", smtr);
        }
    }
}