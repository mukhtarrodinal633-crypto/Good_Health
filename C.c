#include <stdio.h>
#include <string.h>

void Identitas_Produk();

char Nama_Produk[100];
int Jumlah_Persajian;

int main() {
    int pilihanProduk, pilihanUmur;
    int gula, natrium, lemakJenuh;

    printf("\n==>> Tampilkan Menu Produk <<==\n");
    printf("1. Makanan\n");
    printf("2. Minuman\n");
    printf("3. EXIT\n");
    printf("Pilih menu: ");
    scanf("%d", &pilihanProduk);

    if (pilihanProduk == 1 || pilihanProduk == 2) {

        printf("\n==>> Tampilkan Menu Kategori Umur <<==\n");
        printf("1. Anak-Anak 8-12 Tahun\n");
        printf("2. Remaja 13-17 Tahun\n");
        printf("3. Dewasa 18+ Tahun\n");
        printf("Pilih kategori umur: ");
        scanf("%d", &pilihanUmur);

        if (pilihanUmur == 1) {
            gula = 25;
            natrium = 1200;
            lemakJenuh = 10;
            printf("\nKategori: Anak-Anak\n");
        } else if (pilihanUmur == 2) {
            gula = 40;
            natrium = 1500;
            lemakJenuh = 15;
            printf("\nKategori: Remaja\n");
        } else if (pilihanUmur == 3) {
            gula = 50;
            natrium = 2000;
            lemakJenuh = 20;
            printf("\nKategori: Dewasa\n");
        } else {
            printf("Pilihan tidak valid!\n");
            return 0;
        }
        printf("\n==>> Informasi Batas Gizi Produk untuk %s <<==\n", (pilihanUmur == 1) ? "Anak-Anak" : (pilihanUmur == 2) ? "Remaja" : "Dewasa");
        printf("Batas Gula         : %d gram\n", gula);
        printf("Batas Natrium      : %d mg\n", natrium);
        printf("Batas Lemak Jenuh  : %d gram\n", lemakJenuh);

        Identitas_Produk();
    } else if (pilihanProduk == 3) {
        printf("Terima kasih telah menggunakan layanan kami!\n");
    } else {
        printf("Pilihan tidak valid!\n");
    }
    return 0;
}
void Identitas_Produk() {
    printf("\n==>> Identitas Produk <<==\n");
    printf("Nama Produk: ");
    scanf(" %[^\n]", Nama_Produk);
    printf("Jumlah Persajian: ");
    scanf("%d", &Jumlah_Persajian);
    printf("\nNama Produk       : %s\n", Nama_Produk);
    printf("Jumlah Persajian  : %d\n", Jumlah_Persajian);

    printf("\n ==>> Nilai Gizi per Persajian <<==\n");
}
