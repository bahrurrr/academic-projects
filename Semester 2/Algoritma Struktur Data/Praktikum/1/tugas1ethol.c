#include <stdio.h>
#include <stdlib.h>

struct statis {
    int data[10];
};

struct dinamis {
    int *data;
};

int main() {
    struct statis isi1;
    struct dinamis isi2;
    int n, i, temp;

    printf("banyak data yang diinput : ");
    scanf("%d", &n);

    isi2.data = (int*) malloc(n * sizeof(int));

    printf("masukkan data : \n");
    for (i = 0; i < n; i++) {
        printf("data ke-%d : ", i+1);
        scanf("%d", &temp);

        isi2.data[i] = temp;

        if (i < 10) {
            isi1.data[i] = temp;
        }
    }
    puts(" ");
    for (i = 0; i < n; i++) {
        if (i < 10) {
            printf("hasil statis ke-%d: %d\n", i+1, isi1.data[i]);
        } else {
            printf("hasil statis ke-%d: tidak muat\n", i+1);
        }
    }
    puts(" ");
    for (i = 0; i < n; i++) {
        printf("hasil dinamis ke-%d: %d\n", i+1, isi2.data[i]);
    }

    free(isi2.data);
}