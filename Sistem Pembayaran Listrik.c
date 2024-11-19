// Sistem Pembayaran Listrik

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pelanggan
{
    char nama[50];
    int id;
    char tgl[30];
    float pemakaian;
    float tagihan;
};

struct bill
{
    int id;
    char tgl[30];
    int biaya;
    float pemakaian;
    float tagihan;
};

void tambah_pelanggan(struct pelanggan *data_pelanggan, int *jumlah_pelanggan)
{
    printf("Masukkan nama pelanggan: ");
    scanf("%s", &data_pelanggan[*jumlah_pelanggan].nama);
    printf("Masukkan ID pelanggan: ");
    scanf("%d", &data_pelanggan[*jumlah_pelanggan].id);
    printf("Masukkan tanggal: ");
    scanf(" %s", &data_pelanggan[*jumlah_pelanggan].tgl);
    printf("Masukkan pemakaian listrik : ");
    scanf("%f", &data_pelanggan[*jumlah_pelanggan].pemakaian);

    // Calculate the bill based on usage (adjust as needed)
    data_pelanggan[*jumlah_pelanggan].tagihan = 1400 * data_pelanggan[*jumlah_pelanggan].pemakaian;
    printf("Pelanggan ditambahkan dengan sukses!\n");
    (*jumlah_pelanggan)++;
}

// Function to search for a customer by ID
void cari_pelanggan(struct pelanggan *data_pelanggan, int jumlah_pelanggan)
{
    int idCari;
    printf("Masukkan ID pelanggan: ");
    scanf("%d", &idCari);
    for (int i = 0; i < jumlah_pelanggan; i++)
    {
        if (data_pelanggan[i].id == idCari)
        {
            printf("Nama pelanggan: %s\n", data_pelanggan[i].nama);
            printf("ID pelanggan: %d\n", data_pelanggan[i].id);
            printf("Tanggal: %s\n", data_pelanggan[i].tgl);
            printf("Pemakaian:%.2f\n", data_pelanggan[i].pemakaian);
            return;
        }
    }
    printf("Pelanggan dengan ID %d tidak ditemukan.\n", idCari);
}

// Function to update customer data by ID
void update_pelanggan(struct pelanggan *data_pelanggan, int jumlah_pelanggan)
{
    int idPerbarui;
    printf("Masukkan ID pelanggan yang ingin diperbarui : ");
    scanf("%d", &idPerbarui);

    for (int i = 0; i < jumlah_pelanggan; i++)
    {
        if (data_pelanggan[i].id == idPerbarui)
        {
            printf("Masukkan nama pelanggan: ");
            scanf("%s", data_pelanggan[i].nama);
            printf("Masukkan tanggal: ");
            scanf("%s", data_pelanggan[i].tgl);
            printf("Masukkan pemakaian listrik: ");
            scanf("%f", &data_pelanggan[i].pemakaian);

            // Recalculate the bill based on the updated usage (adjust as needed)
            data_pelanggan[i].tagihan = 1400 * data_pelanggan[i].pemakaian;
            printf("Data pelanggan telah diperbarui !\n");
            return;
        }
    }
    printf("Pelanggan dengan ID %d tidak ditemukan.\n", idPerbarui);
}

// Function to delete a customer by ID
void hapus_pelanggan(struct pelanggan *data_pelanggan, int *jumlah_pelanggan)
{
    int idHapus;
    printf("Masukkan ID pelanggan yang ingin dihapus: ");
    scanf("%d", &idHapus);
    for (int i = 0; i < *jumlah_pelanggan; i++)
    {
        if (data_pelanggan[i].id == idHapus)
        {
            for (int j = i; j < *jumlah_pelanggan - 1; j++)
            {
                data_pelanggan[j] = data_pelanggan[j + 1];
            }

            printf("Pelanggan dengan ID %d telah dihapus.\n", idHapus);
            (*jumlah_pelanggan)--;
            return;
        }
    }
    printf("Pelanggan dengan ID %d tidak ditemukan.\n", idHapus);
}

void rekap(struct pelanggan *data_pelanggan, int jumlah_pelanggan)
{
    int total;
    for (int i = 0; i < jumlah_pelanggan; i++)
    {
        total += data_pelanggan[i].tagihan;
        printf("Nama pelanggan :\n", data_pelanggan[i].nama);
        printf(" ID pelanggan :\n", data_pelanggan[i].id);
        printf("Tanggal :\n", data_pelanggan[i].tgl);
        printf(" Total pemakaian (Kwh) :\n", data_pelanggan[i].pemakaian);
        printf("Total tagihan bulanan: %d\n", total);
    }
    return;
}

// Function to save customer data to a file
void simpanDataKeFile(struct pelanggan *data_pelanggan, int jumlah)
{
    FILE *file = fopen("data.txt", "w");
    if (file == NULL)
    {
        printf("Error membuka file untuk penulisan.\n");
        exit(1);
    }
    for (int i = 0; i < jumlah; i++)
    {
        fprintf(file, "%s %d %.2f %.2f\n", data_pelanggan[i].nama, data_pelanggan[i].id, data_pelanggan[i].pemakaian, data_pelanggan[i].tagihan);
    }

    fclose(file); // Close the file after writing
}

// Function to load customer data from a file
int muatDataDariFile(struct pelanggan *data_pelanggan)
{
    FILE *file = fopen("data.txt", "r");
    if (file == NULL)
    {
        printf("Tidak ada file data yang ditemukan atau tidak dapat dibaca.\n");
        return 0;
    }

    int jumlah = 0;
    while (fscanf(file, "%s %d %f %f", data_pelanggan[jumlah].nama, &data_pelanggan[jumlah].id, &data_pelanggan[jumlah].pemakaian, &data_pelanggan[jumlah].tagihan) == 4)
    {
        jumlah++;
    }

    fclose(file);
    return jumlah;
}

int main()
{
    struct pelanggan data_pelanggan[100]; // Maximum of 100 customers
    struct bill data_bill[100];
    int jumlah_bill;
    int jumlah_pelanggan; // Number of customers

    // Load existing data from the file
    jumlah_pelanggan = muatDataDariFile(data_pelanggan);
    int pilihan;
    do
    {
        printf("\n");
        printf("Sistem Pembayaran Listrik\n");
        printf("Menu:\n");
        printf("1. Tambah pelanggan\n");
        printf("2. Cari pelanggan\n");
        printf("3. Update pelanggan\n");
        printf("4. Hapus pelanggan\n");
        printf("5. Rekap\n");
        printf("6. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        switch (pilihan)
        {
        case 1:
            tambah_pelanggan(data_pelanggan, &jumlah_pelanggan);
            break;
        case 2:
            cari_pelanggan(data_pelanggan, jumlah_pelanggan);
            break;
        case 3:
            update_pelanggan(data_pelanggan, &jumlah_pelanggan);
            break;
        case 4:
            hapus_pelanggan(data_pelanggan, &jumlah_pelanggan);
            break;
        case 5:
            rekap(data_pelanggan, jumlah_pelanggan);
            break;
        case 6:
            printf("Program berakhir.\n");
            simpanDataKeFile(data_pelanggan, jumlah_pelanggan);
            break;
        default:
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 0);
    return 0;
}