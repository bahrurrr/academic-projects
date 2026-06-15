#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define null 0

typedef struct simpulmhs mahasiswa;
typedef struct simpulmk matakuliah;

struct simpulmhs {
    long long nrp;
    char nama[30];
    char prodi[30];
    mahasiswa *nextmhs;
    mahasiswa *prevmhs;
    matakuliah *next;
};

struct simpulmk {
    char kodemk[6];
    char namamk[15];
    int nilai;
    matakuliah *nextmk;
};

void inisialisasi(mahasiswa **head);
mahasiswa* buat_mhs(long long nrp, char nama[], char prodi[]);
matakuliah* buat_mk(char kode[], char nama[], int nilai);
void sisip_mhs(mahasiswa **head, long long nrp, char nama[], char prodi[]);
void hapus_mhs(mahasiswa **head, long long target);
void update_mhs(mahasiswa *head, long long target, char nama[], char prodi[]);
void sisip_mk(mahasiswa *head, long long target, char kode[], char nama[], int nilai);
void hapus_mk(mahasiswa *head, long long target, char kode[]);
void tampil(mahasiswa *head);

int main() {
    mahasiswa *head;
    
    inisialisasi(&head);
    
    int menu;
    int jalan = 1;

    while (jalan == 1) {
        printf("\n1. tambah mahasiswa\n2. hapus mahasiswa\n3. update mahasiswa\n4. tambah mata kuliah\n5. hapus mata kuliah\n6. tampil data\n7. keluar\npilih: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1: {
                long long nrp;
                char nama[30];
                char prodi[30];
                
                printf("nrp: "); 
                scanf("%lld", &nrp);
                
                printf("nama: "); 
                scanf(" %29[^\n]", nama);
                
                printf("prodi: "); 
                scanf(" %29[^\n]", prodi);
                
                sisip_mhs(&head, nrp, nama, prodi);
                break;
            }
            case 2: {
                long long target;
                
                printf("nrp dihapus: "); 
                scanf("%lld", &target);
                
                hapus_mhs(&head, target);
                break;
            }
            case 3: {
                long long target;
                char nama[30];
                char prodi[30];
                
                printf("nrp diupdate: "); 
                scanf("%lld", &target);
                
                printf("nama baru: "); 
                scanf(" %29[^\n]", nama);
                
                printf("prodi baru: "); 
                scanf(" %29[^\n]", prodi);
                
                update_mhs(head, target, nama, prodi);
                break;
            }
            case 4: {
                long long target;
                char kode[6];
                char nama[15];
                int nilai;
                
                printf("nrp mahasiswa: "); 
                scanf("%lld", &target);
                
                printf("kode mata kuliah: "); 
                scanf("%5s", kode);
                
                printf("nama mata kuliah: "); 
                scanf(" %14[^\n]", nama);
                
                printf("nilai: "); 
                scanf("%d", &nilai);
                
                sisip_mk(head, target, kode, nama, nilai);
                break;
            }
            case 5: {
                long long target;
                char kode[6];
                
                printf("nrp mahasiswa: "); 
                scanf("%lld", &target);
                
                printf("kode mata kuliah dihapus: "); 
                scanf("%5s", kode);
                
                hapus_mk(head, target, kode);
                break;
            }
            case 6: {
                tampil(head);
                break;
            }
            case 7: {
                jalan = 0;
                break;
            }
            default: {
                printf("pilihan salah\n");
                break;
            }
        }
    }
    
    return 0;
}

void inisialisasi(mahasiswa **head) {
    *head = null;
}

mahasiswa* buat_mhs(long long nrp, char nama[], char prodi[]) {
    mahasiswa *baru = (mahasiswa*)malloc(sizeof(mahasiswa));
    
    baru->nrp = nrp;
    strcpy(baru->nama, nama);
    strcpy(baru->prodi, prodi);
    
    baru->nextmhs = null;
    baru->prevmhs = null;
    baru->next = null;
    
    return baru;
}

matakuliah* buat_mk(char kode[], char nama[], int nilai) {
    matakuliah *baru = (matakuliah*)malloc(sizeof(matakuliah));
    
    strcpy(baru->kodemk, kode);
    strcpy(baru->namamk, nama);
    baru->nilai = nilai;
    
    baru->nextmk = null;
    
    return baru;
}

