// Mencari Nilai Terkecil Dari Tiga Bilangan From Input

#include <stdio.h>

int main() {
    int angka1, angka2, angka3, terkecil;

    printf("Masukkan tiga angka: ");
    scanf("%d %d %d", &angka1, &angka2, &angka3);

    if (angka1 <= angka2) {
        if (angka1 <= angka3) {
            terkecil = angka1;
        } else {
            terkecil = angka3;
        }
    } else {
        if (angka2 <= angka3) {
            terkecil = angka2;
        } else {
            terkecil = angka3;
        }
    }

    printf("Nilai terkecil adalah: %d\n", terkecil);

    return 0;
}
