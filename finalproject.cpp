#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* */
int idx;

FILE *JL;
FILE *NL;
FILE *History;
FILE *IStok;

struct iniStok{
	char namastok[25];
	int qty;
}iStok[100];

struct jenis_layanan{
	int id_jenis;
	char jenislay[30];
	float hargalay;	
	int stok;
} menujenis[100];

struct nama_layanan{
	int id_nama;
	char nama[30];
	char isi[100];
	float hargabundling;	
} bundling[100];

struct entry_pesanan{
	int tanggal, bulan, tahun;
	char customer_name[25];
	char pesanan[30];
	float total_harga;
} masukin_pesanan[100];

// Prototype ------------------------
void TampilServiceJ();
void TampilServiceN();
void TampilStok();
void copyrightGengKapak();
void EntryPesanan();
void EntryPaket();
void historyPesanan(int);
int pembayaran(int , int);
int hitungTotal (int, int);
void wegotHistory();
// ----------------------------------



int main(){
	int opsi;
	
	printf("=============================================================\n");
	printf("===================== Barbershop Service ====================\n");
	printf("=============================================================\n\n");
	
	printf("\n[1]. Masukan Pesanan Pelanggan\n");
	printf("[2]. Riwayat Penjualan\n");
	printf("[3]. Lihat Stok Persediaan (Tersorting)\n");
	printf("\n\nPilih Opsi [1/2/3] : ");
	scanf("%d", &opsi);
	
	if(opsi == 1){
		copyrightGengKapak();
		system("cls");
		
		
		printf("\n");
		EntryPesanan();
	}
	if(opsi == 2){
		system("cls");
		wegotHistory();
	}
	if(opsi == 3){
		system("cls");
		printf("Data telah disorting berdasarkan Stok paling sedikit\n\n");
    	
		TampilStok();
	}
	copyrightGengKapak();
}



float hitungTotal (int jumlah_custom, int arr[]){
	float total = 0;
	int set = 0;
	while(set < jumlah_custom){
		for(int i = 0; i < (sizeof(menujenis)/sizeof(menujenis[0])); i++){
			if(arr[set] == menujenis[i].id_jenis){
				total += menujenis[i].hargalay;
				set++;
			}
		}
	}
	return total;	
}

void Sorting(){
	
}

void tampilkan_pencarian(int cariwoi){
	for(int i = 0; i < 100; i++){
			if(cariwoi == bundling[i].id_nama){
				printf("\nPaket \t: %s\nLayanan : %s\n===== Total : Rp.%.3f ===== \n", bundling[i].nama, bundling[i].isi, bundling[i].hargabundling);
			} 
		}
}

int cari_bundling(int nyari_id){
		for(int i = 0; i < 10; i++){
			if(nyari_id == bundling[i].id_nama){
				return nyari_id;
			} 
		}
		return -1;
}

void carilagi(){
	
}

void EntryPesanan(){
	long int uang;
	int pilih_paket;
	int milih;
	
	History = fopen("riwayatpesanan.txt", "r+");
	
	printf("---------------------- Enter Customer Data ---------------------\n");
	printf("\nTransaction date (dd/mm/yy) : ");
	scanf("%d/%d/%d", &masukin_pesanan[idx].tanggal, &masukin_pesanan[idx].bulan, &masukin_pesanan[idx].tahun);
	getchar();
	
	while((masukin_pesanan[idx].tanggal > 31 || masukin_pesanan[idx].tanggal < 1) || (masukin_pesanan[idx].bulan > 12 || masukin_pesanan[idx].bulan < 1) || (masukin_pesanan[idx].tahun < 2020)){
		masukin_pesanan[idx].tanggal = 0, masukin_pesanan[idx].bulan = 0, masukin_pesanan[idx].tahun = 0;
		printf("\nTanggal Tidak Valid\n");
		printf("Transaction date (dd/mm/yy) : ");
		scanf("%d/%d/%d", &masukin_pesanan[idx].tanggal, &masukin_pesanan[idx].bulan, &masukin_pesanan[idx].tahun);
		getchar();
	}
	
	printf("\nCustomer name \t: ");
	scanf("%[^\n]", &masukin_pesanan[idx].customer_name);
	getchar();
	printf("\nCustomer : %s, Tanggal : %d - %d - %d\n", masukin_pesanan[idx].customer_name, masukin_pesanan[idx].tanggal, masukin_pesanan[idx].bulan, masukin_pesanan[idx].tahun);
	
	printf("\n(1) Bundle or (2) Custom : ");
	scanf("%d", &milih);
	getchar();
	if(milih == 1){
		system("cls");
		printf("     <<<<< Service Paket/Bundling >>>>>\n\n");
		TampilServiceN();
		EntryPaket();
	
		} else if (milih == 2){
		system("cls");	
		printf("     <<<<< Service Biasa/Custom >>>>>\n");
		TampilServiceJ();
		int jumlah_custom;
		copyrightGengKapak();
		printf("\n\nJumlah yang akah dipilih : ");
		scanf("%d", &jumlah_custom);
		getchar();
		int arr[jumlah_custom];
		
		for(int i = 0; i < jumlah_custom; i++){
			printf("\nPilih (Id) Layanan Ke-[%d] dari %d : ", i+1, jumlah_custom);
			scanf("%d", &arr[i]);
			getchar();
			for(int j = 0; j < 15; j++){
				if(arr[i] == menujenis[j].id_jenis){
					printf("________________________________\n%d. %s, Rp.%.3f\n________________________________", i+1, menujenis[j].jenislay, menujenis[j].hargalay);
				}
			}
		}
		printf("\n============ Total : Rp.%.3f =================\n\n", hitungTotal(jumlah_custom, arr));
		printf("Pembelian Berhasil :))");
		
	}
}

