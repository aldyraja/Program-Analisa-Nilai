#include <stdio.h>
#include "inputNilaiPelajaran.h"
#include "cetakTabelNilai.h"
#include "urutkanNilaiPelajaran.h"
#include "cariNilai.h"

int menu(char **opsi);	//Mencetak opsi dan me-return input (Function dengan argumen berupa address)
int keluar(void);		//Konfirmasi keluar program

int main(void) {
	int i, input, temp;
	char *labelX[8];
	char mataKuliah[8][20] = {"Komputasi Numerik", "Material Listrik", "Sistem Benam 1", "Teknik T. Listrik",
								"Sinyal dan Sistem", "Algoritma dan P.", "R. Elektronika 1", '\000'};
	char *labelY[41];
	char namaPeserta[41][25] = {'\000'};
//	char namaPeserta[41][25] = {"Aldy Raja", "Aero Bestari", "Pieter 1", "Raja Aldy", "Bestari Aero", "Pieter 2", "\000"};
	float *xy[41];
	float nilai[41][7] = {0};
//	float nilai[41][7] = {{0, 90, 0, 90, 0, 90, 0}, {7, 6, 5, 4, 3, 2, 1}, {3, 4, 5, 6, 5, 4, 3}, {2, 4, 6, 8, 10, 12, 14}, {-1}};
	float data[41] = {0};
	
	for(i = 0; i < 8; i++) {
		labelX[i] = mataKuliah[i];
	}
	
	for(i = 0; i < 41; i++) {
		labelY[i] = namaPeserta[i];
		xy[i] = nilai[i];
	}
	
	printf("SELAMAT DATANG DI PROGRAM ANALISA NILAI\n\n");
	printf("Program ini bertujuan untuk membantu pengajar dalam menganalisa nilai ujian peserta.\n\n");
	printf("Pada program ini user akan memberikan input nama dan nilai peserta pada mata kuliah terkait,\n");
	printf("setelah itu data akan diurutkan oleh program dan user dapat menerima output berupa nilai yang\n");
	printf("telah diurutkan, jumlah peserta yang lulus, peserta dengan nilai tertinggi dan terendah,\n");
	printf("rata-rata nilai ujian, dan rata-rata nilai keseluruhan mata kuliah dari satu peserta.\n\n");
	
	system("pause");
	system("cls");
	
	
	printf("TAHAP PENGINPUTAN DATA\n\n");
	inputNilaiPelajaran(labelX, labelY, xy, 40);
	printf("\n\n");
	
	do {
		system("cls");
		printf("DATA TERINPUT DALAM PROGRAM\n\n");
		cetakTabelNilai(labelX, labelY, xy);
		system("pause");
		
		printf("\n>> Pilih Mata Kuliah yang ingin diurutkan.");
		printf("\n");
		input = menu(labelX);
		printf("\n");
		urutkanNilaiPelajaran(labelY, 25, xy, 7, (input-1));
		cetakTabelNilai(labelX, labelY, xy);
		printf("\n>> Seluruh data telah disusun menurut nilai Mata Kuliah %s !\n\n", mataKuliah[input-1]);
		system("pause");
		
		printf("\n>> Pilih Mata Kuliah yang nilainya ingin dicari.");
		printf("\n");
		input = menu(labelX);
		printf("\n");
		i = 0;
		do {
			data[i] = nilai[i][input-1];
		} while (namaPeserta[++i][0] != '\000');
		data[i] = -1;
		i = 0;
		printf("Masukkan nilai yang ingin dicari: ");
		cariNilai(data, 40);
		i = 0;
		if(data[i] == -1) printf("data tidak ditemukan");
		while(data[i] != -1) {
			if(i == 0) printf("Nilai tersebut dimiliki oleh: ");
			printf("%s, ", namaPeserta[(int)data[i]]);
			if(namaPeserta[(int)data[i]]=='\000')break;
			i++;
		}
		printf("\n");
		system("pause");
		
		printf("\n>> Pilih Mata Kuliah untuk melihat mahasiswa yang lulus.");
		printf("\n");
		temp = menu(labelX);
		printf("\n");
		urutkanNilaiPelajaran(labelY, 25, xy, 7, (temp-1));
		
		cetakTabelNilai(labelX, labelY, xy);
		i = 0;
		do {
			data[i] = nilai[i][temp-1];
		} while (namaPeserta[++i][0] != '\000');
		data[i] = -1;
		i = 0;
		printf("Masukkan nilai KKM: ");
		input = cariNilai(data, 40);
		i = 0;
		printf("Terdapat %d mahasiswa yang lulus Mata Kuliah %s", input, mataKuliah[temp-1]);
		i = 0;
		while(namaPeserta[i][0] != '\000') i++;
		
		if(input != 0) {
			input = i - input;
			temp = i;
			printf(", yaitu: ");
			for(i = input; i < temp; i++) {
				printf("%s, ", namaPeserta[i]);
			}
		}
		printf("\n");
	} while (keluar());
	
	return 0;
}

int menu(char **opsi) {
	int i = 0;
	int input;
	do {
		printf("%d %s\n", (i+1), opsi[i]);
	} while(opsi[++i][0] != '\000');		//jika opsi berikutnya '\000' maka keluar loop
	printf("Masukkan Pilihan: ");
	scanf("%d", &input);
	return input;
}

int keluar(void) {
	char jawaban;
		while (1) {
		printf("\nprogram akan ditutup, yakin ingin keluar? [Y/n]");
		fflush(stdin);
		scanf("%c", &jawaban);
		if(jawaban == 'y' || jawaban == 'Y') {
			return 0;
		} else if(jawaban == 'n' || jawaban == 'N') {
			return 1;
		} else {
			printf("\n>>pilih jawaban yang sesuai!");
		}
	}
}
