#include <stdio.h>
#include <string.h>
#define max 500

char str[max];
void token(char *);
int main() {
    printf ("masukkan kalimat : ");
    fgets (str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    
    token(str);
}
void token(char *a) {
    int token = 1;
    char *p = a;

    while (*p != '\0') {
        while (*p == ' ') {
            p++;
        }
        if (*p == '\0')
            break;

        printf("Token %d: ", token);
        token++;

        while (*p != ' ' && *p != '\0' && *p != '\n') {
            putchar(*p);
            p++;
        }

        printf("\n");
    }
}