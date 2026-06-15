#include <stdio.h>

int main()
{
    float bil1, bil2, tambah,kurang, bagi, kali;
    int pilihan;

    printf ("masukkan bilangan pertama : ");
    scanf ("%f", &bil1);
    printf ("masukkan bilangan kedua : ");
    scanf ("%f", &bil2);
    
    puts ("menu matematika :\n1. penjumlahan\n2. pengurangan\n3. pembagian\n4. perkalian");
    printf ("masukkan pilihan anda : ");
    scanf ("%d", &pilihan);

    if (pilihan == 1)
    {
        tambah = bil1 + bil2;
        printf ("hasil operasi tersebut adalah : %.2f\n", tambah);
    }
        else if (pilihan == 2)
        {
            kurang = bil1 - bil2;
            printf ("hasil operasi tersebut adalah : %.2f\n", kurang);
        }
    else if (pilihan == 3)
    {
        if (bil2 != 0) 
        {
        bagi = bil1 / bil2;
        printf ("hasil operasi tersebut adalah : %.2f\n", bagi);
        }
            else 
            { 
                printf("error : pembagi tidak boleh 0\n");
            }
    }
    else if (pilihan == 4)
    {
        kali = bil1 * bil2;
        printf ("hasil operasi tersebut adalah : %.2f\n", kali);
    }
        else
        {
            printf ("pilihan tidak valid!\n");
        }

return 0;
}