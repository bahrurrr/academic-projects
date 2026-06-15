#include <stdio.h>

int masukkan(int);
float average(int, float);
int main() {
    int n, i, a;
    float b;
    printf ("berapa kali anda ingin memasukkan nilai : ");
    scanf ("%d", &n);
    
    a = masukkan(n);
    b = average(n, a);
    printf ("total jumlah data anda : %d dan average nya : %.2f", a, b);

}
int masukkan(int x) {
    int total, i, j = 0;
    for (i = 1; i <= x; i++)
    {
        printf ("nilai ke-%d : ", i);
        scanf ("%d", &total);

        j += total;
    }
    return j;
}
float average(int x, float y) {
    float rata;
    if (y == 0)
    {
        return 0;
    }
    else rata = y / x;
    return rata;
}