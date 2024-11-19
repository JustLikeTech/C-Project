// Program Laporan Resmi

#include <stdio.h>
#include <string.h>

int main()
{
    char kata[] = "POLITEKNIK";
    int panjangKata = strlen(kata);

    // Modifikasi program untuk menghasilkan keluaran sesuai dengan skenario
    for (int i = 1; i <= panjangKata; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%c", kata[j]);
        }
        printf("\n");
    }

    return 0;
}
