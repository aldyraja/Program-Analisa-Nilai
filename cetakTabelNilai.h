void cetakTabelNilai(char mataKuliah[8][20], DataPesertaPtr *sPtr) {
	int i = 0, j = 0;
	float sum = 0;

	DataPesertaPtr previousPtr; /* pointer to previous node in list */
	DataPesertaPtr currentPtr; /* pointer to current node in list */

	printf("%4s %-26s ", "No", " ");
	for(i = 0; i < 7; i++) {
		printf("%20s ", mataKuliah[i]);
	}
	printf("%20s\n", "Mean");

	previousPtr = NULL;
	currentPtr = *sPtr;
	i = 0;

	while ( currentPtr != NULL) {
		printf("\n%4d %-26s ", (++i), currentPtr->nama);
		sum = (currentPtr->komnum + currentPtr->matlis + currentPtr->sisben + currentPtr->ttl + currentPtr->sinsis + currentPtr->alprog + currentPtr->re);
		printf("%20.2f %20.2f %20.2f %20.2f %20.2f %20.2f %20.2f %20.2f", currentPtr->komnum, currentPtr->matlis, currentPtr->sisben, currentPtr->ttl, currentPtr->sinsis, currentPtr->alprog, currentPtr->re, sum/7);
		previousPtr = currentPtr; /* walk to ... */
		currentPtr = currentPtr->nextPtr; /* ... next node */
	}
	
	printf("\n%31s ", "=  =  =  Mean  =  =  =");

	sum = 0;
	previousPtr = NULL;
	currentPtr = *sPtr;
	i = 0;
	while(currentPtr != NULL) {
		sum += currentPtr->komnum;
		previousPtr = currentPtr; /* walk to ... */
		currentPtr = currentPtr->nextPtr; /* ... next node */
		i++;
	}
	printf("%20.2f ", (sum / i));

	sum = 0;
	previousPtr = NULL;
	currentPtr = *sPtr;
	i = 0;
	while(currentPtr != NULL) {
		sum += currentPtr->matlis;
		previousPtr = currentPtr; /* walk to ... */
		currentPtr = currentPtr->nextPtr; /* ... next node */
		i++;
	}
	printf("%20.2f ", (sum / i));

	sum = 0;
	previousPtr = NULL;
	currentPtr = *sPtr;
	i = 0;
	while(currentPtr != NULL) {
		sum += currentPtr->sisben;
		previousPtr = currentPtr; /* walk to ... */
		currentPtr = currentPtr->nextPtr; /* ... next node */
		i++;
	}
	printf("%20.2f ", (sum / i));

	sum = 0;
	previousPtr = NULL;
	currentPtr = *sPtr;
	i = 0;
	while(currentPtr != NULL) {
		sum += currentPtr->ttl;
		previousPtr = currentPtr; /* walk to ... */
		currentPtr = currentPtr->nextPtr; /* ... next node */
		i++;
	}
	printf("%20.2f ", (sum / i));

	sum = 0;
	previousPtr = NULL;
	currentPtr = *sPtr;
	i = 0;
	while(currentPtr != NULL) {
		sum += currentPtr->sinsis;
		previousPtr = currentPtr; /* walk to ... */
		currentPtr = currentPtr->nextPtr; /* ... next node */
		i++;
	}
	printf("%20.2f ", (sum / i));

	sum = 0;
	previousPtr = NULL;
	currentPtr = *sPtr;
	i = 0;
	while(currentPtr != NULL) {
		sum += currentPtr->alprog;
		previousPtr = currentPtr; /* walk to ... */
		currentPtr = currentPtr->nextPtr; /* ... next node */
		i++;
	}
	printf("%20.2f ", (sum / i));

	sum = 0;
	previousPtr = NULL;
	currentPtr = *sPtr;
	i = 0;
	while(currentPtr != NULL) {
		sum += currentPtr->re;
		previousPtr = currentPtr; /* walk to ... */
		currentPtr = currentPtr->nextPtr; /* ... next node */
		i++;
	}
	printf("%20.2f ", (sum / i));

	printf("\n");
}