void copyrightGengKapak(){
	printf("\n---------------- Copyright by @Geng Kapak 2023 ---------------\n");
}

void EntryPaket(){
	int pilih_paket, uang;
	printf("\nPilih Id Paket : ");
	scanf("%d", &pilih_paket);
	getchar();
		
	cari_bundling(pilih_paket);
		
	while(cari_bundling(pilih_paket) == -1){
		printf("\nPaket / ID Tidak Ditemukan!\n");
		printf("\nPilih Id Paket : ");
		scanf("%d", &pilih_paket);
		getchar();
		cari_bundling(pilih_paket);
	}
	tampilkan_pencarian(cari_bundling(pilih_paket));
	historyPesanan(pilih_paket);
}

void historyPesanan(int id){
	History = fopen("riwayatpesanan.txt", "+");
	for(int i = 0; i < (sizeof(bundling)/sizeof(bundling[0])); i++){
		if(id == bundling[i].id_nama){
			strcpy(masukin_pesanan[idx].pesanan, bundling[i].nama);
			masukin_pesanan[idx].total_harga = bundling[i].hargabundling;
		}
	}
	for(int i = 0; i <= idx; i++){
			fprintf(History, "%d/%d/%d - Atas Nama : %s, Pesanan : %s, Total : Rp.%.3f\n",
	masukin_pesanan[idx].tanggal, masukin_pesanan[idx].bulan, masukin_pesanan[idx].tahun,
	masukin_pesanan[idx].customer_name, masukin_pesanan[idx].pesanan, masukin_pesanan[idx].total_harga);
	
	}

//	fclose(History);	
		
}

void wegotHistory(){
	History = fopen("riwayatpesanan.txt", "r+");
	
	while(fscanf(History, "%d/%d/%d - Atas Nama : %[^,], Pesanan : %[^,], Total : Rp.%f\r\n",&masukin_pesanan[idx].tanggal, &masukin_pesanan[idx].bulan, &masukin_pesanan[idx].tahun,&masukin_pesanan[idx].customer_name, &masukin_pesanan[idx].pesanan, &masukin_pesanan[idx].total_harga) != EOF){
		
		printf("%d/%d/%d - Atas Nama : %s, Pesanan : %s, Total : Rp.%.3f\n",
	masukin_pesanan[idx].tanggal, masukin_pesanan[idx].bulan, masukin_pesanan[idx].tahun,
	masukin_pesanan[idx].customer_name, masukin_pesanan[idx].pesanan, masukin_pesanan[idx].total_harga);
	idx++;
	}
}

void TampilStok(){
	IStok = fopen("stok.txt", "r+");
		while (fscanf(IStok, "%[^|]|%d\r\n", &iStok[idx].namastok, &iStok[idx].qty) != EOF){
			printf("Qty : %d,\t %s\n", iStok[idx].qty, iStok[idx].namastok);
			idx++;
		}
	
}

void TampilServiceJ(){
	JL = fopen("jenislayanan.txt", "r+");
	while (fscanf(JL, "%d|%[^|]|%f\r\n", &menujenis[idx].id_jenis, &menujenis[idx].jenislay, &menujenis[idx].hargalay) != EOF){
		printf("________________________________\nId \t : %d\nLayanan\t : %s\nHarga \t : Rp.%.3f\n", menujenis[idx].id_jenis, menujenis[idx].jenislay, menujenis[idx].hargalay);
		idx++;
	}
}

void TampilServiceN(){
	NL = fopen("namalayanan.txt", "r+");
	while (fscanf(NL, "%d-%[^-]-%[^-]-%f\r\n", &bundling[idx].id_nama, &bundling[idx].nama, &bundling[idx].isi, &bundling[idx].hargabundling) != EOF){
		printf("________________________________\nId \t : %d\nPaket\t : %s \nLayanan\t : %s \nHarga \t : Rp.%.3f\n", bundling[idx].id_nama, bundling[idx].nama, bundling[idx].isi, bundling[idx].hargabundling);
		idx++;
	}
}
