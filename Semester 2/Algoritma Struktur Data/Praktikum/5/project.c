#include <stdio.h>
#include <stdlib.h>

typedef struct simpulMhs Mahasiswa;
typedef struct simpulMK MataKuliah;
struct simpulMhs {
    int NRP;
    char Nama[30];
    char Prodi[15];
    Mahasiswa *nextMhs;
    Mahasiswa *prevMhs;
    MataKuliah *next;
};
struct simpulMK {
    char KodeMK[6];
    char NamaMK[15];
    int Nilai;
    MataKuliah *nextMK;
};

Mahasiswa *head = NULL;
Mahasiswa *tail = NULL;

Mahasiswa *buat_simpul(int);
void free_node(Mahasiswa *);
void sisip_terurut(int);
void hapus_mhs(int);
void hapus_mk(int);
void update_mhs(int);
void tampilkan();

int main() {
    
}