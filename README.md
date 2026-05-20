# SDG 3: Good Health and Well-Being
## Implementasi SDG 3: Good Health and Well-Being Melalui Program Analisis Batas Konsumsi Berdasarkan Takaran Saji Pada Makanan dan Minuman Kemasan

Disusun Oleh:
Kelompok 5 HERMES
- Cristian (2506550822)
- Haikel Zaki Nurfaiz	(2506533394)
- Rodinal Mukhtar Aulya	(2506553263)
- Thoriq Muhammad Fatih	(2506549410)

---

## Informasi Singkat

SDG 3 bertujuan untuk memastikan kehidupan yang sehat dan meningkatkan kesejahteraan bagi semua orang, di segala usia. Selain itu, SDG 3 bertujuan untuk mencegah penderitaan yang tidak perlu akibat penyakit yang dapat dicegah serta kematian dini dengan berfokus pada sasaran-sasaran utama yang meningkatkan kesehatan populasi suatu negara secara keseluruhan.

Program ini sesuai dengan SDG 3: Good Health and Well-Being karena berfokus pada peningkatan kesadaran masyarakat terhadap kesehatan melalui pola konsumsi makanan dan minuman yang lebih sehat. Salah satu tujuan SDG 3 adalah mengurangi risiko penyakit tidak menular seperti diabetes, obesitas, tekanan darah tinggi, dan penyakit jantung yang banyak dipengaruhi oleh konsumsi gula, natrium, lemak jenuh, dan kalori berlebihan. 

Program ini membantu pengguna mengetahui apakah jumlah konsumsi mereka masih dalam batas aman, berada pada kondisi waspada, atau sudah berbahaya berdasarkan rekomendasi kesehatan dan kebutuhan energi harian. Dengan adanya informasi tersebut, pengguna diharapkan dapat lebih bijak dalam memilih dan mengontrol konsumsi makanan maupun minuman kemasan sehingga dapat mendukung gaya hidup yang lebih sehat.

## Fitur
- Analisis gula, natrium, dan lemak jenuh
- Status konsumsi: Aman, Waspada, Bahaya
- Perhitungan energi total
- Mendukung makanan dan minuman

## Bahasa Pemrograman
- C Programming Language

## Struktur Data yang Digunakan
- Array
- Struct
- Enum
- Union
- Pointer

## Cara Menjalankan
1. Compile program
2. Jalankan file .exe
3. Masukkan data produk

## Alur Program

Program dimulai dengan meminta pengguna memilih jenis produk, yaitu makanan atau minuman, kemudian memilih kategori umur sesuai pengguna. Setelah itu, program menampilkan batas konsumsi harian berdasarkan kategori umur berupa batas gula, natrium, lemak jenuh, dan kebutuhan energi harian. Selanjutnya, pengguna memasukkan nama produk, jumlah sajian per kemasan, serta informasi nilai gizi per sajian seperti lemak total, lemak jenuh, protein, karbohidrat total, gula total, dan natrium.

Untuk produk makanan, pengguna memasukkan takaran saji makanan dan memilih apakah produk memiliki jumlah pieces atau tidak. Jika memiliki pieces, pengguna memasukkan jumlah pieces per sajian dan jumlah pieces yang dikonsumsi sehingga program dapat menghitung total serving dan jumlah makanan yang dikonsumsi. Jika tidak memiliki pieces, pengguna memasukkan bagian kemasan yang dikonsumsi. Pada produk minuman, pengguna memasukkan takaran saji minuman dan jumlah minuman yang dikonsumsi sehingga program dapat menghitung total serving dan jumlah minuman yang diminum.

Program kemudian menghitung total kandungan nutrisi, total energi, serta persentase konsumsi terhadap batas harian berdasarkan jumlah konsumsi pengguna. Setelah itu, program membandingkan hasil konsumsi dengan batas harian untuk menentukan status konsumsi dalam kategori AMAN, WASPADA, atau BAHAYA. Hasil akhir program menampilkan informasi konsumsi, total kandungan gizi, persentase batas harian, total energi, analisis konsumsi, status konsumsi, serta saran kesehatan sesuai kondisi pengguna.
