#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
    char nama[50];
    char kode[20];
    char tanggal[15];
    float biaya;
};

void tambahData(FILE *file) {
    FILE *tempFile = fopen("Tambah_Data.txt", "w");
    struct customer customer;

    fseek(file, 0, SEEK_END);

    printf("Nama Pelanggan: ");
    scanf("%s", customer.nama);

    printf("Kode Pelanggan: ");
    scanf("%s", customer.kode);

    printf("Tanggal Pendafaran: ");
    scanf("%s", customer.tanggal);

    printf("Biaya Langganan: ");
    scanf("%f", &customer.biaya);

    fprintf(file, "%s %s %s %.2f\n", customer.nama, customer.kode, customer.tanggal, customer.biaya);
    fclose(tempFile);

    printf("Data Pelanggan Telah Ditambahkan.\n");
}

void cariData(FILE *file) {
    char search[20];

    printf("Masukkan Nama Pelanggan/Kode Pelanggan: ");
    scanf("%s", search);

    struct customer customer;
    fseek(file, 0, SEEK_SET);

    while (fscanf(file, "%s %s %s %f", customer.nama, customer.kode, customer.tanggal, &customer.biaya) != EOF) {
        if (strstr(customer.nama, search) || strstr(customer.kode, search)) {
            printf("Nama: %s\n Kode: %s\n Tanggal: %s\n Biaya: %.2f \n", customer.nama, customer.kode, customer.tanggal, customer.biaya);
        }
    }
}

void hapusData(FILE *file) {
    char kode[20];

    printf("Masukkan Kode Pelanggan Yang Akan Dihapus: ");
    scanf("%s", kode);

    FILE *tempFile = fopen("Tambah_Data.txt", "w");
    struct customer customer;

    fseek(file, 0, SEEK_SET);

    while (fscanf(file, "%s %s %s %f", customer.nama, customer.kode, customer.tanggal, &customer.biaya) != EOF) {
        if (strcmp(customer.kode, kode) != 0) {
            fprintf(tempFile, "%s %s %s %.2f\n", customer.nama, customer.kode, customer.tanggal, customer.biaya);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("Data_Baru.txt");
    rename("Tambah_Data.txt", "Data_Baru.txt");

    printf("Data Pelanggan Telah Dihapus.\n");
}

void totalBiaya(FILE *file) {
    char nama[50];

    printf("Masukkan Nama Pelanggan: ");
    scanf("%s", nama);

    struct customer customer;
    fseek(file, 0, SEEK_SET);

    while (fscanf(file, "%s %s %s %f", customer.nama, customer.kode, customer.tanggal, &customer.biaya) != EOF) {
        if (strstr(customer.nama, nama) != 0) {
            float totalBiaya = customer.biaya * 3;

            printf("Total Biaya Untuk 3 Hari : %.2f\n", totalBiaya);
            return;
        }
    }
    printf("Data Pelanggan Tidak Ditemukan.\n");
}

void billMenu(FILE *file) {
    int subMenu;

    printf("Pilih Menu:\n");
    printf("1. Kode Pelanggan:\n");
    printf("2. Tanggal Pembayaran\n");
    printf("3. Biaya Langganan:\n");
    scanf("%d", &subMenu);

    struct customer customer;

    fseek(file, 0, SEEK_SET);

    while (fscanf(file, "%s %s %s %f", customer.nama, customer.kode, customer.tanggal, &customer.biaya) != EOF) {
        switch (subMenu) {

        case 1:
            printf("Kode Pelanggan: %s\n", customer.kode);
            break;

        case 2:
            printf("Tanggal Pembayaran: %s\n", customer.tanggal);
            break;

        case 3:
            printf("Biaya Langganan: %.2f\n", customer.biaya);
            break;

        default:
            printf("Pilihan Sub Menu Tidak Valid.\n");
            break;
        }
    }
}

int main() {
    int pilihan;

    FILE *file = fopen("Data_Baru.txt", "a+");

    if (file == NULL) {
        printf("Gagal Membuka File.\n");
        return 1;
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Tambah Data\n");
        printf("2. Cari Data\n");
        printf("4. Hapus Data\n");
        printf("5. Bill\n");
        printf("6. Total Biaya\n");
        printf("0. Keluar\n");

        printf("Pilih Menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
        case 1:
            tambahData(file);
            break;
        case 2:
            cariData(file);
            break;
        case 4:
            hapusData(file);
            break;
        case 5:
            billMenu(file);
            break;
        case 6:
            totalBiaya(file);
            break;
        case 0:
            printf("Keluar Dari Program");
            fclose(file);
            return 0;
        default:
            break;
        }
    }

    return 0;
}
