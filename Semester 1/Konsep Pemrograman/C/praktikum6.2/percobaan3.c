#include <stdio.h>

int main() {
    //char nama[] = {"Ahmad", "Adang", "Dani", "Edi"};
    int bahasa[] = {81, 80, 89, 77};
    int mtk[] = {90, 83, 55, 70};
    int digital[] = {62, 87, 65, 92};
    float rata[9999];
    int i, n = 4;

    for (i = 0; i < n; i++)
    {
        rata[i] = (bahasa[i] + mtk[i] + digital[i]) / 3.0;
    }
    
    puts ("\tNo. Mhs\t\tRata-rata");
    puts ("\t-------------------------");
    for (i = 0; i < n; i++)
    {
        printf ("\t   %d\t\t  %.2f\n", i+1, rata[i]);
    }
}