void sisip_mhs(mahasiswa **head, long long nrp, char nama[], char prodi[]) {
    mahasiswa *cek = *head;
    
    while (cek != null) {
        if (cek->nrp == nrp) {
            printf("nrp sudah ada\n");
            return;
        }
        cek = cek->nextmhs;
    }

    mahasiswa *baru = buat_mhs(nrp, nama, prodi);

    if (*head == null) {
        *head = baru;
        return;
    }

    mahasiswa *temp = *head;
    
    if (baru->nrp < temp->nrp) {
        baru->nextmhs = temp;
        temp->prevmhs = baru;
        *head = baru;
        return;
    }

    while (temp->nextmhs != null && temp->nextmhs->nrp < baru->nrp) {
        temp = temp->nextmhs;
    }

    baru->nextmhs = temp->nextmhs;
    baru->prevmhs = temp;
    
    if (temp->nextmhs != null) {
        temp->nextmhs->prevmhs = baru;
    }
    
    temp->nextmhs = baru;
}

void hapus_mhs(mahasiswa **head, long long target) {
    mahasiswa *temp = *head;
    
    while (temp != null && temp->nrp != target) {
        temp = temp->nextmhs;
    }
    
    if (temp == null) {
        printf("tidak ada\n");
        return;
    }
    
    matakuliah *mk = temp->next;
    
    while (mk != null) {
        matakuliah *hapus = mk;
        mk = mk->nextmk;
        free(hapus);
    }
    
    if (temp->prevmhs != null) {
        temp->prevmhs->nextmhs = temp->nextmhs;
    } else {
        *head = temp->nextmhs;
    }
    
    if (temp->nextmhs != null) {
        temp->nextmhs->prevmhs = temp->prevmhs;
    }
    
    free(temp);
    
    printf("dihapus\n");
}

void update_mhs(mahasiswa *head, long long target, char nama[], char prodi[]) {
    while (head != null && head->nrp != target) {
        head = head->nextmhs;
    }
    
    if (head == null) {
        printf("tidak ada\n");
        return;
    }
    
    strcpy(head->nama, nama);
    strcpy(head->prodi, prodi);
    
    printf("diupdate\n");
}

void sisip_mk(mahasiswa *head, long long target, char kode[], char nama[], int nilai) {
    while (head != null && head->nrp != target) {
        head = head->nextmhs;
    }
    
    if (head == null) {
        printf("tidak ada\n");
        return;
    }
    
    matakuliah *baru = buat_mk(kode, nama, nilai);
    
    baru->nextmk = head->next;
    head->next = baru;
}

void hapus_mk(mahasiswa *head, long long target, char kode[]) {
    while (head != null && head->nrp != target) {
        head = head->nextmhs;
    }
    
    if (head == null) {
        printf("tidak ada\n");
        return;
    }
    
    matakuliah *temp = head->next;
    matakuliah *prev = null;
    
    while (temp != null && strcmp(temp->kodemk, kode) != 0) {
        prev = temp;
        temp = temp->nextmk;
    }
    
    if (temp == null) {
        printf("tidak ada\n");
        return;
    }
    
    if (prev == null) {
        head->next = temp->nextmk;
    } else {
        prev->nextmk = temp->nextmk;
    }
    
    free(temp);
    
    printf("dihapus\n");
}

void tampil(mahasiswa *head) {
    if (head == null) {
        printf("belum ada data\n");
        return;
    }

    while (head != null) {
        printf("\nnrp: %lld\nnama: %s\nprodi: %s\n", head->nrp, head->nama, head->prodi);
        
        matakuliah *mk = head->next;
        int total = 0;
        int jumlah = 0;
        
        while (mk != null) {
            printf("- %s: %s (nilai: %d)\n", mk->kodemk, mk->namamk, mk->nilai);
            
            total += mk->nilai;
            jumlah++;
            
            mk = mk->nextmk;
        }
        
        if (jumlah > 0) {
            printf("rata-rata: %d\n", total / jumlah);
        } else {
            printf("belum ada mk\n");
        }
        
        head = head->nextmhs;
    }
}