#include <stdio.h>
#include <string.h>

int main() {
    char arr[] = "pensit";
    int pjg = strlen(arr);

    printf("kata awal : %s\n\n", arr);

    for (int i = 0; i < pjg / 2; i++)
    {
        char tmp = arr[i];
        arr[i] = arr[pjg - i - 1];
        arr[pjg - i - 1] = tmp;
    }
    
    printf("setelah dibalik : %s", arr);
    return 0;
}