#include <stdio.h>
#include <string.h>

// 1. ENUM untuk tipe data kategori agar kode lebih readable
typedef enum { FOOD = 1, BEVERAGE, EXIT } ProductType;
typedef enum { CHILD = 1, TEEN, ADULT } AgeCategory;
typedef enum { SAFE, WARNING, DANGER } HealthStatus;

// 2. STRUCT untuk mengelompokkan informasi nilai gizi (Nutrisi)
typedef struct {
    float total_fat;
    float saturated_fat;
    float protein;
    float carbohydrates;
    float sugar;
    float sodium;
} Nutrition;

// 3. UNION untuk efisiensi memori pada input porsi (karena makanan vs minuman berbeda metode)
typedef union {
    struct {
        int has_pieces;
        float pieces_per_serving;
        float pieces_consumed;
        float portion_size; // bagian kemasan (1, 0.5, 0.25)
    } food_detail;
    float beverage_consumed_ml;
} ServingDetail;

// 4. STRUCT Utama untuk membungkus semua data produk
typedef struct {
    char name[100];
    ProductType type;
    AgeCategory age_cat;
    float servings_per_pack;
    float serving_size; // gram atau mL
    float serving_consumed; // hitungan SD (serving dikonsumsi)
    float total_consumed; // hitungan gram/mL dikonsumsi
    ServingDetail details;
    Nutrition base_nutr;  // per sajian
    Nutrition total_nutr; // total dikonsumsi
    float total_calories;
    Nutrition akg_percentage;
    float calorie_percentage;
    HealthStatus status;
} ProductAnalysis;

// 5. STRUCT untuk master data batas harian (Bentuk Array Objek)
typedef struct {
    int max_sugar;
    int max_sodium;
    int max_sat_fat;
    int calorie_need;
    char label[20];
} LimitConfig;

// Master Data Batas Harian berdasarkan indeks Kategori Umur (menggunakan array)
const LimitConfig AGE_LIMITS[] = {
    {0, 0, 0, 0, "None"}, // Dummy indeks 0
    {25, 1200, 10, 1400, "Anak-anak"}, // Indeks 1 (CHILD)
    {40, 1500, 15, 2000, "Remaja"},    // Indeks 2 (TEEN)
    {50, 2000, 20, 2150, "Dewasa"}     // Indeks 3 (ADULT)
};

// String bantuan untuk output status
const char* STATUS_STR[] = {"AMAN", "WASPADA", "BAHAYA"};

// 6. PROTOTIPE FUNGSI (Menggunakan Pointer untuk Efisiensi)
void display_header();
void get_age_category(AgeCategory *age_cat);
void display_limits(AgeCategory age_cat);
void process_serving(ProductAnalysis *prod);
void calculate_nutrition(ProductAnalysis *prod);
void determine_status_and_advice(const ProductAnalysis *prod, char *analysis_text, char *advice_text);
void display_output(const ProductAnalysis *prod, const char *analysis, const char *advice);

int main() {
    ProductAnalysis prod;
    char analysis_msg[1000];
    char advice_msg[3000];

    display_header();

    while (1) {
        printf("> Pilihan Jenis Produk\n1. Makanan\n2. Minuman\n3. Exit\n\nMasukkan jenis produk: ");
        int input_type;
        scanf("%d", &input_type);
        prod.type = (ProductType)input_type;

        if (prod.type == EXIT) {
            printf("\nTerima kasih telah menggunakan program kami!\n");
            break;
        }
        if (prod.type < FOOD || prod.type > EXIT) {
            printf("\nInput jenis produk salah!\n\n");
            continue;
        }

        // Panggil fungsi dengan melempar Alamat Memori (Pointer)
        get_age_category(&prod.age_cat);
        display_limits(prod.age_cat);

        printf("\nMasukkan nama produk: ");
        scanf(" %[^\n]", prod.name);
        printf("Masukkan jumlah sajian per kemasan: ");
        scanf("%f", &prod.servings_per_pack);

        process_serving(&prod);
        calculate_nutrition(&prod);
        determine_status_and_advice(&prod, analysis_msg, advice_msg);
        display_output(&prod, analysis_msg, advice_msg);
    }
    return 0;
}

void display_header() {
    printf("===================================================\n");
    printf("          PROGRAM ANALISIS BATAS KONSUMSI\n");
    printf("       Berdasarkan Takaran Saji Pada Kemasan\n");
    printf("===================================================\n\n");
}

// Implementasi Pointer untuk memutasi data secara langsung
void get_age_category(AgeCategory *age_cat) {
    int input_age;
    do {
        printf("\n> Pilih Kategori Umur\n1. Anak-anak (5-12 tahun)\n2. Remaja (13-17 tahun)\n3. Dewasa (18+ tahun)\n\nMasukkan kategori umur Anda: ");
        scanf("%d", &input_age);
        if (input_age < 1 || input_age > 3) {
            printf("\nInput kategori umur salah!\n");
        }
    } while (input_age < 1 || input_age > 3);
    *age_cat = (AgeCategory)input_age;
}

