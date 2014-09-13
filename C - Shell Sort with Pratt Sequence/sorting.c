#include "proj1.h"
#include <stdio.h>
#include <stdlib.h>

/* 
*Loads an input file and return an array with values
*/
long * Load_File(char *Filename, int *Size)
{
	long *array = malloc(sizeof(long) * ((*Size) +1));
	int n, success;

    // File checking
	FILE *fptr = fopen(Filename, "r");
    if(!fptr)
    {
        printf("File loading failed: File does not exist.\n");
        return NULL;
    }

    // Write file to array
    for(n = 0; n < (*Size)+1; n++)
    {
        success = fscanf(fptr, "%ld\n", &array[n]);
        if(!success)
        {
                printf("File loading failed: format incorrect.\n");
                fclose(fptr);
                return NULL;
        }
    }
    // Close file pointer
    fclose(fptr);
    return array;
}

/* 
*Write the sorted array to a file
*/
int Save_File(char *Filename, long *Array, int Size)
{
	int n;

    // File checking
	FILE * fptr = fopen(Filename, "w");
	if(!fptr)
    {
        printf("File loading failed: File does not exist.\n");
        return 0;
    }

    // Write the pointer Array to file	
	for (n=0; n<Size; n++)
	{
		fprintf(fptr, "%ld\n", Array[n]);
	}

    // Close file pointer
	fclose(fptr);

return Size;
}


/* 
*   Perform Shell Sort with Insertion Sort Method
*/
void Shell_Insertion_Sort(long *Array, int Size, double *N_Comp, double *N_Move)
{
    // counter variables   
    int n, j;
    // variables
    int index = 0;
    int power = 0;
    int seqSize = 0;
    long temp;

    // find max number in sequence
    while(pwr(3,power)<Size)
        power++;

    // find number of elements in sequence
    for (n= 0; n<power; n++)
        seqSize += (power-n);

    // create k sequence
    int * ksequence = calloc(Size, sizeof(int) * Size);
    findSeq(seqSize, ksequence);

    //outside loop runs ksequence[n]
    for (n=0; n<seqSize; n++)
    {
        // inside loop for Array
        for (index = ksequence[n]; index < Size; index++) 
        {
        // temp variable = array[value] @ index
         temp = Array[index];
            // insertion sort, find greatest value and work backwards
            for (j = index - ksequence[n]; Array[j] > temp && j > 0; j -= ksequence[n]) 
            {
                Array[j + ksequence[n]] = Array[j];
               (*N_Comp)++;
            }
            Array[j + ksequence[n]] = temp;
            (*N_Move)++;
         }
        (*N_Move)++; 
    }
    free (ksequence);
}

/* 
*   Perform Shell Sort with Selection Sort Method
*/
void Shell_Selection_Sort(long *Array, int Size, double *N_Comp, double *N_Move)
{
 // counter variables   
    int n, j;
    // variables
    int index = 0;
    int power = 0;
    int seqSize = 0;
    int indexofMin = 0;
    long longTemp = 0;

    // find max number in sequence
    while(pwr(3,power)<Size)
        power++;

    // find number of elements in sequence
    for (n=0; n<power; n++)
        seqSize += (power-n);

    // create k sequence
    int * ksequence = calloc(Size, sizeof(int) * Size);
    findSeq(seqSize, ksequence);

    //outside loop runs ksequence[n]
    for (n=0; n<seqSize; n++)
    {
        // inside loop for Array
        for (index = ksequence[n]; index < Size; index++) 
        {
        // temp variable = array[value] @ index
         indexofMin = index;
            for (j = index + ksequence[n]; j < Size; j += ksequence[n]) 
            {
                if(Array[indexofMin] > Array[j])
                 {
                    // compare
                    indexofMin = j;
                    (*N_Comp)++;
                 }
            }
            // selection swap
            longTemp = Array[index];
            Array[index] = Array[indexofMin];
            Array[indexofMin] = longTemp;
            (*N_Move)++;
         }
    }
    free (ksequence);

}

/* 
*  Print the p2q3 sequence to file, Size in this case is the size of the sequence
*/
int Print_Seq(char *Filename, int Size)
{
    // initialize variables
    int n;  
    int * sequence = calloc(Size, sizeof(int) * Size);

    // file checking
    FILE *fptr = fopen(Filename, "w");
    if(!fptr)
    {
        printf("File loading failed: File does not exist.\n");
        return 0;
    }
	
    fprintf(fptr, "%d\n", Size);
    findSeq(Size, sequence);

    for(n = 0; n < Size; n++)
    {
    	fprintf(fptr, "%d\n", sequence[n]);
    }

    fclose(fptr);
    free(sequence);
    return Size;
}


/* 
*  Power function in replace of math.h
*/
int pwr(int base, int exp)
{
	int ans = 1;
	int n = 0;
	for (n=0; n<exp; n++)
	{
		ans *= base;
	}
	return ans;
}


/* 
*  Function to generate the p2q3 sequence
*/
void findSeq(int Size, int * sequence)
{
    // counter variable
    int n = 0;
    // p2q3 sequence
    int p = 1;
    int q = 0;

    for(n = 0; n < Size; n += p)
    {
        sequence[n] = pwr(3, q);
        p++;
        q++;
    }
    for(n -= 2; n > 0; n--)
    {
        if(sequence[n] == 0)
        {
            sequence[n] = 2 * (sequence[n + 1] / 3);
        }
    }
}