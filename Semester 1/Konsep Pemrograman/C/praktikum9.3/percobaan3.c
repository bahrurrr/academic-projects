#include <stdio.h>
#include <string.h>

typedef struct
{
    char nama[20], grade;
    int nrp;
    float nilaitugas, nilaiuts, nilaiuas, nilaiakhir;
} data;

void input(data *, int);
void tampil(data *, int);

int main() {
    int n;
    data mhs[10];

    puts ("MENGHITUNG NILAI AKHIR\nMATA KULIAH KONSEP PEMROGRAMAN\n");
    printf ("Berapa jumlah mahasiswa ? ");
    scanf ("%d", &n);
    while (getchar() != '\n');

    input(mhs, n);
    tampil(mhs, n);

    return 0;
}

void input(data *m, int a) {
    int i = 0, counter = 1;
    puts("\nMasukkan DATA Mahasiswa");
    do {
        printf ("\nMahasiswa ke-%d\n", counter++);
        printf("Nama           : ");
        fgets(m->nama, sizeof(m->nama), stdin);
        m->nama[strcspn(m->nama, "\n")] = '\0';
        printf("Nilai tugas    : ");
        scanf("%f", &m->nilaitugas);
        printf("Nilai uts      : ");
        scanf("%f", &m->nilaiuts);
        printf("Nilai uas      : ");
        scanf("%f", &m->nilaiuas);
        while (getchar() != '\n');

        m->nilaiakhir = (m->nilaitugas * 0.2) +
                            (m->nilaiuts * 0.4) +
                            (m->nilaiuas * 0.4);

        i++;
        m++;
    } while (i < a);
}

void tampil(data *m, int n) {
    printf("\n\n\tDAFTAR NILAI\n");
    printf("\tMATAKULIAH KONSEP PEMROGRAMAN\n");
    printf("===============================================================\n");
    printf("No  Nama Mahasiswa       Tugas  UTS   UAS   Akhir   Grade\n");
    printf("===============================================================\n");

    for (int i = 0; i < n; i++) {
        if (m->nilaiakhir >= 80) m->grade = 'A';
        else if (m->nilaiakhir >= 70) m->grade = 'B';
        else if (m->nilaiakhir >= 60) m->grade = 'C';
        else if (m->nilaiakhir >= 50) m->grade = 'D';
        else m->grade = 'E';

        printf("%-3d %-20s %-6.0f %-5.0f %-5.0f %-7.0f %3c\n",
               i + 1,
               m->nama,
               m->nilaitugas,
               m->nilaiuts,
               m->nilaiuas,
               m->nilaiakhir,
               m->grade);
        m++;
    }

    printf("===============================================================\n");
    printf("Total Mahasiswa = %d\n", n);
    printf("Press any key to continue...\n");
}