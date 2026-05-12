#include <stdio.h>
#include <string.h>

float hitungServing();

void Nilai_Gizi();
int Gula_Total;
int Natrium_Total;
int Karbo_Total;
int Lemak_Total;
int Lemak_Jenuh;
int Protein_Total;

void Identitas_Produk();
char Nama_Produk[100];
int Jumlah_Persajian;

int main() {
    int pilihanProduk, pilihanUmur;
    int gula, natrium, lemak;
    char pilihanPieces;
    float Serving_Dikonsumsi;

    printf("\n=====================================\n");
    printf("==>> Tampilkan Menu Produk <<==\n");
    printf("1. Makanan\n");
    printf("2. Minuman\n");
    printf("3. EXIT\n");
    printf("Pilih menu: ");
    if(scanf("%d", &pilihanProduk) != 1) {
        printf("Input harus berupa angka!\n");
        return 0;
    }
    printf("=====================================\n");

    if (pilihanProduk == 1 || pilihanProduk == 2) {
        printf("\n=====================================\n");
        printf("==>> Pilih Kategori Umur <<==\n");
        printf("1. Anak-Anak 8-12 Tahun\n");
        printf("2. Remaja 13-17 Tahun\n");
        printf("3. Dewasa 18+ Tahun\n");
        printf("Pilih kategori umur: ");
        if(scanf("%d", &pilihanUmur) != 1) {
            printf("Input harus berupa angka!\n");
            return 0;
        }
        printf("=====================================\n");

        if (pilihanUmur == 1) {
            gula = 40;
            natrium = 1500;
            lemak = 50;

            printf("\n=====================================\n");
            printf("Kategori: Anak-Anak\n");
            printf("Gula     : 25 - 40 gram\n");
            printf("Natrium  : 1000 - 1500 mg\n");
            printf("Lemak    : 35 - 50 gram\n");
            printf("=====================================\n");

        } else if (pilihanUmur == 2) {
            gula = 50;
            natrium = 2000;
            lemak = 67;

            printf("\n=====================================\n");
            printf("Kategori: Remaja\n");
            printf("Gula     : 40 - 50 gram\n");
            printf("Natrium  : 1500 - 2000 mg\n");
            printf("Lemak    : 50 - 67 gram\n");
            printf("=====================================\n");

        } else if (pilihanUmur == 3) {
            gula = 50;
            natrium = 2000;
            lemak = 67;

            printf("\n=====================================\n");
            printf("Kategori: Dewasa\n");
            printf("Gula     : Maksimal 50 gram\n");
            printf("Natrium  : Maksimal 2000 mg\n");
            printf("Lemak    : Maksimal 67 gram\n");
            printf("=====================================\n");

        } else {
            printf("Pilihan tidak valid!\n");
            return 0;
        }

        printf("\n=====================================\n");
        printf("==>> Informasi Batas Gizi Produk <<==\n");
        printf("Batas Maksimum Gula     : %d gram\n", gula);
        printf("Batas Maksimum Natrium  : %d mg\n", natrium);
        printf("Batas Maksimum Lemak    : %d gram\n", lemak);
        printf("=====================================\n");

        Identitas_Produk();
        Nilai_Gizi();

        printf("\n=====================================\n");
        printf("==>> Informasi Konsumsi <<==\n");
        if(pilihanProduk == 1) {
            printf("Apakah sajian memiliki jumlah pieces? (y/n): ");
            scanf(" %c", &pilihanPieces);
            printf("=====================================\n");

            if(pilihanPieces == 'y' || pilihanPieces == 'Y') {
                Serving_Dikonsumsi = hitungServing();

            } else if(pilihanPieces == 'n' || pilihanPieces == 'N') {
                printf("Jumlah Serving yang Dikonsumsi: ");

                if(scanf("%f", &Serving_Dikonsumsi) != 1) {
                    printf("Input harus berupa angka!\n");
                    return 0;
                }
            } else {
                printf("Input harus y atau n!\n");
                return 0;
            }
        } else {
            printf("Jumlah Serving yang Diminum: ");
            if(scanf("%f", &Serving_Dikonsumsi) != 1) {
                printf("Input harus berupa angka!\n");
                return 0;
            }
        }
        if(Serving_Dikonsumsi > Jumlah_Persajian) {
            printf("\nJumlah konsumsi melebihi total sajian dalam kemasan!\n");
        } else {

            float Total_Gula = Gula_Total * Serving_Dikonsumsi;
            float Total_Natrium = Natrium_Total * Serving_Dikonsumsi;
            float Total_Lemak = Lemak_Total * Serving_Dikonsumsi;

            printf("\n=====================================\n");
            printf("==>> Total Gizi yang Dikonsumsi <<==\n");
            printf("Total Gula      : %.2f gram\n", Total_Gula);
            printf("Total Natrium   : %.2f mg\n", Total_Natrium);
            printf("Total Lemak     : %.2f gram\n", Total_Lemak);
            printf("=====================================\n");

            printf("\n=====================================\n");
            printf("==>> Status Konsumsi <<==\n");
            float persenGula = (Total_Gula / gula) * 100;
            float persenNatrium = (Total_Natrium / natrium) * 100;
            float persenLemak = (Total_Lemak / lemak) * 100;

            printf("\n==> GULA <==\n");
            if(persenGula <= 70) {
                printf("Status : AMAN\n");
                printf("Saran  : Konsumsi gula masih dalam batas aman.\n");
                printf("Ikuti Laman Ini untuk Hidup Lebih Sehat: https://www.who.int/news-room/fact-sheets/detail/healthy-diet\n");
            } else if(persenGula <= 100) {
                printf("Status : WASPADA\n");
                printf("Saran  : Kurangi makanan/minuman manis hari ini.\n");
                printf("Ikuti Laman Ini untuk Hidup Lebih Sehat: https://www.who.int/news-room/fact-sheets/detail/healthy-diet\n");
            } else {
                printf("Status : BAHAYA\n");
                printf("Saran  : Konsumsi gula berlebihan, perbanyak air putih dan hindari makanan manis lainnya.\n");
                printf("Ikuti Laman Ini untuk Hidup Lebih Sehat: https://www.heart.org/en/healthy-living\n");
            }
            printf("\n==> NATRIUM <==\n");
            if(persenNatrium <= 70) {
                printf("Status : AMAN\n");
                printf("Saran  : Kadar natrium masih aman untuk dikonsumsi.\n");
                printf("Ikuti Laman Ini untuk Hidup Lebih Sehat:  https://www.who.int/news-room/fact-sheets/detail/healthy-diet\n");
            } else if(persenNatrium <= 100) {
                printf("Status : WASPADA\n");
                printf("Saran  : Kurangi makanan asin atau instan.\n");
                printf("Ikuti Laman Ini untuk Hidup Lebih Sehat: https://www.who.int/news-room/fact-sheets/detail/healthy-diet\n");
            } else {
                printf("Status : BAHAYA\n");
                printf("Saran  : Natrium terlalu tinggi, hindari makanan tinggi garam.\n");
                printf("Ikuti Laman Ini untuk Hidup Lebih Sehat: https://www.heart.org/en/healthy-living\n");
            }
            printf("\n==> LEMAK <==\n");
            if(persenLemak <= 70) {
                printf("Status : AMAN\n");
                printf("Saran  : Lemak masih dalam batas normal.\n");
                printf("Ikuti Laman Ini untuk Hidup Lebih Sehat: https://www.who.int/news-room/fact-sheets/detail/healthy-diet\n");
            } else if(persenLemak <= 100) {
                printf("Status : WASPADA\n");
                printf("Saran  : Kurangi makanan berminyak dan gorengan.\n");
                printf("Ikuti Laman Ini untuk Hidup Lebih Sehat: https://www.who.int/news-room/fact-sheets/detail/healthy-diet\n");
            } else {
                printf("Status : BAHAYA\n");
                printf("Saran  : Lemak berlebihan, perbanyak aktivitas fisik dan konsumsi makanan sehat.\n");
                printf("Ikuti Laman Ini untuk Hidup Lebih Sehat: https://www.heart.org/en/healthy-living\n");
            }
            printf("=====================================\n");
        }
    } else if (pilihanProduk == 3) {
        printf("Terima kasih telah menggunakan layanan kami!\n");
    } else {
        printf("Pilihan tidak valid!\n");
    }
    return 0;
}
void Identitas_Produk() {
    printf("\n=====================================\n");
    printf("==>> Identitas Dan Jumlah Persajian Produk <<==\n");
    printf("Nama Produk: ");
    scanf(" %[^\n]", Nama_Produk);

    printf("Jumlah Persajian: ");

    if(scanf("%d", &Jumlah_Persajian) != 1) {
        printf("Input harus berupa angka!\n");
        return;
    }
    printf("\nNama Produk       : %s\n", Nama_Produk);
    printf("Jumlah Persajian  : %d\n", Jumlah_Persajian);
    printf("=====================================\n");
}
void Nilai_Gizi() {
    printf("\n=====================================\n");
    printf("==>> Nilai Gizi per Persajian <<==\n");
    printf("Gula Total (gram): ");
    scanf("%d", &Gula_Total);

    printf("Natrium (mg): ");
    scanf("%d", &Natrium_Total);

    printf("Karbohidrat (gram): ");
    scanf("%d", &Karbo_Total);

    printf("Lemak Total (gram): ");
    scanf("%d", &Lemak_Total);

    printf("Lemak Jenuh (gram): ");
    scanf("%d", &Lemak_Jenuh);

    printf("Protein (gram): ");
    scanf("%d", &Protein_Total);
    printf("=====================================\n");

    printf("\n=====================================\n");
    printf("==>> Informasi Nilai Gizi <<==\n");
    printf("Gula Total      : %d gram\n", Gula_Total);
    printf("Natrium         : %d mg\n", Natrium_Total);
    printf("Karbohidrat     : %d gram\n", Karbo_Total);
    printf("Lemak Total     : %d gram\n", Lemak_Total);
    printf("Lemak Jenuh     : %d gram\n", Lemak_Jenuh);
    printf("Protein         : %d gram\n", Protein_Total);
    printf("=====================================\n");
}
float hitungServing() {
    float Pieces_Dikonsumsi;
    float Pieces_Persajian;
    float Serving_Dikonsumsi;

    printf("\n=====================================\n");
    printf("Jumlah Pieces Per Sajian: ");

    if(scanf("%f", &Pieces_Persajian) != 1) {
        printf("Input harus berupa angka!\n");
        return 0;
    }
    printf("Jumlah Pieces yang Dikonsumsi: ");

    if(scanf("%f", &Pieces_Dikonsumsi) != 1) {
        printf("Input harus berupa angka!\n");
        return 0;
    }
    printf("=====================================\n");

    Serving_Dikonsumsi = Pieces_Dikonsumsi / Pieces_Persajian;

    return Serving_Dikonsumsi;
}
