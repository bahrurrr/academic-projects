#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char nama[50];
    char tgl_lahir[12];
    char jns_kelamin;
    float gaji;
} data;
void input(data *, int);
void tampil(data *, int);
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
void input(data *p, int a) {
    int i, count = 1;
    for (i = 0; i < a; i++) {
        p->id = count;
        printf ("\nData pegawai ke-%d", count++);
        printf ("\nNama                   : ");
        fgets (p->nama, sizeof(p->nama), stdin);
        p->nama[strcspn(p->nama, "\n")] = '\0';
        printf ("Tgl lahir <dd-mm-yyyy> : ");
        fgets (p->tgl_lahir, sizeof(p->tgl_lahir), stdin);
        p->tgl_lahir[strcspn(p->tgl_lahir, "\n")] = '\0';
        printf ("Jenis Kelamin [L/P]    : ");
        scanf (" %c", &p->jns_kelamin);
        printf ("Gaji/bln               : ");
        scanf ("%f", &p->gaji); 
        getchar();
        p++;
    }
}
void tampil(data *p, int a) {
    int i;
    printf ("\nData pegawai yang telah diinputkan\n\n");
    for (i = 0; i < a; i++)
    {
        printf ("No id                  : %d\n", p->id);
        printf ("Nama                   : %s\n", p->nama);
        printf ("Tgl lahir <dd-mm-yyyy> : %s\n", p->tgl_lahir);
        printf ("Jenis Kelamin [L/P]    : %c\n", p->jns_kelamin);
        printf ("Gaji/bln               : Rp %.2f\n", p->gaji);
        puts ("");
        p++;
    }
}