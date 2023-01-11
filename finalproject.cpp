#include <stdio.h>
/* */
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

void TampilServiceJ();
void TampilServiceN();
void copyrightGengKapak();
void EntryPesanan();

int idx = 0;
FILE *JL;
FILE *NL;
FILE *History;

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
//		functionEntry();
		printf("\nService Biasa\n");
		TampilServiceJ();
		printf("\nService Bundling\n");
		TampilServiceN();
		printf("\n");
//		InputJenisLayananBaru();
		EntryPesanan();
	}
	if(opsi == 2){
//		functionRiwayatPenjualan();
		printf("tes 2");
	}
	copyrightGengKapak();
}




void InputJenisLayananBaru (){
	printf("\n----------------------------------\n");
	JL = fopen("jenislayanan.txt", "r+");
	if(JL == NULL){
		printf("File Tidak Ada!!");
	}
//	struct jenis_layanan layanan;	
	printf("Masukan ID : "); 
	scanf("%d", &menujenis[idx].id_jenis);
	getchar();
//	mengecek apakah ada ID yang sama?
//	for(int i = 0; i <= 100; i++){
//		if(menujenis[idx].id_jenis == menujenis[i].id_jenis){
//			menujenis[i].id_jenis = '\0';
//			printf("ID Sudah ada");
//		}
//	}
	printf("Jenis Layanan : "); 
	scanf("%[^\n]", menujenis[idx].jenislay);
	getchar();
	printf("Harga : "); 
	scanf("%lld", &menujenis[idx].hargalay);
	getchar();
	fprintf(JL, "%d - %s - %d", menujenis[idx].id_jenis, menujenis[idx].jenislay, menujenis[idx].hargalay);
	printf("\nId: %d || Jenis : %s || Harga : Rp.%lld, Berhasil disimpan", menujenis[idx].id_jenis, menujenis[idx].jenislay, menujenis[idx].hargalay);	
	idx++;
	
}

void InputNamaLayanan (){
	char namalay[30];
	int id_jenis;
	int total;
	
	
//	scanf();
//	scanf();
}

int HitungTotalPembayaran (){
	
}

void Sorting(){
	
}

void Searching(){
	
}

void EntryPesanan(){
	int tanggal;
	int bulan;
	int tahun;
	char customer_name[25];
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
		TampilServiceN();
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
		printf("Id : %d. %s - Rp.%d\n", menujenis[idx].id_jenis, menujenis[idx].jenislay, menujenis[idx].hargalay);
		idx++;
	}
}

void TampilServiceN(){
	NL = fopen("namalayanan.txt", "r+");
	while (fscanf(NL, "%d-%[^-]-%[^-]-%d\r\n", &bundling[idx].id_nama, &bundling[idx].nama, &bundling[idx].isi, &bundling[idx].hargabundling) != EOF){
		printf("Id : %d. %s - %s - Rp.%d\n", bundling[idx].id_nama, bundling[idx].nama, bundling[idx].isi, bundling[idx].hargabundling);
		idx++;
	}
}