// Implementasi Array pembacaan data konfigurasi umur
void display_limits(AgeCategory age_cat) {
    printf("\n===============================================\n");
    printf("> Menampilkan Batas Harian Kategori %s\n\n", AGE_LIMITS[age_cat].label);
    printf("Gula             : %d gram\n", AGE_LIMITS[age_cat].max_sugar);
    printf("Natrium          : %d mg\n", AGE_LIMITS[age_cat].max_sodium);
    printf("Lemak jenuh      : %d gram\n", AGE_LIMITS[age_cat].max_sat_fat);
    printf("Kebutuhan energi : %d kkal/hari\n", AGE_LIMITS[age_cat].calorie_need);
    printf("===============================================\n");
}

// Implementasi UNION & Pointer
void process_serving(ProductAnalysis *prod) {
    if (prod->type == FOOD) {
        printf("\nMasukkan takaran saji makanan (gram): ");
        scanf("%f", &prod->serving_size);
        printf("\nApakah terdapat jumlah pieces?\n1. Ya\n2. Tidak\n\n> ");
        scanf("%d", &prod->details.food_detail.has_pieces);

        if (prod->details.food_detail.has_pieces == 1) {
            printf("\nMasukkan jumlah pieces per saji: ");
            scanf("%f", &prod->details.food_detail.pieces_per_serving);
            printf("Masukkan jumlah pieces yang dikonsumsi: ");
            scanf("%f", &prod->details.food_detail.pieces_consumed);

            prod->serving_consumed = prod->details.food_detail.pieces_consumed / prod->details.food_detail.pieces_per_serving;
        } else {
            printf("\nBerapa bagian kemasan yang dikonsumsi?\n1    = seluruh kemasan\n0.5  = setengah kemasan\n0.25 = seperempat kemasan\n\n> ");
            scanf("%f", &prod->details.food_detail.portion_size);

            prod->serving_consumed = prod->servings_per_pack * prod->details.food_detail.portion_size;
        }
        prod->total_consumed = prod->serving_consumed * prod->serving_size;
    } else if (prod->type == BEVERAGE) {
        printf("\nMasukkan takaran saji minuman (mL): ");
        scanf("%f", &prod->serving_size);
        printf("Masukkan jumlah minuman yang dikonsumsi (mL): ");
        scanf("%f", &prod->details.beverage_consumed_ml);

        prod->serving_consumed = prod->details.beverage_consumed_ml / prod->serving_size;
        prod->total_consumed = prod->details.beverage_consumed_ml;
    }
}

void calculate_nutrition(ProductAnalysis *prod) {
    printf("\n---\n\nMasukkan Lemak Total per sajian (gram): ");
    scanf("%f", &prod->base_nutr.total_fat);
    printf("Masukkan Lemak Jenuh per sajian (gram): ");
    scanf("%f", &prod->base_nutr.saturated_fat);
    printf("Masukkan Protein per sajian (gram): ");
    scanf("%f", &prod->base_nutr.protein);
    printf("Masukkan Karbohidrat Total per sajian (gram): ");
    scanf("%f", &prod->base_nutr.carbohydrates);
    printf("Masukkan Gula Total per sajian (gram): ");
    scanf("%f", &prod->base_nutr.sugar);
    printf("Masukkan Natrium per sajian (mg): ");
    scanf("%f", &prod->base_nutr.sodium);
    printf("\n---\n");

    // Kalkulasi Berbasis Pointer Struct
    float sd = prod->serving_consumed;
    prod->total_nutr.total_fat = prod->base_nutr.total_fat * sd;
    prod->total_nutr.saturated_fat = prod->base_nutr.saturated_fat * sd;
    prod->total_nutr.protein = prod->base_nutr.protein * sd;
    prod->total_nutr.carbohydrates = prod->base_nutr.carbohydrates * sd;
    prod->total_nutr.sugar = prod->base_nutr.sugar * sd;
    prod->total_nutr.sodium = prod->base_nutr.sodium * sd;

    prod->total_calories = (prod->total_nutr.carbohydrates * 4) + (prod->total_nutr.protein * 4) + (prod->total_nutr.total_fat * 9);
    
    // Hitung Persentase AKG menggunakan Master Array
    LimitConfig limits = AGE_LIMITS[prod->age_cat];
    prod->calorie_percentage = (prod->total_calories / limits.calorie_need) * 100;
    prod->akg_percentage.sugar = (prod->total_nutr.sugar / limits.max_sugar) * 100;
    prod->akg_percentage.sodium = (prod->total_nutr.sodium / limits.max_sodium) * 100;
    prod->akg_percentage.saturated_fat = (prod->total_nutr.saturated_fat / limits.max_sat_fat) * 100;
}

