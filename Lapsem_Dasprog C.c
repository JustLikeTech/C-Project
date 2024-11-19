#include <stdio.h>

int main() {
    double A, B, C, luas;

    A = 1.0 / 2.0;

    printf("Masukkan Angka Pertama: ");
    scanf("%f", &A);

    printf("Masukkan Angka Kedua: ");
    scanf("%f", &B);

    printf("Masukkan Angka Ketiga: ");
    scanf("%f", &C);

    luas = A * B * C;
    printf("Luas adalah: %f\n", luas);

    return 0;
}
