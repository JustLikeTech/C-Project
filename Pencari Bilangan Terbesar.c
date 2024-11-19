// Pencari Bilangan Terbesar

#include <stdio.h>

int main() {
    int bilangan[10]; // Array untuk menyimpan 10 bilangan
    int temp;

    printf("===== Selamat Datang Di Program Pencari Bilangan Terbesar=====\n");
    // Meminta pengguna untuk memasukkan 10 bilangan
    printf("\nMasukkan 10 bilangan:\n");
    for (int i = 0; i < 10; i++) {
        printf("Bilangan ke-%d: ", i + 1);
        scanf("%d", &bilangan[i]);
    }

    // Melakukan pengurutan dalam urutan menurun
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (bilangan[i] < bilangan[j]) {
                // Menukar bilangan jika bilangan[i] < bilangan[j]
                temp = bilangan[i];
                bilangan[i] = bilangan[j];
                bilangan[j] = temp;
            }
        }
    }

    // Mencetak bilangan dalam urutan menurun
    printf("Bilangan dalam urutan menurun:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", bilangan[i]);
    }

    return 0;
}
