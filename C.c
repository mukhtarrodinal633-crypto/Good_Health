#include <stdio.h>
#include <string.h>

void Identitas_Produk();

char Nama_Produk[100];
int Jumlah_Persajian;

int main() {

    int pilihanProduk, pilihanUmur;
    int gula, natrium, lemak;

    printf("\n==>> Tampilkan Menu Produk <<==\n");
    printf("1. Makanan\n");
    printf("2. Minuman\n");
    printf("3. EXIT\n");
    printf("Pilih menu: ");
    scanf("%d", &pilihanProduk);

    if (pilihanProduk == 1 || pilihanProduk == 2) {
        printf("\n==>> Pilih Kategori Umur <<==\n");
        printf("1. Anak-Anak 8-12 Tahun\n");
        printf("2. Remaja 13-17 Tahun\n");
        printf("3. Dewasa 18+ Tahun\n");
        printf("Pilih kategori umur: ");
        scanf("%d", &pilihanUmur);

        if (pilihanUmur == 1) {
            int gulaMin = 25, gulaMax = 40;
            int natriumMin = 1000, natriumMax = 1500;
            int lemakMin = 35, lemakMax = 50;

            gula = gulaMax;
            natrium = natriumMax;
            lemak = lemakMax;

            printf("\nKategori: Anak-Anak\n");
            printf("Rentang Batas Gizi Harian:\n");
            printf("Gula     : %d - %d gram\n", gulaMin, gulaMax);
            printf("Natrium  : %d - %d mg\n", natriumMin, natriumMax);
            printf("Lemak    : %d - %d gram\n", lemakMin, lemakMax);

        } else if (pilihanUmur == 2) {
            int gulaMin = 40, gulaMax = 50;
            int natriumMin = 1500, natriumMax = 2000;
            int lemakMin = 50, lemakMax = 67;

            gula = gulaMax;
            natrium = natriumMax;
            lemak = lemakMax;

            printf("\nKategori: Remaja\n");
            printf("Rentang Batas Gizi Harian:\n");
            printf("Gula     : %d - %d gram\n", gulaMin, gulaMax);
            printf("Natrium  : %d - %d mg\n", natriumMin, natriumMax);
            printf("Lemak    : %d - %d gram\n", lemakMin, lemakMax);

        } else if (pilihanUmur == 3) {
            int gulaMin = 0, gulaMax = 50;
            int natriumMin = 0, natriumMax = 2000;
            int lemakMin = 0, lemakMax = 67;

            gula = gulaMax;
            natrium = natriumMax;
            lemak = lemakMax;

            printf("\nKategori: Dewasa\n");
            printf("Rentang Batas Gizi Harian:\n");
            printf("Gula     : %d - %d gram\n", gulaMin, gulaMax);
            printf("Natrium  : %d - %d mg\n", natriumMin, natriumMax);
            printf("Lemak    : %d - %d gram\n", lemakMin, lemakMax);

        } else {
            printf("Pilihan tidak valid!\n");
            return 0;
        }
        printf("\n==>> Informasi Batas Gizi Produk <<==\n");
        printf("Batas Maksimum Gula     : %d gram\n", gula);
        printf("Batas Maksimum Natrium  : %d mg\n", natrium);
        printf("Batas Maksimum Lemak    : %d gram\n", lemak);

        Identitas_Produk();

    } else if (pilihanProduk == 3) {
        printf("Terima kasih telah menggunakan layanan kami!\n");
    } else {

        printf("Pilihan tidak valid!\n");
    }
    return 0;
}

void Identitas_Produk() {
    printf("\n==>> Identitas Dan Jumlah Persajian Produk <<==\n");
    printf("Nama Produk: ");
    scanf(" %[^\n]", Nama_Produk);

    printf("Jumlah Persajian: ");
    scanf("%d", &Jumlah_Persajian);

    printf("\nNama Produk       : %s\n", Nama_Produk);
    printf("Jumlah Persajian  : %d\n", Jumlah_Persajian);

    printf("\n==>> Nilai Gizi per Persajian <<==\n");
}
