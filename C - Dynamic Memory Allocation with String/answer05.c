#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pa05.h"

/*
 * Read a file of integers.
 *
 * Arguments:
 *
 * filename: the name of a file that contains a list of integers (one
 * per line)
 * 
 * numInteger: pointer to store the number of integers in the
 * file. You need to update the value stored at the address which is
 * the pointer's value.  If the function fails to update the value, it
 * is considered reading the file has failed.
 *
 * Returns:
 *
 * a array of integers from the file, or NULL if *any* error is
 * encountered.
 *
 * Hint: use fscanf
 *
 * You do NOT know how many integers are in the file until you have
 * read it. Once you know how many integers there are, you can modify
 * the "numberOfIntegers" variable. (Note that this is a pointer, not
 * an integer) You must allocate memory to store the integers.
 * 
 * Once memory is allocated to store the integers, you will need to
 * re-read the values from the file. To do this, you must reset the
 * file pointer to the beginning of the file using the function
 * "fseek". 
 *
 * You should not use rewind (if you have learned it somewhere).  The
 * difference of rewind and fseek is that rewind does not tell you
 * whether it fails.  
 *
 * One way to read integeres is to use the "fscanf" function.  It is
 * easier than reading one character at a time by using fgetc.
 *
 * You must use malloc in this function.
 * 
 * Some old books encourage readers to type cast in front of malloc,
 * something like
 *
 * int * ptr = (int *) malloc(sizeof(int) * size);
 *
 * Type cast is no longer needed and in fact is discouraged now.  You
 * should *NOT* type cast malloc.  It is discouraged even though it is
 * not wrong.
 *
 * You will receive zero if you allocate a large array whose size is
 * independent of the number of integers in the file.  For example, if
 * you write this
 *
 * int array[10000];
 * 
 *
 */

int * readInteger(char * filename, int * numInteger)
{
  FILE * fp = fopen(filename, "r");
  int n;
  int * array;
  
  // read number of array elements	
  if (fp == NULL)
    return NULL;
  else
    {
      while(!feof(fp)){
	if(fscanf(fp, "%d", &n))
	  (*numInteger)++;
      }
      *numInteger-=1;
      
      // create memory stack
      array = malloc(sizeof(int)* *numInteger);
  
      // goto beginning of file and fill in array
      fseek(fp, 0, SEEK_SET);
      n = 0;
      while(!feof(fp))
	{
	  fscanf(fp, "%d", &array[n]);
	  n++;
	}
      // close file pointer and return array 
      fclose(fp);
      return array;
    }
}

/* ----------------------------------------------- */

/*
 * Read a file of strings. This is similar to readInteger. However,
 * each string is an array of characters. The function needs to
 * allocate memory for an array of strings, i.e., array of arrays of
 * characters. In other words, this is a two-dimensional array (thus,
 * char **).
 *
 * Arguments:
 *
 * filename: the name of a file that contains a list of strings (one
 * per line)
 * 
 * numString: pointer to store the number of strings in the
 * file. You need to update the value stored at the address which is
 * the pointer's value.  If the function fails to update the value, it
 * is considered reading the file has failed.
 *
 * Returns:
 *
 * a array of strings from the file, or NULL if *any* error is
 * encountered.
 *
 * Hint: use fgets. 
 * 
 * Remember that an array of strings is a two-dimensional array of
 * characters
 *
 * You do NOT know how many strings are in the file until you have
 * read it. Once you know how many strings there are, you can modify
 * the "numberOfStrings" variable. (Note that this is a pointer, not
 * an string) You must allocate memory to store the strings.
 * 
 * Once memory is allocated to store the strings, you will need to
 * re-read the values from the file. To do this, you must reset the
 * file pointer to the beginning of the file using the function
 * "fseek". 
 *
 * You should not use rewind (if you have learned it somewhere).  The
 * difference of rewind and fseek is that rewind does not tell you
 * whether it fails.  
 *
 * One way to read stringes is to use the "fscanf" function.  It is
 * easier than reading one character at a time by using fgetc.
 *
 * You must use malloc in this function.
 * 
 * Some old books encourage readers to type cast in front of malloc,
 * something like
 *
 * int * ptr = (int *) malloc(sizeof(int) * size);
 *
 * Type cast is no longer needed and in fact is discouraged now.  You
 * should *NOT* type cast malloc.  It is discouraged even though it is
 * not wrong.
 *
 * You will receive zero if you allocate a large array whose size is
 * independent of the number of strings in the file.  For example, if
 * you write this
 *
 * char array[10000];
 * 
 *
 */

