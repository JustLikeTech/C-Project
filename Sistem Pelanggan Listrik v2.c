// Sistem Pelanggan Listrik v2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer // Bentuk Data Yang Menyimpan Beberapa Tipe Data 
{
    char nama[50];
    char kode[20];
    char tanggal[15];
    float biaya;
};

/*Fungsi Tambah Data*/

void tambahData(FILE *file)
{
    FILE *tempFile = fopen("Data_Baru.txt", "a"); // Pengintegrasian Data Ke Dalam Penyimpanan 
    struct customer customer;

    fseek(file, 0, SEEK_END);

    do{ // Loop Untuk Menginputkan Macam Data Pelanggan
        while(getchar() != '\n' );

        printf("\nNama Pelanggan: ");
        scanf("%s", customer.nama);

        printf("Kode Pelanggan: ");
        scanf("%s", customer.kode);

        printf("Tanggal Pendafaran: ");
        scanf("%s", customer.tanggal);

        printf("Biaya Langganan: ");
        scanf("%f", &customer.biaya);

        fprintf(file, "%s %s %s %.2f\n", customer.nama, customer.kode, customer.tanggal, customer.biaya);
        fclose(tempFile);

        printf("\nData Pelanggan Telah Ditambahkan.\n");

        printf("Tambahkan Data Lagi? (Ketik 1: (Ya) / Ketik 2 (Tidak) ):"); // Looping Penambahan Data Pelanggan
        int tambahLagi; // Pemrosesan Penambahan Data
        scanf("%d", &tambahLagi); 

        if (tambahLagi != 1){
            break;
        }
    } while (1);

    fclose(tempFile);
}

/*End Fungsi Tambah Data*/

/*Fungsi Cari Data*/

void cariData(FILE *file)
{
    char cari[20];

    printf("\nMasukkan Nama Pelanggan/Kode Pelanggan: ");
    scanf("%19s", cari); // Batasi pembacaan input agar tidak melebihi panjang maksimum (19 karakter).

    struct customer customer;
    fseek(file, 0, SEEK_SET);

    int dataDitemukan = 0; // Untuk menandai apakah data ditemukan

    while (fscanf(file, "%s %s %s %f", customer.nama, customer.kode, customer.tanggal, &customer.biaya) != EOF)
    {
        if (strstr(customer.nama, cari) || strstr(customer.kode, cari))
        {
            dataDitemukan = 1; // Menandai bahwa data ditemukan

            printf("\nBerikut Hasil Pencarian Data:\n");
            printf("Nama: %s\nKode: %s\nTanggal: %s\nBiaya: %.2f\n", customer.nama, customer.kode, customer.tanggal, customer.biaya);
        }
    }

    if (!dataDitemukan)
    {
        printf("Data Anda Tidak Ditemukan.\n");
    }
}

/*End Fungsi Cari Data*/

/*Fungsi Hapus Data*/

