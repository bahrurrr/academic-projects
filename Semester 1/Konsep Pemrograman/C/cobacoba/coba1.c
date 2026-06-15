#include <stdio.h>
#include <string.h>

int suhu[] = {5, 10, 20, 30, 50, 40, 30, 20, 10, 5};
int main() {
    float rata2, total = 0;
    int i, max = suhu[0], min = suhu[0], jml;

    jml = sizeof(suhu) / sizeof(suhu[0]);
    for (i = 0; i < jml; i++)
    {
        total += suhu[i];
        
        if (max < suhu[i])
        {
            max = suhu[i];
        }
        if (min > suhu[i])
        {
            min = suhu[i];
        }
    }
    rata2 = total / jml;

    printf ("rata-rata suhu : %.2f\n", rata2);
    printf ("suhu minimum : %d\n", min);
    printf ("suhu maksimum : %d\n", max);

    if (rata2 < 30)
    {
        puts ("suhu anda normal");
    }
    else puts ("suhu anda panas");
}