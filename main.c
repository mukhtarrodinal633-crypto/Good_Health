#include<stdio.h>
#include<string.h>

int main(){
	// JUDUL PROGRAM
	printf("========================================\n");
	printf("    PROGRAM ANALISIS BATAS KONSUMSI \n");
	printf("    Berdasarkan Takaran Saji Kemasan \n");
	printf("========================================\n\n");
	
	// LOOP PROGRAM
	// Program akan terus berjalan sampai user memilih Exit
	int jenis_produk;
	int kategori_umur;
	
	int batas_gula;
	int batas_natrium;
	int batas_lemakjenuh;
	
	char nama_produk[100];
	float sajian_per_kemasan;

	int pilihan_pieces;
	float takaran_saji;
	
	float pieces_per_saji;
	float pieces_dikonsumsi;
	float bagian_kemasan;
	
	float minuman_dikonsumsi;
	float serving_dikonsumsi;
	float gram_dikonsumsi;
		
	float lemak_total;
	float lemak_jenuh;
	float protein;
	float karbohidrat_total;
	float gula_total;
	float natrium;
	
	float total_lemak_total;
	float total_lemak_jenuh;
	float total_protein;
	float total_karbohidrat_total;
	float total_gula_total;
	float total_natrium;
	
	char status[20];
	char analisis_konsumsi[1000];
	char saran[1000];
	
	do{
		printf("> Pilihan Jenis Produk\n"
				"1. Makanan\n"
				"2. Minuman\n"
				"3. Exit\n");
		printf("\nMasukkan jenis produk yang diinginkan: ");
		scanf("%d", &jenis_produk);
	
		// Jika jenis_produk = 3
		if ( jenis_produk == 3 ){
			printf("\nTerima kasih telah menggunakan layanan kami!\n");
		break;
		}
	
		// Jika jenis_produk < 1 atau > 3
		if ( jenis_produk < 1 || jenis_produk > 3 ){
			printf("\nInput kategori jenis produk salah!\n\n");
		continue;
		}
	
		do{
			// INPUT KATEGORI UMUR
			printf("\n> Pilih Kategori Umur Kamu\n"
					"1. Anak-anak (5-12 tahun)\n"
					"2. Remaja (13-17 tahun)\n"
					"3. Dewasa (18+ tahun)\n");
			printf("\nMasukkan kategori umur Anda: ");
			scanf("%d", &kategori_umur);
			
			if ( kategori_umur < 1 || kategori_umur > 3 ){
				printf("\nInput kategori umur Anda salah!\n");
			}
		} while( kategori_umur < 1 || kategori_umur > 3 );
		
		// MENENTUKAN BATAS KONSUMSI BERDASARKAN KATEGORI UMUR
		if (kategori_umur == 1){
			batas_gula = 25;
			batas_natrium = 1200;
			batas_lemakjenuh = 10;
		}
	
		else if (kategori_umur == 2){
			batas_gula = 40;
			batas_natrium = 1500;
			batas_lemakjenuh = 15;	
		}
	
		else if (kategori_umur == 3){
			batas_gula = 50;
			batas_natrium = 2000;
			batas_lemakjenuh = 20;	
		}
		
		// INPUT IDENTITAS PRODUK
		printf("\nMasukkan nama produk: ");
		scanf(" %[^\n]", nama_produk);
		
		printf("Masukkan jumlah sajian per kemasan: ");
		scanf("%f", &sajian_per_kemasan);
		
		// INPUT JUMLAH KONSUMSI
		if ( jenis_produk == 1 ){
			
			printf("\nMasukkan takaran saji makanan (gr): ");
			scanf("%f", &takaran_saji);
			
			printf("\nApakah takaran saji memiliki jumlah sajian (pieces)?\n"
					"1. Ya\n"
					"2. Tidak\n\n");
			printf("> ");
			scanf("%d", &pilihan_pieces);
		
			if ( pilihan_pieces == 1 ){
				printf("\nMasukkan jumlah pieces per saji: ");
				scanf("%f", &pieces_per_saji);
			
				printf("Masukkan jumlah pieces yang dikonsumsi: ");
				scanf("%f", &pieces_dikonsumsi);
			
				// Menghitung jumlah serving
				serving_dikonsumsi = pieces_dikonsumsi / pieces_per_saji;
				// Menghitung jumlah gram yang dikonsumsi
				gram_dikonsumsi = serving_dikonsumsi * takaran_saji;
				
			} else {
				printf("\nBerapa bagian kemasan yang dikonsumsi?\n");
				printf("Contoh:\n"
						"1    = seluruh kemasan\n"
						"0.5  = setengah kemasan\n"
						"0.25 = seperempat kemasan\n");
				printf("> ");
				scanf("%f", &bagian_kemasan);

				// Menghitung serving
				serving_dikonsumsi = sajian_per_kemasan * bagian_kemasan;
			}
		}
			
		else if ( jenis_produk == 2 ){
			printf("\nMasukkan takaran saji minuman (mL): ");
			scanf("%f", &takaran_saji);
			
			printf("Masukkan jumlah minuman yang dikonsumsi (mL): ");
			scanf("%f", &minuman_dikonsumsi);
			
			serving_dikonsumsi = minuman_dikonsumsi / takaran_saji;
		}

		printf("---\n");
		
		// INPUT INFORMASI NILAI GIZI BERDASARKAN PER SAJIAN
		printf("\nMasukkan jumlah Lemak Total sesuai tabel informasi gizi (gr): ");
		scanf("%f", &lemak_total);
		
		printf("Masukkan jumlah Lemak Jenuh sesuai tabel informasi gizi (gr): ");
		scanf("%f", &lemak_jenuh);
		
		printf("Masukkan jumlah Protein sesuai tabel informasi gizi (gr): ");
		scanf("%f", &protein);
		
		printf("Masukkan jumlah Karbohidrat Total sesuai tabel informasi gizi (gr): ");
		scanf("%f", &karbohidrat_total);
		
		printf("Masukkan jumlah Gula Total sesuai tabel informasi gizi (gr): ");
		scanf("%f", &gula_total);
		
		printf("Masukkan jumlah Garam (Natrium) sesuai tabel informasi gizi (mg): ");
		scanf("%f", &natrium);
		
		printf("---\n");
		
		// PROSES PERHITUNGAN TOTAL KANDUNGAN
		total_lemak_total 		= lemak_total * serving_dikonsumsi;
		total_lemak_jenuh 		= lemak_jenuh * serving_dikonsumsi;
		total_protein    		= protein * serving_dikonsumsi;
		total_karbohidrat_total = karbohidrat_total * serving_dikonsumsi;
		total_gula_total        = gula_total * serving_dikonsumsi;
		total_natrium			= natrium * serving_dikonsumsi;
		
		// MENENTUKAN STATUS KONSUMSI
		strcpy(status, "AMAN");

		if (total_gula_total > batas_gula){
			strcpy(status, "BAHAYA");
		} else if (
			total_gula_total >= batas_gula * 0.7 && strcmp(status, "BAHAYA") != 0){
			strcpy(status, "WASPADA");
		}

		if (total_natrium > batas_natrium){
			strcpy(status, "BAHAYA");
		} else if (
			total_natrium >= batas_natrium * 0.7 && strcmp(status, "BAHAYA") != 0){
			strcpy(status, "WASPADA");
		}

		if (total_lemak_jenuh > batas_lemakjenuh){
			strcpy(status, "BAHAYA");
		} else if (
			total_lemak_jenuh >= batas_lemakjenuh * 0.7 && strcmp(status, "BAHAYA") != 0){
			strcpy(status, "WASPADA");
		}
    
		// MENENTUKAN SARAN
		if (strcmp(status, "AMAN") == 0) {
    		strcpy(saran, "Pertahankan pola konsumsi seimbang dan tetap membatasi makanan tinggi gula, natrium, dan lemak jenuh. WHO (World Health Organization) merekomendasikan pola makan sehat dengan memperbanyak konsumsi buah, sayur, dan makanan bergizi seimbang untuk menjaga kesehatan tubuh dalam jangka panjang.\n"
    				"> Baca selengkapnya: https://www.who.int/news-room/fact-sheets/detail/healthy-diet");
		} else if (strcmp(status, "WASPADA") == 0) {
    		strcpy(saran, "Kurangi frekuensi konsumsi makanan atau minuman tinggi gula, natrium, dan lemak jenuh. Disarankan untuk memperhatikan informasi nilai gizi pada kemasan dan menyeimbangkan konsumsi dengan aktivitas fisik serta asupan makanan bergizi lainnya.\n"
    				"> Baca selengkapnya: https://www.who.int/news-room/fact-sheets/detail/healthy-diet");
		} else if (strcmp(status, "BAHAYA") == 0) {
    		strcpy(saran, "Batasi konsumsi produk tinggi gula, natrium, dan lemak jenuh serta hindari konsumsi berlebihan dalam satu waktu. WHO (World Health Organization) dan AHA (American Heart Association) menyarankan pembatasan gula tambahan, natrium, dan lemak jenuh untuk membantu mencegah penyakit tidak menular dan menjaga kesehatan jangka panjang.\n"
    				"> Baca selengkapnya: https://www.heart.org/en/healthy-living");
		}
		
		// ANALISIS JUMLAH KONSUMSI
		if (serving_dikonsumsi > sajian_per_kemasan) {
    		strcpy(analisis_konsumsi, "Jumlah konsumsi melebihi sajian per kemasan.");
		} else if (serving_dikonsumsi == sajian_per_kemasan) {
    		strcpy(analisis_konsumsi, "Jumlah konsumsi sesuai sajian per kemasan.");
		} else {
    		strcpy(analisis_konsumsi, "Jumlah konsumsi masih di bawah sajian per kemasan.");
		}
    
		// OUTPUT KESELURUHAN ANALISIS PROGRAM
		printf("========================================\n");
		printf("        HASIL ANALISIS KONSUMSI \n");
		printf("========================================\n\n");
		
		printf("Nama produk                   : %s\n", nama_produk);
		printf("Kategori umur                 : %d\n", kategori_umur);
		printf("Jumlah sajian yang dikonsumsi : %.f sajian\n", serving_dikonsumsi);
		printf("Jumlah lemak total            : %.f gram\n", total_lemak_total);
		printf("Jumlah lemak jenuh            : %.f gram\n", total_lemak_jenuh);
		printf("Jumlah protein                : %.f gram\n", total_protein);
		printf("Jumlah karbohidrat total      : %.f gram\n", total_karbohidrat_total);
		printf("Jumlah gula                   : %.f gram\n", total_gula_total);
		printf("Jumlah natrium                : %.f milligram\n\n", total_natrium);
		
		printf("Analisis: \n%s\n\n", analisis_konsumsi);
		printf("Status konsumsi: \n%s\n\n", status);
		printf("Saran: \n%s\n\n", saran);
		
		printf("---\n");
		
	} while(jenis_produk != 3);
	
	return 0;
}