void hapusData(FILE *file)
{
    char kode[20];

    printf("\nMasukkan Kode Pelanggan Yang Akan Dihapus: ");
    scanf("%s", kode);

    FILE *tempFile = fopen("Data_Baru.txt", "w");
    struct customer customer;

    fseek(file, 0, SEEK_SET);

    while (fscanf(file, "%s %s %s %f", customer.nama, customer.kode, customer.tanggal, &customer.biaya) != EOF)
    {
        if (strcmp(customer.kode, kode) != 0)
        {
            fprintf(tempFile, "%s %s %s %.2f\n", customer.nama, customer.kode, customer.tanggal, customer.biaya);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("Data_Baru.txt");
    rename("Temp_File.txt", "Data_Baru.txt");

    printf("Data Pelanggan Telah Dihapus.\n");
}

/*End Fungsi Hapus Data*/

/*Fungsi Total Biaya*/

void totalBiaya(FILE *file)
{
    char nama[50];

    printf("\nMasukkan Nama Pelanggan: ");
    scanf("%s", nama);

    struct customer customer;
    fseek(file, 0, SEEK_SET);

    while (fscanf(file, "%s %s %s %f", customer.nama, customer.kode, customer.tanggal, &customer.biaya) != EOF)
    {
        if (strstr(customer.nama, nama) != NULL)
        {
            float biayaBulanan = customer.biaya * 30;  // Perhitungan Biaya Langganan Dalam 1 Bulan =  30 Hari
            float biayaTahunan = customer.biaya * 365; // Perhitungan Biaya Langganan Dalam 1 Tahun = 365 Hari

            printf("\nTotal Biaya Untuk 1 Bulan : %.2f\n", biayaBulanan); // Output Perthitungan Biaya Langganan 1 Bulan
            printf("\nTotal Biaya Untuk 1 Tahun : %.2f\n", biayaTahunan); // Output Perhitungan Biaya Langganan 1 Tahun

            return;
        }
    }
    printf("Data Pelanggan Tidak Ditemukan.\n");
}

/*End Fungsi Total Biaya*/

/*Fungsi Bill Menu*/

void billMenu(FILE *file)
{
    int subMenu;
    int waktuLangganan;
    float totalBiaya;

    printf("\nPilih Menu Bill:\n");
    printf("1. Tanggal Pembayaran\n");
    printf("2. Biaya Langganan\n");

    printf("Masukkan Angka Pilihan:");
    scanf("%d", &subMenu);

    struct customer customer;

    printf("\nMasukkan Kode Pelanggan:"); // Pencarian Data Tanggal Langganan Dengan Bantuan Kode Pelanggan
    
    char kode[20];
    scanf("%s", kode);

    fseek(file, 0, SEEK_SET);
    int pelangganDitemukan = 0;

    while (fscanf(file, "%s %s %s %f", customer.nama, customer.kode, customer.tanggal, &customer.biaya) != EOF)
    {
        if (strcmp(customer.kode, kode) == 0)
        {
            pelangganDitemukan = 1;

            switch (subMenu)
            {
            case 1: // Pilihan Menu Estimasi Tanggal (Bulan/Tahun) Biaya Langganan (BillMenu)
                printf("\n Pilih Estimasi Tanggal Untuk Tagihan Langganan:\n");
                printf("1. Bulan\n");
                printf("2. Tahun\n");
                printf("Pilih Salah Satu Estimasi Tanggal:");
                scanf("%d", &waktuLangganan);

                int tahun, bulan;
                sscanf(customer.tanggal, "%d-%d", &tahun, &bulan);

                switch (waktuLangganan)
                {
                case 1:
                    bulan += 1;
                    if (bulan > 12)
                    {
                        bulan -= 12;
                        tahun += 1;
                    }

                    printf("Tagihan Anda Selanjutnya Setelah 1 Bulan: %04d-%02d\n", tahun, bulan);
                    break;
                case 2:
                    tahun += 1;
                    printf("Tagihan Anda Selanjutnya Setelah 1 Tahun : %04d-%02d\n", tahun, bulan);
                    break;
                default:
                    printf("Pilihan Estimasi Waktu Anda Salah");
                    break;
                }
                break;

            case 2: // Pilihan Menu Estimasi Waktu (Bulan/Tahun) Biaya Langganan (BillMenu)
                printf("\nMasukkan Estimasi Waktu Untuk Biaya Langganan:\n");
                printf("1. Bulan\n");
                printf("2. Tahun\n");
                printf("Silahkan Masukkan Pilihan Anda:");
                scanf("%d", &waktuLangganan);

                switch (waktuLangganan)
                {
                case 1: // Case Perhitungan Per Bulan
                    totalBiaya = customer.biaya * (waktuLangganan * 30);
                    printf("Biaya Langganan Untuk %d Bulan: %.2f\n", waktuLangganan, totalBiaya);
                    break;

                case 2: // Case Perhitungan Per Tahun
                    totalBiaya = customer.biaya * (waktuLangganan * 365);
                    printf("Biaya Langganan Untuk %d Tahun: %.2f\n", waktuLangganan, totalBiaya);
                    break;

                default:
                    printf("Pilihan Satuan Waktu Tidak Tepat, Silahkan Pilih Satuan Waktu Yang Tepat...");
                    break;
                }
                break;

            default:
                printf("Pilihan Sub Menu Tidak Valid.\n");
                break;
            }
            break;
        }
        
        if (!pelangganDitemukan){
            printf("Pelanggan Dengan Kode %s Ditemukan.\n", kode);
        }

    }
}
/*End Fungsi Bill Menu*/

/*Fungsi Update Data*/
void updateData(FILE *file){
    
    char kode[20];

    printf("\nMasukkan Kode Pelanggan Yang Akan DiUpdate:");
    scanf("%s", kode);

    FILE *tempfile = fopen("Temp_File.txt", "w");
    struct customer customer;

    fseek(file, 0, SEEK_SET);

    while (fscanf(file, "%s %s %s %f", customer.nama, customer.kode, customer.tanggal, &customer.biaya) != EOF){

        if(strcmp(customer.kode, kode) == 0){

            printf("\nMasukkan Nama Pelanggan Baru: ");
            scanf("%s", customer.nama);

            printf("Masukkan Kode Pelanggan Baru: ");
            scanf("%s", customer.kode);

            printf("Masukkan Tanggal Pendaftaran Baru: ");
            scanf("%s", customer.tanggal);

            printf("Masukkan Biaya Langganan Baru: ");
            scanf("%f", &customer.biaya);
        }

        fprintf(tempfile, "%s %s %s %.2f\n", customer.nama, customer.kode, customer.tanggal, customer.biaya);

    }

    fclose(file);
    fclose(tempfile);

    remove("Data_Baru.txt");
    rename("Temp_File.txt", "Data_Baru.txt");

    printf("\nData Pelanggan Telah DiUpdate.\n");
}
/*Fungsi Update Data*/

int main()
{
    int pilihan;

    FILE *file = fopen("Data_Baru.txt", "a+");

    if (file == NULL)
    {
        printf("Gagal Membuka File.\n");
        return 1;
    }

    printf("\n ================= Selamat Datang Super User PLN Manager =================\n");
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Tambah Data\n");
        printf("2. Cari Data\n");
        printf("3. Update Data\n");
        printf("4. Hapus Data\n");
        printf("5. Bill\n");
        printf("6. Total Biaya\n");
        printf("0. Keluar\n");

        printf("Pilih Menu: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            tambahData(file);
            break;
        case 2:
            cariData(file);
            break;
        case 3:
            updateData(file);
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
