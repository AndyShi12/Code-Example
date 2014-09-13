// Loading and Saving File
long * Load_File(char *Filename, int *Size);
int Save_File(char *Filename, long *Array, int Size);

// Shell and Insertion Sort
void Shell_Insertion_Sort(long *Array, int Size, double *N_Comp, double *N_Move);
void Shell_Selection_Sort(long *Array, int Size, double *N_Comp, double *N_Move);

// Print Sequence
int Print_Seq(char *Filename, int Size);

//void readFile(char *filename, int *size);
int pwr(int base, int exp);
void findSeq(int seqSize, int * sequence);
//sint sizeofSeq(int *sizeofArray);
