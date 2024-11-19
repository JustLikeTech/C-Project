#include <stdio.h>

// Program Konversi (Feet to Inch, Inch to Cm, Cm to M)

// Fungsi untuk mengubah ukuran dari satuan kaki (feet) ke inci
double f_to_i(double feet) {
    return feet * 12.0; // 1 kaki = 12 inchi
}

// Fungsi untuk mengubah ukuran dari satuan inci ke centimeter
double i_to_cm(double inches) {
    return inches * 2.54; // 1 inchi = 2.54 cm
}

// Fungsi untuk mengubah ukuran dari satuan centimeter ke meter
double c_to_m(double centimeters) {
    return centimeters / 100.0; // 100 cm = 1 meter
}

int main() {
    double feet, inches, centimeters, meters;
    char pilihan;

    printf("========Selamat Datang Di Program Konverter Ukuran========\n");

    // Mintalah masukan dalam satuan kaki (feet)
    printf("\nMasukkan ukuran dalam kaki (feet): ");
    scanf("%lf", &feet);

    // Konversi ke inci
    inches = f_to_i(feet);

    // Konversi ke centimeter
    centimeters = i_to_cm(inches);

    // Konversi ke meter
    meters = c_to_m(centimeters);

    // Tampilkan hasil konversi dalam meter
    printf("\nUkuran dalam meter: %.2lf meter\n", meters);
    printf("Ukuran dalam inchi: %.2lf inchi\n", inches);
    printf("Ukuran dalam centimeter: %.2lf centimeter\n", centimeters);

    do {
        // Proses yang akan diulang
        printf("Pilih Huruf y/Y Untuk Mengulangi Program");
        scanf(" %c", &pilihan);

        if (pilihan == 'Y' || pilihan == 'y') {
            // Lanjutkan proses
            printf("Meneruskan proses...\n");

            // Tambahkan proses yang ingin diulang di sini

            // Meminta input bilangan
            printf("Masukkan Suatu Bilangan : ");
            scanf("%d", &bilangan);

            // Keluar dari loop jika bilangan adalah 0
            if (bilangan == 0) {
                break; }

            // Meminta input bilangan pembagi
            printf("Masukkan bilangan pembagi (2/3/4/5): ");
            scanf("%d", &pembagi);

            // Menghitung sisa hasil pembagian
            int sisa = bilangan / pembagi;

            // Menampilkan hasil
            if (sisa == 0) {
                printf("Tidak ada sisa hasil pembagian.\n");}
            else {
            printf("Sisa hasil pembagian: %d\n", sisa); }

        } else if (pilihan == 'N' || pilihan == 'n') {
            // Keluar dari pengulangan
            printf("Keluar dari pengulangan.\n");
            break;

        } else {
        // Input tidak valid
        printf("Masukkan Y untuk terus atau N untuk berhenti.\n");
        }
    }

    return 0;
}
