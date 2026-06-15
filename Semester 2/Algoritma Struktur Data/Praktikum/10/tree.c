#include <stdio.h>
#include <stdlib.h>

struct tree {
    int info; 
    struct tree *kiri;
    struct tree *kanan;
};

typedef struct tree *pohon;

pohon baru(int data);
void sisip(pohon ph, pohon sp);
void preorder(pohon ph);
void inorder(pohon ph);
void postorder(pohon ph);
int hitung_size(pohon ph);
int hitung_depth(pohon ph);

int main() {
    pohon root = NULL;
    pohon node_baru;
    int n, data;

    printf("pembentukan binary search tree\n");
    printf("masukkan jumlah data yang ingin diinput: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("masukkan data ke-%d: ", i + 1);
        scanf("%d", &data);
        
        if (root == NULL) {
            root = baru(data);
        } else {
            node_baru = baru(data);
            sisip(root, node_baru);
        }
    }

    printf("\nhasil penelusuran:\n");
    printf("preorder  : "); preorder(root); printf("\n"); 
    printf("inorder   : "); inorder(root); printf("\n");
    printf("postorder : "); postorder(root); printf("\n");

    printf("\nanalisis pohon:\n");
    printf("jumlah simpul (size) : %d\n", hitung_size(root)); 
    printf("kedalaman (depth)    : %d\n", hitung_depth(root)); 

    return 0;
}

pohon baru(int data) {
    pohon br = (pohon)malloc(sizeof(struct tree));
    if (br != NULL) {
        br->info = data;
        br->kiri = NULL;  
        br->kanan = NULL; 
    }
    return br;
}

void sisip(pohon ph, pohon sp) {
    pohon p = ph;
    pohon q = ph;

    while (q != NULL) {
        p = q;
        if (sp->info == p->info) {
            printf("data %d sudah ada di dalam tree!\n", sp->info);
            return;
        } else if (sp->info < p->info) {
            q = p->kiri; 
        } else {
            q = p->kanan; 
        }
    }

    if (sp->info < p->info) {
        p->kiri = sp; 
    } else {
        p->kanan = sp; 
    }
}

void preorder(pohon ph) {
    if (ph != NULL) { 
        printf("%d ", ph->info); 
        preorder(ph->kiri);      
        preorder(ph->kanan);     
    }
}

void inorder(pohon ph) {
    if (ph != NULL) { 
        inorder(ph->kiri);       
        printf("%d ", ph->info); 
        inorder(ph->kanan);      
    }
}

void postorder(pohon ph) {
    if (ph != NULL) { 
        postorder(ph->kiri);     
        postorder(ph->kanan);    
        printf("%d ", ph->info); 
    }
}

int hitung_size(pohon ph) {
    if (ph == NULL) return 0;
    return 1 + hitung_size(ph->kiri) + hitung_size(ph->kanan);
}

int hitung_depth(pohon ph) {
    if (ph == NULL) return -1; 
    int depth_kiri = hitung_depth(ph->kiri);
    int depth_kanan = hitung_depth(ph->kanan);
    
    if (depth_kiri > depth_kanan) {
        return depth_kiri + 1;
    } else {
        return depth_kanan + 1;
    }
}