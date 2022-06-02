struct treeNode {
	struct treeNode *leftPtr; /* treeNode pointer */
	float data; /* define data as an float */
	struct treeNode *rightPtr; /* treeNode pointer */
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

void urutkanNilaiPelajaran(DataPesertaPtr *sPtr, int indexMapel) {
	int swap, i, j = 0;
	float holdf;
	char holdc[25];
	
	DataPesertaPtr previousPtr; /* pointer to previous node in list */
	DataPesertaPtr currentPtr; /* pointer to current node in list */
	
	do {
		i = 0;
		previousPtr = *sPtr;
		currentPtr = (*sPtr)->nextPtr;
		do {
			swap = 0;
			switch (indexMapel) {
				case 0:	//komnum
					if (previousPtr->komnum > currentPtr->komnum) swap = 1;
					break;
				case 1:	//matlis
					if (previousPtr->matlis > currentPtr->matlis) swap = 1;
					break;
				case 2:	//sisben
					if (previousPtr->sisben > currentPtr->sisben) swap = 1;
					break;
				case 3:	//ttl
					if (previousPtr->ttl > currentPtr->ttl) swap = 1;
					break;
				case 4:	//sinsis
					if (previousPtr->sinsis > currentPtr->sinsis) swap = 1;
					break;
				case 5:	//alprog
					if (previousPtr->alprog > currentPtr->alprog) swap = 1;
					break;
				case 6:	//re
					if (previousPtr->re > currentPtr->re) swap = 1;
					break;
				default:
					break;
			}

			if(swap) {
				strcpy(holdc, previousPtr->nama);
				strcpy(previousPtr->nama, currentPtr->nama);
				strcpy(currentPtr->nama, holdc);

				holdf = previousPtr->komnum;
				previousPtr->komnum = currentPtr->komnum;
				currentPtr->komnum = holdf;

				holdf = previousPtr->matlis;
				previousPtr->matlis = currentPtr->matlis;
				currentPtr->matlis = holdf;

				holdf = previousPtr->sisben;
				previousPtr->sisben = currentPtr->sisben;
				currentPtr->sisben = holdf;

				holdf = previousPtr->ttl;
				previousPtr->ttl = currentPtr->ttl;
				currentPtr->ttl = holdf;

				holdf = previousPtr->sinsis;
				previousPtr->sinsis = currentPtr->sinsis;
				currentPtr->sinsis = holdf;

				holdf = previousPtr->alprog;
				previousPtr->alprog = currentPtr->alprog;
				currentPtr->alprog = holdf;

				holdf = previousPtr->re;
				previousPtr->re = currentPtr->re;
				currentPtr->re = holdf;
			}
			previousPtr = currentPtr; /* walk to ... */
			currentPtr = currentPtr->nextPtr; /* ... next node */
			i++;
		} while(currentPtr != NULL);
		j++;	
	} while(j < i);
}


/* begin inorder traversal of tree */
void inOrder( TreeNodePtr treePtr ) {
	/* if tree is not empty then traverse */
	if ( treePtr != NULL ) {
		inOrder( treePtr->leftPtr );
		printf( "%.2f\t", treePtr->data );
		inOrder( treePtr->rightPtr );
	}
}

/* insert node into tree */
void insertNode( TreeNodePtr *treePtr, float value ) {
	/* if tree is empty */
	if ( *treePtr == NULL ) {
		*treePtr = malloc( sizeof( TreeNode ) );
		/* if memory was allocated then assign data */
		if ( *treePtr != NULL ) {
			(*treePtr)->data = value;
			(*treePtr)->leftPtr = NULL;
			(*treePtr)->rightPtr = NULL;
		} else {
			printf( "%f not inserted. No memory available.\n", value);
		}
	} else { /* tree is not empty */
		/* data to insert is less than data in current node */
		if ( value < (*treePtr)->data) {
			insertNode( &((*treePtr)->leftPtr ), value);
		} else if ( value > (*treePtr)->data ) { /* data to insert is greater than data in current node */
			insertNode( &((*treePtr)->rightPtr ), value);
		}
	}
}

void createBinaryTree(TreeNodePtr *treePtr, DataPesertaPtr *sPtr, int indexMapel) {
	
	DataPesertaPtr previousPtr; /* pointer to previous node in list */
	DataPesertaPtr currentPtr; /* pointer to current node in list */
	
	previousPtr = NULL;
	currentPtr = *sPtr;

	do {
		switch (indexMapel) {
			case 0:
				insertNode(treePtr, currentPtr->komnum);
				break;
			case 1:
				insertNode(treePtr, currentPtr->matlis);
				break;
			case 2:
				insertNode(treePtr, currentPtr->sisben);
				break;
			case 3:
				insertNode(treePtr, currentPtr->ttl);
				break;
			case 4:
				insertNode(treePtr, currentPtr->sinsis);
				break;
			case 5:
				insertNode(treePtr, currentPtr->alprog);
				break;
			case 6:
				insertNode(treePtr, currentPtr->re);
				break;
			default:
				break;
		}
		previousPtr = currentPtr; /* walk to ... */
		currentPtr = currentPtr->nextPtr; /* ... next node */
	} while(currentPtr != NULL);
	inOrder(*treePtr);
}
