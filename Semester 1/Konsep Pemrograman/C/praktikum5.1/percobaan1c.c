#include <stdio.h>

void menu (int);
int main(){
    int n;
    printf ("berpa banyak ingin menampilkan : ");
    scanf ("%d", &n);
    
    for (int i = 1; i <= n; i++){
         menu(n);
    }
}

void menu (int n){
    printf ("pilhan menu\n");
}