void determine_status_and_advice(const ProductAnalysis *prod, char *analysis_text, char *advice_text) {
    // 1. Tentukan Analisis Konsumsi Kemasan
    if (prod->serving_consumed > prod->servings_per_pack) {
        strcpy(analysis_text, "Jumlah konsumsi melebihi sajian per kemasan.");
    } else if (prod->serving_consumed == prod->servings_per_pack) {
        strcpy(analysis_text, "Jumlah konsumsi sesuai sajian per kemasan.");
    } else {
        strcpy(analysis_text, "Jumlah konsumsi masih di bawah sajian per kemasan.");
    }

    // 2. Tentukan Status Kesehatan (Aman / Waspada / Bahaya)
    HealthStatus final_status = SAFE;
    if (prod->akg_percentage.sugar > 100 || prod->akg_percentage.sodium > 100 || prod->akg_percentage.saturated_fat > 100) {
        final_status = DANGER;
    } else if (prod->akg_percentage.sugar >= 70 || prod->akg_percentage.sodium >= 70 || prod->akg_percentage.saturated_fat >= 70) {
        final_status = WARNING;
    }
    // Menggunakan Pointer (Mutasi langsung status di dalam Objek utama)
    ((ProductAnalysis*)prod)->status = final_status;

    // 3. Ambil Teks Saran Berdasarkan Kombinasi Enum Status & Tipe Produk
    if (final_status == SAFE) {
        if (prod->type == FOOD) {
            strcpy(advice_text, "Konsumsi makanan masih dalam batas aman berdasarkan jumlah gula, natrium, dan lemak jenuh yang dikonsumsi... \n> Baca selengkapnya: https://www.who.int/news-room/fact-sheets/detail/healthy-diet");
        } else {
            strcpy(advice_text, "Konsumsi minuman masih dalam batas aman berdasarkan jumlah gula, natrium, dan lemak jenuh yang dikonsumsi... \n> Baca selengkapnya: https://www.who.int/news-room/fact-sheets/detail/healthy-diet");
        }
    } else if (final_status == WARNING) {
        if (prod->type == FOOD) {
            strcpy(advice_text, "Jumlah konsumsi makanan mulai mendekati batas harian yang direkomendasikan... \n> Baca selengkapnya: https://www.who.int/news-room/fact-sheets/detail/healthy-diet");
        } else {
            strcpy(advice_text, "Jumlah konsumsi minuman mulai mendekati batas harian yang direkomendasikan... \n> Baca selengkapnya: https://www.heart.org/en/healthy-living");
        }
    } else {
        if (prod->type == FOOD) {
            strcpy(advice_text, "Jumlah konsumsi makanan telah melebihi batas harian yang direkomendasikan... \n> Baca selengkapnya: https://www.who.int/news-room/fact-sheets/detail/healthy-diet");
        } else {
            strcpy(advice_text, "Jumlah konsumsi minuman telah melebihi batas harian yang direkomendasikan... \n> Baca selengkapnya: https://www.heart.org/en/healthy-living");
        }
    }
}

void display_output(const ProductAnalysis *prod, const char *analysis, const char *advice) {
    printf("\n=====================================================\n");
    printf("              HASIL ANALISIS KONSUMSI\n");
    printf("=====================================================\n\n");
    printf("Nama produk                    : %s\n", prod->name);
    printf("Kategori umur                  : %s\n", AGE_LIMITS[prod->age_cat].label);
    printf("Jumlah %s dikonsumsi      : %.2f %s\n", (prod->type == FOOD) ? "makanan" : "minuman", prod->total_consumed, (prod->type == FOOD) ? "gram" : "mL");
    printf("Jumlah sajian dikonsumsi       : %.2f sajian\n", prod->serving_consumed);

    printf("\nTOTAL KANDUNGAN GIZI\n");
    printf("Lemak total                    : %.2f gram\n", prod->total_nutr.total_fat);
    printf("Lemak jenuh                    : %.2f gram\n", prod->total_nutr.saturated_fat);
    printf("Protein                        : %.2f gram\n", prod->total_nutr.protein);
    printf("Karbohidrat total              : %.2f gram\n", prod->total_nutr.carbohydrates);
    printf("Gula total                     : %.2f gram\n", prod->total_nutr.sugar);
    printf("Natrium                        : %.2f mg\n", prod->total_nutr.sodium);

    printf("\nPERSENTASE BATAS HARIAN\n");
    printf("Persentase gula                : %.2f%%\n", prod->akg_percentage.sugar);
    printf("Persentase natrium             : %.2f%%\n", prod->akg_percentage.sodium);
    printf("Persentase lemak jenuh         : %.2f%%\n", prod->akg_percentage.saturated_fat);

    printf("\nTOTAL ENERGI\n");
    printf("Total energi dikonsumsi        : %.2f kkal\n", prod->total_calories);
    printf("Persentase kebutuhan energi    : %.2f%%\n", prod->calorie_percentage);

    printf("\nAnalisis konsumsi:\n%s\n", analysis);
    printf("\nStatus konsumsi:\n%s\n", STATUS_STR[prod->status]);
    printf("\nSaran:\n%s\n", advice);
    printf("\n=====================================================\n\n");
}