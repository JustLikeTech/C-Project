#include <stdio.h>

// Struktur untuk menyimpan data mahasiswa
struct Mahasiswa {
    char nim[20];
    char nama[50];
    float nilai[10];  // Array untuk menyimpan nilai mata kuliah
    int jumlahSks[10]; // Array untuk menyimpan jumlah SKS mata kuliah
    int jumlahMataKuliah;
};

// Fungsi untuk menambah data mahasiswa
void tambahData(struct Mahasiswa *mahasiswa) {
    printf("Masukkan NIM: ");
    scanf("%s", mahasiswa->nim);

    printf("Masukkan Nama: ");
    scanf("%s", mahasiswa->nama);

    printf("Jumlah Mata Kuliah: ");
    scanf("%d", &mahasiswa->jumlahMataKuliah);

    for (int i = 0; i < mahasiswa->jumlahMataKuliah; i++) {
        printf("Masukkan Nilai Mata Kuliah %d (A/B/AB/C/BC/D/E): ", i + 1);
        char nilai[3];
        scanf("%s", nilai);

        if (nilai[0] == 'A') {
            mahasiswa->nilai[i] = 4.0;
        } else if (nilai[0] == 'B') {
            mahasiswa->nilai[i] = 3.0;
        } else if (nilai[0] == 'A' && nilai[1] == 'B') {
            mahasiswa->nilai[i] = 3.5;
        } else if (nilai[0] == 'C') {
            mahasiswa->nilai[i] = 2.0;
        } else if (nilai[0] == 'B' && nilai[1] == 'C') {
            mahasiswa->nilai[i] = 2.5;
        } else if (nilai[0] == 'D') {
            mahasiswa->nilai[i] = 1.5;
        } else if (nilai[0] == 'E') {
            mahasiswa->nilai[i] = 0.0;
        } else {
            printf("Nilai tidak valid. Masukkan nilai yang sesuai (A/B/AB/C/BC/D/E).\n");
            i--; // Ulangi iterasi untuk nilai yang tidak valid
        }

        printf("Masukkan Jumlah SKS Mata Kuliah %d: ", i + 1);
        scanf("%d", &mahasiswa->jumlahSks[i]);
    }
}

// Fungsi untuk menampilkan IPK
void lihatIPK(struct Mahasiswa *mahasiswa) {
    float totalBobot = 0;
    int totalSks = 0;

    for (int i = 0; i < mahasiswa->jumlahMataKuliah; i++) {
        totalBobot += mahasiswa->nilai[i] * mahasiswa->jumlahSks[i];
        totalSks += mahasiswa->jumlahSks[i];
    }

    if (totalSks == 0) {
        printf("Belum ada data mata kuliah.\n");
    } else {
        float ipk = totalBobot / totalSks;
        printf("IPK Mahasiswa: %.2f\n", ipk);
    }
}

int main() {
    struct Mahasiswa mahasiswa;

    // Buka file untuk menyimpan data mahasiswa
    FILE *file = fopen("mahasiswa_db.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Gagal membuka file.\n");
        return 1;
    }

    // Tambahkan data mahasiswa
    tambahData(&mahasiswa);

    // Simpan data mahasiswa ke file
    fprintf(file, "Nim: %s\n", mahasiswa.nim); // Input
    fprintf(file, "Nama: %s\n", mahasiswa.nama); // Input
    fprintf(file, "Nilai Mata Kuliah:\n"); // Input

    for (int i = 0; i < mahasiswa.jumlahMataKuliah; i++) {
        fprintf(file, "%d. Nilai: %.2f, SKS: %d\n", i + 1, mahasiswa.nilai[i], mahasiswa.jumlahSks[i]);
    }

    // Tutup file
    fclose(file);

    // Tampilkan IPK
    lihatIPK(&mahasiswa);

    return 0;
}

