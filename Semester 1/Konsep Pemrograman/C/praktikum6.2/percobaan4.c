#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main() {
    int x[] = {0, 30, 60, 90, 120, 150, 180, 210, 240, 270, 300, 330, 360};
    double data[13][3];
    int i, j;
    double rad = 0;
    
    for (i = 0; i < 13; i++)
    {
        rad = x[i] * M_PI / 180.0;
        data[i][0] = sin(rad);
        data[i][1] = cos(rad);
        data[i][2] = tan(rad);
    }

    printf ("x\t\tsin(x)\t\tcos(x)\t\ttan(x)\n");

    for (i = 0; i < 13; i++)
    {
        printf ("%d\t\t%.2f\t\t%.2f\t\t%.2f\n", x[i], data[i][0], data[i][1], data[i][2]);
    }
    
}