#include <stdio.h>

int main()
{
    int n;
    printf("masukkan jumlah elemen: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("jumlah elemen harus positif.\n");
    } else {
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            printf("masukkan elemen ke-%d: ", i + 1);
            scanf("%d", &arr[i]);
        }

        for (int i = n - 2; i >= 0; i--)
        {
            int key = arr[i];
            int j = i + 1;

            while (j < n && arr[j] < key)
            {
                arr[j - 1] = arr[j];
                j++;
            }

            arr[j - 1] = key;
        }

        printf("\nhasil pengurutan ascending: \n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    };

    return 0;
}
