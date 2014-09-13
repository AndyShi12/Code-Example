#include "huffman.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include "tree.c"

int main (int argc , char ** argv)
{
  if (argc != 3)
    {
      printf("Invalid usage: ./pa09 <input of compressed> <output for uncompressed>\n");
      return EXIT_FAILURE;
    }

// Read Input  
  FILE * fptr = NULL;
  fptr = fopen(argv[1], "r");
  if (fptr == NULL)
    {
      printf("File error!\n");
      return EXIT_FAILURE;
    }

// Create Huffman Tree
HuffNode * Huffman_tree = CreateTree(fptr, argv[1]);
fclose(fptr);

// Write File to Text
fptr = fopen(argv[2], "w");
Huff_postOrderPrintFile(Huffman_tree, fptr);

fclose(fptr);

// Free Memory
HuffDestroy (Huffman_tree);

return EXIT_SUCCESS;
}
