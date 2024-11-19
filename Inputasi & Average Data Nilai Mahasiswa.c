// Inputasi & Average Data Nilai Mahasiswa

#include <stdio.h>

int main() {
    int jumlah_mahasiswa;

    printf("===== Selamat Datang Di Program Penginputan Dan Perhitungan Nilai Rata Rata Mahasiswa =====\n\n");

    printf("Jumlah mahasiswa: ");
    scanf("%d", &jumlah_mahasiswa);

    double nilai_mahasiswa[jumlah_mahasiswa][2]; // [0] untuk total nilai, [1] untuk rata-rata
    char nama_mahasiswa[jumlah_mahasiswa][50]; // Array untuk nama mahasiswa

    for (int i = 0; i < jumlah_mahasiswa; i++) {
        printf("\nNama Mahasiswa-%d: ", i + 1);
        scanf("%s", nama_mahasiswa[i]);

        printf("Jumlah nilai: ");
        int jumlah_nilai;
        scanf("%d", &jumlah_nilai);

        nilai_mahasiswa[i][0] = 0.0; // Inisialisasi total nilai

        for (int j = 0; j < jumlah_nilai; j++) {
            double temp;
            printf("Nilai-%d: ", j + 1);
            scanf("%lf", &temp);
            nilai_mahasiswa[i][0] += temp; // Menambahkan nilai ke total nilai
        }

        // Menghitung rata-rata nilai
        nilai_mahasiswa[i][1] = nilai_mahasiswa[i][0] / jumlah_nilai;
    }

    for (int i = 0; i < jumlah_mahasiswa; i++) {
        printf("\nRata-rata Nilai Mahasiswa-%d (%s): %.2lf\n", i + 1, nama_mahasiswa[i], nilai_mahasiswa[i][1]);
    }

    return 0;
}
