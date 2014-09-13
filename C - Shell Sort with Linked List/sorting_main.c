#include "proj2.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char * * argv)
{
int * sizeofArray = malloc(sizeof(int));   // size of the array, first line in I/O file
long * array;        // array of numbers following size
int seqSize = 0;     // size of the sequence
int numWritten;      // number of integers written to array
int power = 0;        // power counter
int n;               // loop counter
int success = 0;
double * numCompare = malloc(sizeof(double)); // comparison counter
double * numMove = malloc(sizeof(double));    // move counter
clock_t loadStart;
clock_t loadEnd;
clock_t loadStart2;
clock_t loadEnd2;
clock_t sortStart;
clock_t sortEnd;
*numCompare = 0;
*numMove = 0;

// Check for proper usage
if (argc != 5)
{
  printf("usage: ./proj1 i/s input.txt seq.txt output.txt\n");
  return EXIT_FAILURE;
}

// Open File Pointer
FILE * fptr = fopen(argv[2], "r");
if (!fptr)
{
  printf("Error: File Does Not Exist\n");
  return EXIT_FAILURE;
}

success = fscanf(fptr, "%d", sizeofArray);
if(!success)
{
	printf("read failed\n\n");
	return EXIT_FAILURE;
}


// Read array of numbers and set array
loadStart = clock();
array = Load_File(argv[2], sizeofArray);

fclose(fptr);

// Find maximum Pratt sequence
while(pwr(3,power)<(*sizeofArray))
        power++;

// sequence size, used to generate Pratt sequence
for (n=0; n<power; n++)
{
  seqSize += (power-n);
}
// print sequence
numWritten = Print_Seq(argv[3], seqSize);
loadEnd = clock();

int type = * argv[1];

if(type == 'i')
{
  sortStart = clock();
  Shell_Insertion_Sort(array, *sizeofArray, numCompare, numMove);
  sortEnd = clock();
}
else if(type == 's')
{
  sortStart = clock();
  Shell_Selection_Sort(array, *sizeofArray, numCompare, numMove);
  sortEnd = clock();
}
else
{

printf("Error: Invalid Usage");
return EXIT_FAILURE;
}

// Write to output
loadStart2 = clock();
numWritten = Save_File(argv[4], array, *sizeofArray);
loadEnd2 = clock();

printf("Number of comparisons: %f\n", *numCompare);
printf("Number of moves: %f\n", *numMove);
printf("I/O time: %f\n", ((double) (loadEnd - loadStart) + (double) (loadEnd2 - loadStart2)) / CLOCKS_PER_SEC);
printf("Sorting time: %f\n", ((double) (sortEnd - sortStart)) / CLOCKS_PER_SEC);


free(sizeofArray);
free(numCompare);
free(numMove);
free(array);

numWritten = EXIT_SUCCESS;
return numWritten;
}
