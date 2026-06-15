#include <stdio.h>
#define max 20
struct date {
    int m, d, y;
};
struct student {
    char name[30];
    struct date birthday;
};
int main() {
    struct student data_mhs[max];
    int i = 0, jml;
    char lagi;
    do
    {
        printf ("nama : ");
        gets (data_mhs[i].name);
        printf ("birthday (mm dd yyy) : ");
        scanf ("%d %d %d", &data_mhs[i].birthday.m, &data_mhs[i].birthday.d, &data_mhs[i].birthday.y);
        i++;
        fflush(stdin);
        printf ("\nmau memasukkan data lagi [Y/T] : ");
        lagi = getchar();
        fflush(stdin);
    } while (lagi == 'Y' || lagi == 'y');
    
    jml = i;
    printf ("\nDATA MAHASISWA\n");
    for (i = 0; i < jml; i++)
    {
        printf ("%d. name : %s", i+1, data_mhs[i].name);
        printf("\n birthday : %d-%d-%d\n\n", data_mhs[i].birthday.m, data_mhs[i].birthday.d, data_mhs[i].birthday.y);
    }
}