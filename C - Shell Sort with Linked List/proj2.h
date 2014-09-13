typedef struct node {
	long value;
	struct node *next;
} Node;

typedef struct list {
	Node *node;
	struct list *next;
} List;

// Loading and Saving File
Node * Load_File(char *Filename);
Node * nodeConstruct(long n);
Node *Shell_Sort(Node *list);
int Save_File(char *Filename, Node * head);
void destroyNode(Node * head);
void printNode (Node * head);
int countNode(Node * head);
long pwr(int base, int exp);
void findSeq(int size, int * sequence);
//Node * List_delete(Node * head, int index);

// Shell and Insertion Sort
//void Shell_Insertion_Sort(long *Array, int Size, double *N_Comp, double *N_Move);
//////Node * Shell_Sort(Node * list);
//void Shell_Selection_Sort(long *Array, int Size, double *N_Comp, double *N_Move);

// Print Sequence
//////int Print_Seq(char *Filename, int Size);

//void readFile(char *filename, int *size);
//////int pwr(int base, int exp);
//////oid findSeq(int seqSize, int * sequence);
//sint sizeofSeq(int *sizeofArray);

