#include <stdio.h>

struct date
{
    int d, m, y;
};
void tom(int, int , int);
int main() {
    struct date today;
    printf ("masukkan tanggal hari ini(dd mm yyyy) : ");
    scanf ("%d %d %d", &today.d, &today.m, &today.y);

    printf ("tanggal yang ada masukkan : %d-%d-%d\n", today.d, today.m, today.y);

    tom(today.d, today.m, today.y);
}
void tom(int a, int b, int c) {
    struct date besok;
    besok.d = a;
    besok.m = b;
    besok.y = c;
    
    if ((c % 400 == 0) || (c % 4 == 0 && c % 100 != 0))
    {
        if (a == 29 && b == 2)
        {
            besok.d = 1;
            besok.m++;
        }
        if (a == 31 && b == 12)
        {
            besok.d = 1;
            besok.m = 1;
            besok.y++;
        }
        else if (a == 31)
        {
            if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12)
            {
                besok.d = 1;
                besok.m++;
            }
        }
        else if (a == 30)
        {
            if (b == 4 || b == 6 || b == 9 || b == 11)
            {
                besok.d = 1;
                besok.m++;
            }
        }
        else besok.d++;
    }
    else
    {
        if (a == 28 && b == 2)
        {
            besok.d = 1;
            besok.m++;
        }
        if (a == 31 && b == 12)
        {
            besok.d = 1;
            besok.m = 1;
            besok.y++;
        }
        else if (a == 31)
        {
            if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12)
            {
                besok.d = 1;
                besok.m++;
            }
        }
        else if (a == 30)
        {
            if (b == 4 || b == 6 || b == 9 || b == 11)
            {
                besok.d = 1;
                besok.m++;
            }
        }
        else besok.d++;
    }

    printf ("besok adalah : %d-%d-%d", besok.d, besok.m, besok.y);
}