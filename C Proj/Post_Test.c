#include <stdio.h>

int hitungBilanganGenap(int jumlahBilangan){
    int i, bilangan = 2, jumlahGenap= 0;

    for ( i = 2; i <= 2* jumlahBilangan; i += 2)
    {
        jumlahGenap += bilangan;
        bilangan += 2;
    }
    return jumlahGenap;
}

int main(){
    int jumlahBilangan, hasil;

    printf("===== Program Menghitung Bilangan Genap Dimulai Dari 2 =====\n");
    
    printf("\nMasukkan Jumlah Bilangan: ");
    scanf("%d", &jumlahBilangan);

    hasil = hitungBilanganGenap(jumlahBilangan);

    printf("\nJumlah Bilangan Genap Dari %d Bilangan Pertama Adalah %d\n", jumlahBilangan, hasil);

    printf("\n===== Terima Kasih Sudah Menggunakan Program Ini =====");
    return 0;
}