char * * readString(char * filename, int * numString)
{
  FILE * fp = fopen(filename, "r");
  int count = 0;
  char ** ptr;
  char buf[MAXIMUM_LENGTH];

  // count number of lines   
  while (fgets(buf,MAXIMUM_LENGTH,fp) !=NULL)
    count++;
  
  // allocate memory of string
  *numString = count;
  ptr = malloc(sizeof(char*) * *numString);
 
  for (count = 0; count < *numString; count++)
    ptr[count] = malloc(sizeof(char) * MAXIMUM_LENGTH);
  fseek(fp, 0, SEEK_SET);
  
  for (count = 0; count < *numString; count++)
    fgets(ptr[count], MAXIMUM_LENGTH, fp);
  fclose(fp);

  return ptr;
}

/* ----------------------------------------------- */
/*
 * print an array of integers, one integer per line
 */
void printInteger(int * arrInteger, int numInteger)
{
  int n = 0;
  for (n=0; n<numInteger; n++)
    {
      printf("%d\n", arrInteger[n]);
    }
}

/* ----------------------------------------------- */
/*
 * print an array of strings, one string per line
 *
 * Hint: printf("%s" ... can print a string
 */
void printString(char * * arrString, int numString)
{
  int n = 0;

  for (n=0; n<numString; n++)
    {
      printf("%s", arrString[n]);
    }
}

/* ----------------------------------------------- */
/*
 * release the memory occupied by the array of integers
 */
void freeInteger(int * arrInteger, int numInteger)
{
  free(arrInteger);
}

/* ----------------------------------------------- */
/*
 * release the memory occupied by the array of strings
 *
 * Hint: an array of strings is a two-dimensional array of characters
 */
void freeString(char ** arrString, int numString)
{
  int n = 0;

  for (n=0; n<numString; n++)
    {
      free(arrString[n]);
    }
  free(arrString);
}

/* ----------------------------------------------- */
/*
 * Write integers to a file, one integer per line
 *
 * Arguments:
 *
 * filename: the name of a file.
 * arrInteger: an array of integers
 * numInteger: the number of integers 
 *
 * Returns:
 * 1 if saving to the file successfully
 * 0 if *any* error is encountered
 *
 * Hint: use fprintf(... %d
 *
 */

int saveInteger(char * filename, int * arrInteger, int numInteger)
{
  int n;
  FILE * fp;
  fp = fopen(filename, "w");

  if (fp == NULL)
    return 0;
  else
    {
      for (n=0; n<numInteger;n++)
	{
	  fprintf(fp,"%d\n",arrInteger[n]);
	}
      fclose(fp);
      return 1;
    }
}

/* ----------------------------------------------- */
/*
 * Write strings to a file, one string per line
 *
 * Arguments:
 *
 * filename: the name of a file.
 * arrString: an array of strings
 * numString: the number of strings 
 *
 * Returns:
 * 1 if saving to the file successfully
 * 0 if *any* error is encountered
 *
 * Hint: use fprintf(... %s
 *
 */

int saveString(char * filename, char * * arrString, int numString)
{
  int n;
  FILE * fp;
  fp = fopen(filename, "w");

  if (fp == NULL)
    return 0;
  else
    {
      for (n=0; n<numString;n++)
	{
	  fprintf(fp,"%s\n",arrString[n]);
	}
      fclose(fp);
      return 1;
    }
}

/* ----------------------------------------------- */
/*
 * sort an arry of integers by calling the built-in qsort function in
 * the C library.  You need to provide the comparison function. Please
 * read the Linux manual about qsort
 *
 */

int compInt(const void * a, const void * b)
{
  int * p1 = (int *) a;
  int * p2 = (int *) b;
  int num1 = * p1;
  int num2 = * p2;

  if (num1==num2)
    return 0;
  else
    if (num1 < num2)
      return -1;
    else
      return 1;
}


void sortInteger(int * arrInteger, int numInteger)
{
  qsort(arrInteger, numInteger, sizeof(int), compInt); 
}

/* ----------------------------------------------- */
/*
 * sort an arry of strings by calling the built-in qsort function in
 * the C library.  You need to provide the comparison function. Please
 * read the Linux manual about qsort
 *
 * Hint: use strcmp in the comparison function
 *
 */

int compstr(const void *p1, const void *p2)
{
  // strcmp was taken from the linux source code website
  return strcmp(* (char * const *) p1, * (char * const *) p2);
}


void sortString(char * * arrString, int numString)
{
  qsort(arrString, numString, sizeof(char*), compstr);
}


