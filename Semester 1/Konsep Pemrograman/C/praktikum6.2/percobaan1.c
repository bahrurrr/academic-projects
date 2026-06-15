#include <stdio.h>

void input(int nilai[], int *);
int max(int nilai[], int);
int main() {
    int nilai[9999];
    int n, hasil;

    input(nilai, &n);
    hasil = max(nilai, n);

    printf ("nilai terbesar input anda : %d", hasil);
}
void input(int nilai[], int *n) {
    int i;

    printf ("berapa jumlah yang ingin anda input : ");
    scanf ("%d", n);
    
    for (i = 0; i < *n; i++)
    {
        printf ("nilai ke-%d : ", i+1);
        scanf ("%d", &nilai[i]);
    }
}
int max(int nilai[], int n) {
    int max, i;
    max = nilai[0];
    
    for (i = 0; i < n; i++)
    {
        if (max <=  nilai[i])
        {
            max = nilai[i];
        }
    }
    return max;
}