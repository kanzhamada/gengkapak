#include <stdio.h>
/* */
int idx = 0;
FILE *JL;
FILE *NL;
FILE *History;

struct jenis_layanan{
	int id_jenis;
	char jenislay[30];
	long long int hargalay;	
} menujenis[100];

struct nama_layanan{
	int id_nama;
	char nama[30];
	char isi[100];
	long long int hargabundling;	
} bundling[100];

//struct riwayat{
//	int tanggal, bulan, tahun;
//	char nama;
//	char paket;
//	struct nama_layanan.nama paket;
//	struct nama_layanan.hargabundling harga_paket;
//	struct jenis_layanan.jenislay custom;
//	struct jenis_layanan.hargalay harga_custom;
//	int total;
//} riwayat_pelanggan[100];



void TampilServiceJ();
void TampilServiceN();
void copyrightGengKapak();
void EntryPesanan();



int main(){
	int opsi;
	printf("=============================================================\n");
	printf("===================== Barbershop Service ====================\n");
	printf("=============================================================\n\n");
	
	printf("\n(1). Masukan Pesanan Pelanggan\n");
	printf("(2). Riwayat Penjualan\n");
	printf("\n\nPilih Opsi [1/2] : ");
	scanf("%d", &opsi);
	if(opsi == 1){
		copyrightGengKapak();
		printf("\n\n     <<<<< Service Biasa >>>>>\n\n");
		TampilServiceJ();
		printf("\n     <<<<< Service Bundling >>>>>\n");
		TampilServiceN();
		printf("\n");
		EntryPesanan();
	}
	if(opsi == 2){
		printf("tes 2");
	}
	copyrightGengKapak();
}

//void InputJenisLayananBaru (){
//	printf("\n----------------------------------\n");
//	JL = fopen("jenislayanan.txt", "r+");
//	if(JL == NULL){
//		printf("File Tidak Ada!!");
//	}
////	struct jenis_layanan layanan;	
//	printf("Masukan ID : "); 
//	scanf("%d", &menujenis[idx].id_jenis);
//	getchar();
////	mengecek apakah ada ID yang sama?
////	for(int i = 0; i <= 100; i++){
////		if(menujenis[idx].id_jenis == menujenis[i].id_jenis){
////			menujenis[i].id_jenis = '\0';
////			printf("ID Sudah ada");
////		}
////	}
//	printf("Jenis Layanan : "); 
//	scanf("%[^\n]", menujenis[idx].jenislay);
//	getchar();
//	printf("Harga : "); 
//	scanf("%lld", &menujenis[idx].hargalay);
//	getchar();
//	fprintf(JL, "%d - %s - %d", menujenis[idx].id_jenis, menujenis[idx].jenislay, menujenis[idx].hargalay);
//	printf("\nId: %d || Jenis : %s || Harga : Rp.%lld, Berhasil disimpan", menujenis[idx].id_jenis, menujenis[idx].jenislay, menujenis[idx].hargalay);	
//	idx++;
//}

//void InputNamaLayanan (){
//	char namalay[30];
//	int id_jenis;
//	int total;
//}

int HitungTotalPembayaran (){
	
}

void Sorting(){
	
}

int pembayaran(int idygmana, int cuan){
	int kembali;
	for(int i = 0; i < 100; i++){
			if(idygmana == bundling[i].id_nama){
				kembali = cuan - bundling[i].hargabundling;
				return kembali;
			} 
		}
	
}

void tampilkan_pencarian(int cariwoi){
	for(int i = 0; i < 100; i++){
			if(cariwoi == bundling[i].id_nama){
				printf("\nPaket \t: %s\nLayanan : %s\nTotal \t: %d", bundling[i].nama, bundling[i].isi, bundling[i].hargabundling);
			} 
		}
}

int cari_bundling(int nyari_id){
		for(int i = 0; i < 100; i++){
			if(nyari_id == bundling[i].id_nama){
				return nyari_id;
			} 
		}
		return -1;
}

void carilagi(){
	
}

void EntryPesanan(){
	int tanggal, bulan, tahun;
	long int uang;
	int pilih_paket;
	char customer_name[25];
	
	History = fopen("riwayatpesanan.txt", "r+");
	
	printf("---------------------- Enter Customer Data ---------------------\n");
	printf("Transaction date (dd/mm/yy) : ");
	scanf("%d/%d/%d", &tanggal, &bulan, &tahun);
	getchar();
	while((tanggal > 31 || tanggal < 1) || (bulan > 12 || bulan < 1) || (tahun < 2020)){
		tanggal = 0, bulan = 0, tahun = 0;
		printf("Tanggal Tidak Valid\n");
		printf("Transaction date (dd/mm/yy) : ");
		scanf("%d/%d/%d", &tanggal, &bulan, &tahun);
		getchar();
	}
	printf("\nCustomer name : ");
	scanf("%[^\n]", &customer_name);
	getchar();
	printf("%s, Tanggal : %d - %d - %d", customer_name, tanggal, bulan, tahun);
	int milih;
	printf("\n(1) Bundle or (2) Custom : ");
	scanf("%d", &milih);
	if(milih == 1){
		printf("Pilih Id Paket : ");
		scanf("%d", &pilih_paket);
		getchar();
		
		cari_bundling(pilih_paket);
		
		while(cari_bundling(pilih_paket) == -1){
			printf("\nPaket / ID Tidak Ditemukan!\n");
			printf("Pilih Id Paket : ");
			scanf("%d", &pilih_paket);
			getchar();
			cari_bundling(pilih_paket);
		}
		
		tampilkan_pencarian(cari_bundling(pilih_paket));
		printf("\nUang Pelanggan : Rp.");
		scanf("%ld", &uang);
		
		printf("Kembali = Rp.%d", pembayaran(cari_bundling(pilih_paket), uang));
		int ulang = 0;
		do{
			fprintf(History, "%d/%d/%d - %s - Paket : %s (Rp.%d) - Bayar : Rp.%d, Kembali Rp.%d\n", tanggal, bulan, tahun, customer_name, bundling[cari_bundling(pilih_paket)].nama, bundling[cari_bundling(pilih_paket)].hargabundling, uang, pembayaran(cari_bundling(pilih_paket), uang));
			++ulang;
		} while(ulang <= 100);
			
		} else if (milih == 2){
		TampilServiceJ();
	}
}

void copyrightGengKapak(){
	printf("\n---------------- Copyright by @Geng Kapak 2023 ---------------");
}

void RiwayatPesanan(){
	
}

void TampilServiceJ(){
	JL = fopen("jenislayanan.txt", "r+");
	while (fscanf(JL, "%d-%[^-]-%d\r\n", &menujenis[idx].id_jenis, &menujenis[idx].jenislay, &menujenis[idx].hargalay) != EOF){
		printf("________________________________\nId \t : %d\nLayanan\t : %s \nHarga \t : Rp.%d\n", menujenis[idx].id_jenis, menujenis[idx].jenislay, menujenis[idx].hargalay);
		idx++;
	}
}

void TampilServiceN(){
	NL = fopen("namalayanan.txt", "r+");
	while (fscanf(NL, "%d-%[^-]-%[^-]-%d\r\n", &bundling[idx].id_nama, &bundling[idx].nama, &bundling[idx].isi, &bundling[idx].hargabundling) != EOF){
		printf("________________________________\nId \t : %d\nPaket\t : %s \nLayanan\t : %s \nHarga \t : Rp.%d\n", bundling[idx].id_nama, bundling[idx].nama, bundling[idx].isi, bundling[idx].hargabundling);
		idx++;
	}
}
