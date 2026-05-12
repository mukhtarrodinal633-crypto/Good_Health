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
    printf("\n==>> Identitas Dan Jumlah Persajian Produk <<==\n");
    printf("Nama Produk: ");
    scanf(" %[^\n]", Nama_Produk);

    printf("Jumlah Persajian: ");
    scanf("%d", &Jumlah_Persajian);

    printf("\nNama Produk       : %s\n", Nama_Produk);
    printf("Jumlah Persajian  : %d\n", Jumlah_Persajian);

    printf("\n==>> Nilai Gizi per Persajian <<==\n");
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
