#include<stdio.h>
#include<string.h>

int main(){

    // JUDUL PROGRAM
    printf("\n=====================================================\n");
    printf("      PROGRAM ANALISIS BATAS KONSUMSI\n");
    printf("   Berdasarkan Takaran Saji Pada Kemasan\n");
    printf("=====================================================\n\n");

    // VARIABEL
    int jenis_produk;
    int kategori_umur;

    int batas_gula;
    int batas_natrium;
    int batas_lemakjenuh;
    int kebutuhan_energi;

    char nama_produk[100];

    float sajian_per_kemasan;
    float takaran_saji;

    int pilihan_pieces;

    float pieces_per_saji;
    float pieces_dikonsumsi;

    float bagian_kemasan;

    float minuman_dikonsumsi;

    float serving_dikonsumsi;
    float takaransaji_dikonsumsi;

    // INFORMASI GIZI
    float lemak_total;
    float lemak_jenuh;
    float protein;
    float karbohidrat_total;
    float gula_total;
    float natrium;

    // TOTAL KANDUNGAN
    float total_lemak_total;
    float total_lemak_jenuh;
    float total_protein;
    float total_karbohidrat_total;
    float total_gula_total;
    float total_natrium;

    // TOTAL ENERGI
    float total_kalori;
    float persen_energi;

    // PERSENTASE AKG
    float persen_gula;
    float persen_natrium;
    float persen_lemak_jenuh;

    char status[20];
    char analisis_konsumsi[1000];
    char saran[3000];

    // LOOP PROGRAM
    do{

        // MENU
        
        printf("\n=====================================\n");
        printf("> Pilihan Jenis Produk\n");
        printf("1. Makanan\n");
        printf("2. Minuman\n");
        printf("3. Exit\n");
        printf("=====================================\n");

        printf("\nMasukkan jenis produk yang diinginkan: ");
        scanf("%d", &jenis_produk);

        // EXIT
        if(jenis_produk == 3){
            printf("\nTerima kasih telah menggunakan program kami!\n");
            break;
        }

        // VALIDASI
        if(jenis_produk < 1 || jenis_produk > 3){
            printf("\nInput jenis produk salah!\n\n");
            continue;
        }

        // INPUT KATEGORI UMUR
        do{
            
            printf("\n> Pilih Kategori Umur\n");
            printf("1. Anak-anak (5-12 tahun)\n");
            printf("2. Remaja (13-17 tahun)\n");
            printf("3. Dewasa (18+ tahun)\n");

            printf("\nMasukkan kategori umur Anda: ");
            scanf("%d", &kategori_umur);

            if(kategori_umur < 1 || kategori_umur > 3){
                printf("\nInput kategori umur salah!\n");
            }

        } while(kategori_umur < 1 || kategori_umur > 3);

        // MENAMPILKAN INFORMASI BATAS KONSUMSI
        if(kategori_umur == 1){

            printf("\n=====================================\n");
            printf("Kategori: Anak-Anak\n");
            printf("Gula     : 25 - 40 gram\n");
            printf("Natrium  : 1000 - 1500 mg\n");
            printf("Lemak    : 35 - 50 gram\n");
            printf("=====================================\n");

        }

        else if(kategori_umur == 2){

            printf("\n=====================================\n");
            printf("Kategori: Remaja\n");
            printf("Gula     : 40 - 50 gram\n");
            printf("Natrium  : 1500 - 2000 mg\n");
            printf("Lemak    : 50 - 67 gram\n");
            printf("=====================================\n");

        }

        else{

            printf("\n=====================================\n");
            printf("Kategori: Dewasa\n");
            printf("Gula     : Maksimal 50 gram\n");
            printf("Natrium  : Maksimal 2000 mg\n");
            printf("Lemak    : Maksimal 67 gram\n");
            printf("=====================================\n");

        }

        // MENENTUKAN BATAS KONSUMSI
        if(kategori_umur == 1){

            batas_gula = 25;
            batas_natrium = 1200;
            batas_lemakjenuh = 10;
            kebutuhan_energi = 1400;

        }

        else if(kategori_umur == 2){

            batas_gula = 40;
            batas_natrium = 1500;
            batas_lemakjenuh = 15;
            kebutuhan_energi = 2000;

        }

        else{

            batas_gula = 50;
            batas_natrium = 2000;
            batas_lemakjenuh = 20;
            kebutuhan_energi = 2150;

        }

        // INPUT IDENTITAS PRODUK
        printf("\nMasukkan nama produk: ");
        scanf(" %[^\n]", nama_produk);

        printf("Masukkan jumlah sajian per kemasan: ");
        scanf("%f", &sajian_per_kemasan);

        // MAKANAN
        if(jenis_produk == 1){

            printf("\nMasukkan takaran saji makanan (gram): ");
            scanf("%f", &takaran_saji);

            printf("\nApakah terdapat jumlah pieces?\n");
            printf("1. Ya\n");
            printf("2. Tidak\n");

            printf("\n> ");
            scanf("%d", &pilihan_pieces);

            // ADA PIECES
            if(pilihan_pieces == 1){

                printf("\nMasukkan jumlah pieces per saji: ");
                scanf("%f", &pieces_per_saji);

                printf("Masukkan jumlah pieces yang dikonsumsi: ");
                scanf("%f", &pieces_dikonsumsi);

                // HITUNG SERVING
                serving_dikonsumsi =
                pieces_dikonsumsi / pieces_per_saji;

                // HITUNG JUMLAH DIKONSUMSI
                takaransaji_dikonsumsi =
                serving_dikonsumsi * takaran_saji;

            }

            // TIDAK ADA PIECES
            else{

                printf("\nBerapa bagian kemasan yang dikonsumsi?\n");
                printf("1    = seluruh kemasan\n");
                printf("0.5  = setengah kemasan\n");
                printf("0.25 = seperempat kemasan\n");

                printf("\n> ");
                scanf("%f", &bagian_kemasan);

                // HITUNG SERVING
                serving_dikonsumsi =
                sajian_per_kemasan * bagian_kemasan;

                // HITUNG JUMLAH DIKONSUMSI
                takaransaji_dikonsumsi =
                serving_dikonsumsi * takaran_saji;

            }

        }

        // MINUMAN
        else if(jenis_produk == 2){

            printf("\nMasukkan takaran saji minuman (mL): ");
            scanf("%f", &takaran_saji);

            printf("Masukkan jumlah minuman yang dikonsumsi (mL): ");
            scanf("%f", &minuman_dikonsumsi);

            // HITUNG SERVING
            serving_dikonsumsi =
            minuman_dikonsumsi / takaran_saji;

            // JUMLAH MINUMAN
            takaransaji_dikonsumsi =
            minuman_dikonsumsi;

        }

        printf("\n---\n");

        // INPUT INFORMASI GIZI
        printf("\nMasukkan Lemak Total per sajian (gram): ");
        scanf("%f", &lemak_total);

        printf("Masukkan Lemak Jenuh per sajian (gram): ");
        scanf("%f", &lemak_jenuh);

        printf("Masukkan Protein per sajian (gram): ");
        scanf("%f", &protein);

        printf("Masukkan Karbohidrat Total per sajian (gram): ");
        scanf("%f", &karbohidrat_total);

        printf("Masukkan Gula Total per sajian (gram): ");
        scanf("%f", &gula_total);

        printf("Masukkan Natrium per sajian (mg): ");
        scanf("%f", &natrium);

        printf("\n---\n");

        // PERHITUNGAN TOTAL KANDUNGAN
        total_lemak_total =
        lemak_total * serving_dikonsumsi;

        total_lemak_jenuh =
        lemak_jenuh * serving_dikonsumsi;

        total_protein =
        protein * serving_dikonsumsi;

        total_karbohidrat_total =
        karbohidrat_total * serving_dikonsumsi;

        total_gula_total =
        gula_total * serving_dikonsumsi;

        total_natrium =
        natrium * serving_dikonsumsi;

        // TOTAL KALORI
        total_kalori =
        (total_karbohidrat_total * 4) +
        (total_protein * 4) +
        (total_lemak_total * 9);

        // PERSENTASE ENERGI
        persen_energi =
        (total_kalori / kebutuhan_energi) * 100;

        // PERSENTASE AKG
        persen_gula =
        (total_gula_total / batas_gula) * 100;

        persen_natrium =
        (total_natrium / batas_natrium) * 100;

        persen_lemak_jenuh =
        (total_lemak_jenuh / batas_lemakjenuh) * 100;

        // MENENTUKAN STATUS
        strcpy(status, "AMAN");

        if(total_gula_total > batas_gula){
            strcpy(status, "BAHAYA");
        }

        else if(total_gula_total >= batas_gula * 0.7){
            strcpy(status, "WASPADA");
        }

        if(total_natrium > batas_natrium){
            strcpy(status, "BAHAYA");
        }

        else if(
            total_natrium >= batas_natrium * 0.7 &&
            strcmp(status, "BAHAYA") != 0){

            strcpy(status, "WASPADA");
        }

        if(total_lemak_jenuh > batas_lemakjenuh){
            strcpy(status, "BAHAYA");
        }

        else if(
            total_lemak_jenuh >= batas_lemakjenuh * 0.7 &&
            strcmp(status, "BAHAYA") != 0){

            strcpy(status, "WASPADA");
        }
        // MENENTUKAN SARAN
    if (strcmp(status, "AMAN") == 0) {

        if (jenis_produk == 1){

         strcpy(saran,
            "Konsumsi makanan masih dalam batas aman berdasarkan jumlah gula, natrium, dan lemak jenuh yang dikonsumsi.");

    }

    else if (jenis_produk == 2){

        strcpy(saran,
        "Konsumsi minuman masih dalam batas aman berdasarkan jumlah gula, natrium, dan lemak jenuh yang dikonsumsi.");

    }

}

else if (strcmp(status, "WASPADA") == 0) {

    if (jenis_produk == 1){

        strcpy(saran,
        "Jumlah konsumsi makanan mulai mendekati batas harian yang direkomendasikan.");

    }

    else if (jenis_produk == 2){

        strcpy(saran,
        "Jumlah konsumsi minuman mulai mendekati batas harian yang direkomendasikan. "
        "Tetap pertahankan pola makan sehat dan seimbang dengan membatasi konsumsi makanan tinggi gula, garam, dan lemak jenuh secara berlebihan. "
        "WHO (World Health Organization) merekomendasikan untuk memperbanyak konsumsi buah, sayur, dan makanan bergizi seimbang untuk menjaga kesehatan tubuh dalam jangka panjang.\n"
        "> Baca selengkapnya: https://www.who.int/news-room/fact-sheets/detail/healthy-diet");

    }

}

else if (strcmp(status, "BAHAYA") == 0) {

    if (jenis_produk == 1){

        strcpy(saran,
        "Jumlah konsumsi makanan telah melebihi batas harian yang direkomendasikan. "
        "Disarankan untuk mengurangi frekuensi konsumsi makanan tinggi gula, natrium, dan lemak jenuh serta menyeimbangkannya dengan makanan bergizi lainnya. "
        "Membiasakan membaca informasi nilai gizi pada kemasan juga dapat membantu mengontrol pola konsumsi harian agar tetap sehat.\n"
        "> Baca selengkapnya: https://www.who.int/news-room/fact-sheets/detail/healthy-diet");

    }

    else if (jenis_produk == 2){

        strcpy(saran,
        "Jumlah konsumsi minuman telah melebihi batas harian yang direkomendasikan. "
        "Kurangi konsumsi minuman tinggi gula tambahan atau sodium dan perbanyak konsumsi air putih. "
        "American Heart Association (AHA) menjelaskan bahwa konsumsi gula tambahan berlebihan dapat meningkatkan risiko obesitas, diabetes, dan gangguan kesehatan lainnya.\n"
        "> Baca selengkapnya: https://www.heart.org/en/healthy-living");

    }

}
        // ANALISIS KONSUMSI
        if(serving_dikonsumsi > sajian_per_kemasan){

            strcpy(
            analisis_konsumsi,
            "Jumlah konsumsi melebihi sajian per kemasan."
            );

        }

        else if(serving_dikonsumsi == sajian_per_kemasan){

            strcpy(
            analisis_konsumsi,
            "Jumlah konsumsi sesuai sajian per kemasan."
            );

        }

        else{

            strcpy(
            analisis_konsumsi,
            "Jumlah konsumsi masih di bawah sajian per kemasan."
            );

        }

        // OUTPUT PROGRAM
        printf("\n=====================================================\n");
        printf("              HASIL ANALISIS KONSUMSI\n");
        printf("=====================================================\n\n");

        printf("Nama produk                    : %s\n", nama_produk);
        printf("Kategori umur                  : %d\n", kategori_umur);

        if(jenis_produk == 1){

            printf("Jumlah makanan dikonsumsi      : %.2f gram\n",
            takaransaji_dikonsumsi);

        }

        else{

            printf("Jumlah minuman dikonsumsi      : %.2f mL\n",
            takaransaji_dikonsumsi);

        }

        printf("Jumlah sajian dikonsumsi       : %.2f sajian\n",
        serving_dikonsumsi);

        printf("\nTOTAL KANDUNGAN GIZI\n");

        printf("Lemak total                    : %.2f gram\n",
        total_lemak_total);

        printf("Lemak jenuh                    : %.2f gram\n",
        total_lemak_jenuh);

        printf("Protein                        : %.2f gram\n",
        total_protein);

        printf("Karbohidrat total              : %.2f gram\n",
        total_karbohidrat_total);

        printf("Gula total                     : %.2f gram\n",
        total_gula_total);

        printf("Natrium                        : %.2f mg\n",
        total_natrium);

        printf("\nPERSENTASE BATAS HARIAN\n");

        printf("Persentase gula                : %.2f%%\n",
        persen_gula);

        printf("Persentase natrium             : %.2f%%\n",
        persen_natrium);

        printf("Persentase lemak jenuh         : %.2f%%\n",
        persen_lemak_jenuh);

        printf("\nTOTAL ENERGI\n");

        printf("Total energi dikonsumsi        : %.2f kkal\n",
        total_kalori);

        printf("Persentase kebutuhan energi    : %.2f%%\n",
        persen_energi);

        printf("\nAnalisis konsumsi:\n%s\n",
        analisis_konsumsi);

        printf("\nStatus konsumsi:\n%s\n",
        status);

        printf("\nSaran:\n%s\n",
        saran);

        printf("\n=====================================================\n\n");

    } while(jenis_produk != 3);

    return 0;
}
