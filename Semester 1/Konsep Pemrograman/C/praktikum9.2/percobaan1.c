#include <stdio.h>
#include <string.h>

struct datamhs
{
    char nama[20], grade;
    int nrp;
    float nilaitugas, nilaiuts, nilaiuas, nilaiakhir;
};

void input(struct datamhs [], int);
void tampil(struct datamhs [], int);

int main() {
    int n;
    struct datamhs mhs[10];

    puts ("MENGHITUNG NILAI AKHIR\nMATA KULIAH KONSEP PEMROGRAMAN\n");
    printf ("Berapa jumlah mahasiswa ? ");
    scanf ("%d", &n);
    while (getchar() != '\n');

    input(mhs, n);
    tampil(mhs, n);

    return 0;
}

void input(struct datamhs mhs[], int a) {
    int i = 0, counter = 1;
    puts("\nMasukkan DATA Mahasiswa");
    do {
        printf ("\nMahasiswa ke-%d\n", counter++);
        printf("Nama           : ");
        fgets(mhs[i].nama, sizeof(mhs[i].nama), stdin);
        mhs[i].nama[strcspn(mhs[i].nama, "\n")] = '\0';
        printf("Nilai tugas    : ");
        scanf("%f", &mhs[i].nilaitugas);
        printf("Nilai uts      : ");
        scanf("%f", &mhs[i].nilaiuts);
        printf("Nilai uas      : ");
        scanf("%f", &mhs[i].nilaiuas);
        while (getchar() != '\n');

        mhs[i].nilaiakhir = (mhs[i].nilaitugas * 0.2) +
                            (mhs[i].nilaiuts * 0.4) +
                            (mhs[i].nilaiuas * 0.4);

        i++;
    } while (i < a);
}

void tampil(struct datamhs mhs[], int n) {
    printf("\n\n\tDAFTAR NILAI\n");
    printf("\tMATAKULIAH KONSEP PEMROGRAMAN\n");
    printf("===============================================================\n");
    printf("No  Nama Mahasiswa       Tugas  UTS   UAS   Akhir   Grade\n");
    printf("===============================================================\n");

    for (int i = 0; i < n; i++) {
        if (mhs[i].nilaiakhir >= 80) mhs[i].grade = 'A';
        else if (mhs[i].nilaiakhir >= 70) mhs[i].grade = 'B';
        else if (mhs[i].nilaiakhir >= 60) mhs[i].grade = 'C';
        else if (mhs[i].nilaiakhir >= 50) mhs[i].grade = 'D';
        else mhs[i].grade = 'E';

        printf("%-3d %-20s %-6.0f %-5.0f %-5.0f %-7.0f %3c\n",
               i + 1,
               mhs[i].nama,
               mhs[i].nilaitugas,
               mhs[i].nilaiuts,
               mhs[i].nilaiuas,
               mhs[i].nilaiakhir,
               mhs[i].grade);
    }

    printf("===============================================================\n");
    printf("Total Mahasiswa = %d\n", n);
    printf("Press any key to continue...\n");
}