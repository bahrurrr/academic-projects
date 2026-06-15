#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char nama[50];
    char tgl_lahir[12];
    char jns_kelamin;
    float gaji;
} data;
void input(data [] , int);
void tampil(data [], int);
int main() {
    data pegawai[5];
    int n;
    printf ("\t\tDATA PEGAWAI\n\n");
    printf ("Berapa jumlah pegawai : ");
    scanf ("%d", &n);
    getchar();

    input(pegawai, n);
    tampil(pegawai, n);
}
void input(data p[], int a) {
    int i, count = 1;
    for (i = 0; i < a; i++) {
        p[i].id = count;
        printf ("\nData pegawai ke-%d", count++);
        printf ("\nNama                   : ");
        fgets (p[i].nama, sizeof(p[i].nama), stdin);
        p[i].nama[strcspn(p[i].nama, "\n")] = '\0';
        printf ("Tgl lahir <dd-mm-yyyy> : ");
        fgets (p[i].tgl_lahir, sizeof(p[i].tgl_lahir), stdin);
        p[i].tgl_lahir[strcspn(p[i].tgl_lahir, "\n")] = '\0';
        printf ("Jenis Kelamin [L/P]    : ");
        scanf (" %c", &p[i].jns_kelamin);
        printf ("Gaji/bln               : ");
        scanf ("%f", &p[i].gaji); 
        getchar();
    }
}
void tampil(data p[], int a) {
    int i;
    printf ("\nData pegawai yang telah diinputkan\n\n");
    for (i = 0; i < a; i++)
    {
        printf ("No id                  : %d\n", p[i].id);
        printf ("Nama                   : %s\n", p[i].nama);
        printf ("Tgl lahir <dd-mm-yyyy> : %s\n", p[i].tgl_lahir);
        printf ("Jenis Kelamin [L/P]    : %c\n", p[i].jns_kelamin);
        printf ("Gaji/bln               : %.2f\n", p[i].gaji);
        puts ("");
    }
}