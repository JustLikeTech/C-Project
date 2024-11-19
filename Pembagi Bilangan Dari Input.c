// Pembagi Bilangan Dari Input 

do {
        // Proses yang akan diulang
        printf("Apakah Anda Ingin Meneruskan? (Y/N): ");
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
