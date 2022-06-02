struct dataPeserta {
	char nama[25];
	float komnum, matlis, sisben, ttl, sinsis, alprog, re; //untuk menyimpan nilai
	struct dataPeserta *nextPtr;
};

typedef struct dataPeserta DataPeserta;
typedef DataPeserta *DataPesertaPtr;

void tambahPeserta(char mataKuliah[8][20], DataPesertaPtr *sPtr) { //Menambahkan node ke linked list (Function dengan argumen berupa address ke sebuah structure)
	int i = 0;
	char namaPeserta[25];
	float nilai[7];

	DataPesertaPtr newPtr; /* pointer to new node */
	DataPesertaPtr previousPtr; /* pointer to previous node in list */
	DataPesertaPtr currentPtr; /* pointer to current node in list */

	newPtr = malloc(sizeof(DataPeserta));

	printf(">> Masukkan 0 pada Nama untuk mengakhiri tambah data.\n");

	printf("Nama: ");
	fflush(stdin);
	scanf("%[^\n]s", &namaPeserta);
	fflush(stdin);
	if(namaPeserta[0] == ' ' || namaPeserta[0] == '\n') {
		printf("\n>>Nama tidak sesuai aturan!\n");
	} else if (namaPeserta[0] == '0'){
		return;
	} else {
		if ( newPtr != NULL ) { /* is space available */
			strcpy(newPtr->nama, namaPeserta);
	
			do {
				printf("Nilai %-17s : ", mataKuliah[i]);
				scanf("%f", &nilai[i]);
				fflush(stdin);
				(nilai[i] >= 0 && nilai[i] <= 100)? i++: printf(">> Nilai hanya 0 - 100!\n");
			} while(i < 7);
	
			newPtr->komnum = nilai[0];
			newPtr->matlis = nilai[1];
			newPtr->sisben = nilai[2];
			newPtr->ttl = nilai[3];
			newPtr->sinsis = nilai[4];
			newPtr->alprog = nilai[5];
			newPtr->re = nilai[6];
	
			newPtr->nextPtr = NULL;
	
			previousPtr = NULL;
			currentPtr = *sPtr;
	
			/* loop to find the correct location in the list */
			while ( currentPtr != NULL && (strcmp(namaPeserta, currentPtr->nama) > 0)) {
				previousPtr = currentPtr; /* walk to ... */
				currentPtr = currentPtr->nextPtr; /* ... next node */
			} /* end while */
			/* insert newPtr at beginning of list */
			if ( previousPtr == NULL ) {
				newPtr->nextPtr = *sPtr;
				*sPtr = newPtr;
			} else { /* insert newPtr between previousPtr and currentPtr */
				previousPtr->nextPtr = newPtr;
				newPtr->nextPtr = currentPtr;
			} /* end else */
		} else {
			printf("%s not inserted. No memory available.\n", namaPeserta);
		}
	}
	printf("\n");
	tambahPeserta(mataKuliah, sPtr);
}

int hapusPeserta(DataPesertaPtr *sPtr) { //Menghapus node dari linked list
	int i = 0;
	char namaPeserta[25];
	
	printf(">> Masukkan 0 pada Nama untuk membatalkan hapus data.\n");
	
	printf("Nama: ");
	fflush(stdin);
	scanf("%[^\n]s", &namaPeserta);

	DataPesertaPtr previousPtr; /* pointer to previous node in list */
	DataPesertaPtr currentPtr; /* pointer to current node in list */
	DataPesertaPtr tempPtr; /* temporary node pointer */
	
	/* delete first node */
	if ( (strcmp((*sPtr)->nama, namaPeserta) == 0)) {
		tempPtr = *sPtr;
		*sPtr = (*sPtr)->nextPtr; /* de-thread the node */
		free(tempPtr); /* free the de-threaded node */
		return 1;
	} else {
		previousPtr = *sPtr;
		currentPtr = ( *sPtr )->nextPtr;
		
		/* loop to find the correct location in the list */
		while ( currentPtr != NULL && (strcmp(currentPtr->nama, namaPeserta) != 0) ) {
			previousPtr = currentPtr; /* walk to ... */
			currentPtr = currentPtr->nextPtr; /* ... next node */
		}
		/* delete node at currentPtr */
		if (currentPtr != NULL) {
			tempPtr = currentPtr;
			previousPtr->nextPtr = currentPtr->nextPtr;
			free(tempPtr);
			return 1;
		}
	}
	return 0;
}

int isEmpty(DataPesertaPtr sPtr) { //Function dengan argumen berupa structure
	return sPtr == NULL;
}
