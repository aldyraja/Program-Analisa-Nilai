int binarySearch(TreeNodePtr *treePtr, float key) {
	
	TreeNodePtr currentPtr; /* pointer to current node in list */
	currentPtr = *treePtr;
	
	do {
		if(currentPtr->data > key) {
			currentPtr = currentPtr->leftPtr;	
		} else if (currentPtr->data < key) {
			currentPtr = currentPtr->rightPtr;
		} else {
			printf("\n>>Data ditemukan!");
			return 1;
		}
	} while(currentPtr != NULL);
	printf("\n>>Data tidak ditemukan!");
	return 0;
}

void cetakHasilPencarian(DataPesertaPtr sPtr, int indexNilai, float key) {
	int i = 0;
	
	DataPesertaPtr previousPtr; /* pointer to previous node in list */
	DataPesertaPtr currentPtr; /* pointer to current node in list */
	
	previousPtr = NULL;
	currentPtr = sPtr;

	do {
		switch (indexNilai) {
			case 0:
				if(currentPtr->komnum == key) printf("%d. %s\n", ++i, currentPtr->nama);
				break;
			case 1:
				if(currentPtr->matlis == key) printf("%d. %s\n", ++i, currentPtr->nama);
				break;
			case 2:
				if(currentPtr->sisben == key) printf("%d. %s\n", ++i, currentPtr->nama);
				break;
			case 3:
				if(currentPtr->ttl == key) printf("%d. %s\n", ++i, currentPtr->nama);
				break;
			case 4:
				if(currentPtr->sinsis == key) printf("%d. %s\n", ++i, currentPtr->nama);
				break;
			case 5:
				if(currentPtr->alprog == key) printf("%d. %s\n", ++i, currentPtr->nama);
				break;
			case 6:
				if(currentPtr->re == key) printf("%d. %s\n", ++i, currentPtr->nama);
				break;
			default:
				break;
		}
		previousPtr = currentPtr; /* walk to ... */
		currentPtr = currentPtr->nextPtr; /* ... next node */
	} while(currentPtr != NULL);
}
