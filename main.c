#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ubahPeserta.h"
#include "cetakTabelNilai.h"
#include "urutkanNilaiPelajaran.h"
#include "cariNilai.h"

int menu(char mataKuliah[8][20]);	//Mencetak pilihan dan me-return input (Function dengan argumen berupa array)
void keluar(int *konfirmasi);		//Konfirmasi keluar program (Function dengan argumen berupa address)

//struct dataPeserta di library ubahPeserta.h

int main(void) {
	int i = 1;
	int input;
	char jawaban;
	float key;
	char mataKuliah[8][20] = {"Komputasi Numerik", "Material Listrik", "Sistem Benam 1", "Teknik T. Listrik",
							"Sinyal dan Sistem", "Algoritma dan P.", "R. Elektronika 1"};
	
	//Inisialisasi Linked List
	DataPesertaPtr startPtr = NULL;
	TreeNodePtr rootPtr = NULL;

	//Penjelasan program
	printf("SELAMAT DATANG DI PROGRAM ANALISA NILAI\n\n");
	printf("Program  ini  bertujuan  untuk   membantu   pengajar   dalam   menganalisa  nilai  ujian  peserta.\n\n");
	printf("Pada program  ini user  akan memberikan  input nama  dan nilai  peserta pada  mata kuliah terkait,\n");
	printf("setelah itu  data  akan diurutkan oleh  program dan user  dapat menerima output  berupa nilai yang\n");
	printf("telah diurutkan, peserta  dengan nilai tertinggi  dan terendah, rata-rata  nilai ujian,  rata-rata\n");
	printf("nilai keseluruhan mata kuliah dari satu peserta, dan user.  dapat mencari siapakah yang memperoleh\n");
	printf("nilai tertentu  pada  salah satu  mata kuliah.\n\n");
	
	system("pause");
	
	do {
		do {
			system("cls");
			printf("TAHAP PENGINPUTAN DATA\n\n");
			switch(i) {
				case 0:
					printf("1. Tambah Peserta\n");
					printf("2. Hapus Peserta\n");
					scanf("%d", &i);
					fflush(stdin);
					if(!(i == 1 || i == 2)) i = 3;
					continue;
				case 1:
					tambahPeserta(mataKuliah, &startPtr);
					printf( "\n>>Data berhasil ditambahkan!\n");
					system("pause");
					break;
				case 2:
					/* if list is not empty */
					if (!isEmpty(startPtr)) {
						if (hapusPeserta(&startPtr)) {
							printf( "\n>>Data berhasil dihapus!\n");
							system("pause");
						} else {
							printf("\n>>Data tidak ditemukan!\n\n");
							system("pause");
						}
					} else {
						printf("\n>>Tidak ada data yang tersimpan!\n\n");
						system("pause");
					}
					break;
				case 3:
					printf("\n>>Nilai tidak diubah.\n");
					system("pause");
					break;
				default:
					break;
			}
			system("cls");
			printf("DATA TERINPUT DALAM PROGRAM\n\n");
			cetakTabelNilai(mataKuliah, &startPtr);
			
			do {
				printf("\n>>Ubah data? [y/n]");
				fflush(stdin);
				scanf("%c", &jawaban);
				fflush(stdin);
				if(!(jawaban == 'y' || jawaban == 'Y' || jawaban == 'n' || jawaban == 'N')) {
					printf("\n>>pilih jawaban yang sesuai!");
				}
			} while (!(jawaban == 'y' || jawaban == 'Y' || jawaban == 'n' || jawaban == 'N'));
			i = 0;
		} while(jawaban == 'y' || jawaban == 'Y');
		
		printf("\n>> Pilih Mata Kuliah yang nilainya ingin dicari.");
		printf("\n");
		input = menu(mataKuliah);
		printf("\n");
		printf("Masukkan nilai yang ingin dicari: ");
		scanf("%f", &key);
		fflush(stdin);		
		printf("\n>> in-order traversal of tree: ");
		rootPtr = NULL;
		createBinaryTree(&rootPtr, &startPtr, (input-1));
		i = binarySearch(&rootPtr, key);
		if(i) {
			printf("\n\nNilai tersebut dimiliki oleh:\n");
			cetakHasilPencarian(startPtr, (input-1), key);
		}
		printf("\n\n");
		
		printf("\n>> Pilih Mata Kuliah yang ingin diurutkan.");
		printf("\n");
		input = menu(mataKuliah);
		printf("\n");
		urutkanNilaiPelajaran(&startPtr, (input-1));
		cetakTabelNilai(mataKuliah, &startPtr);
		printf("\n>> Seluruh data telah disusun menurut nilai Mata Kuliah %s !\n\n", mataKuliah[input-1]);
		system("pause");
		keluar(&i);
	} while (i);
	system("pause");
	return 0;
}

int menu(char mataKuliah[8][20]) {
	int i;
	int input;
	do {
		for(i = 0; i < 7; i++) printf("%d %s\n", (i+1), mataKuliah[i]);
		printf("Masukkan Pilihan: ");
		scanf("%d", &input);
		fflush(stdin);
		if(input < 1 || input > 7 ) printf("\n>>Pilih jawaban yang sesuai!\n\n");
	} while(input < 1 || input > 7 );
	return input;
}

void keluar(int *konfirmasi) {
	char jawaban;
		while (1) {
		printf("\nprogram akan ditutup, yakin ingin keluar? [y/n]");
		scanf("%c", &jawaban);
		fflush(stdin);
		if(jawaban == 'y' || jawaban == 'Y') {
			*konfirmasi = 0;
			break;
		} else if(jawaban == 'n' || jawaban == 'N') {
			*konfirmasi = 4;
			break;
		} else {
			printf("\n>>pilih jawaban yang sesuai!");
		}
	}
}
