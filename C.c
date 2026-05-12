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
    int gula, natrium, lemakJenuh;
    int pilihanPieces;
    float Serving_Dikonsumsi;

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
        Nilai_Gizi();
        printf("\n==>> Informasi Konsumsi <<==\n");
        if(pilihanProduk == 1) {
        	printf("Apakah sajian memiliki jumlah pieces?\n");
        	printf("1. Ya\n");
        	printf("2. Tidak\n");
        	printf("Pilih menu: ");
        	scanf("%d", &pilihanPieces);
        	if(pilihanPieces == 1) {
        		Serving_Dikonsumsi = hitungServing();
			}
			else{
				printf("Jumlah Serving yang Dikomsumsi: ");
				scanf("%f", &Serving_Dikonsumsi);
			}
		}
		else {
			printf("Jumlah Serving yang Diminum: ");
			scanf("%f", &Serving_Dikonsumsi);
		}
		if(Serving_Dikonsumsi > Jumlah_Persajian){
			printf("\nJumlah Konsumsi Melebihi Total Sajian Dalam Kemasan");
		}
		else{
			//belum
		}
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
void Nilai_Gizi() {
	printf("Gula Total: ");
	scanf("%d", &Gula_Total);
	printf("Natrium: ");
	scanf("%d", &Natrium_Total);
	printf("Karbohidrat: ");
	scanf("%d", &Karbo_Total);
	printf("Lemak Total: ");
	scanf("%d", &Lemak_Total);
	printf("Lemak Jenuh: ");
	scanf("%d", &Lemak_Jenuh);
	printf("Protein: ");
	scanf("%d", &Protein_Total);
	
	printf("\nGula Total        : %d\n", Gula_Total);
	printf("Natrium           : %d\n", Natrium_Total);
	printf("Karbohidrat       : %d\n", Karbo_Total);
	printf("Lemak Total       : %d\n", Lemak_Total);
	printf("Lemak Jenuh       : %d\n", Lemak_Jenuh);
	printf("Protein           : %d\n", Protein_Total);
}

float hitungServing(){
	float Pieces_Dikonsumsi;
	float Pieces_Persajian;
	float Serving_Dikonsumsi;
	printf("\nJumlah Pieces Per Sajian: ");
	scanf("%f", &Pieces_Persajian);
	printf("Jumlah Pieces yang Dikonsumsi: ");
	scanf("%f", &Pieces_Dikonsumsi);
	Serving_Dikonsumsi = Pieces_Dikonsumsi/Pieces_Persajian;
	return Serving_Dikonsumsi;
}
