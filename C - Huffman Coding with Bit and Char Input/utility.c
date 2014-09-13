#include "pa09.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/*************************************************
 * Printing Output to a File
 *
 *************************************************/
void Huff_postOrderPrintFile(HuffNode *tree, FILE * file)
{
  if (tree == NULL) 
    return;

  fprintf(file,"Left\n");
  Huff_postOrderPrintFile(tree->left,file);
  fprintf(file,"Back\n");

  fprintf(file,"Right\n");
  Huff_postOrderPrintFile(tree->right,file);
  fprintf(file,"Back\n");

  if (tree->left == NULL && tree->right == NULL) {
    fprintf(file,"Leaf: %c\n",tree->value);
  }    
}

/*************************************************
 * Stack Functions
 *
 *************************************************/
Stack * StackPush(Stack * st, HuffNode * hnode)
{
  Stack * stackMem = malloc(sizeof(Stack));
  stackMem -> node = hnode;
  stackMem -> next = st; 
  return stackMem;
}

Stack * StackPop(Stack * head)
{
  if(head==NULL)
    return NULL;

  Stack * top  = head -> next; 
  free(head);
  return top;
}

/*************************************************
 * Huffman Functions
 *
 ************************************************/

HuffNode * HuffNodeCreate(int val)
{
  HuffNode * hnode = malloc(sizeof(HuffNode));
  hnode -> value = val;
  hnode -> left = NULL;
  hnode -> right = NULL;
  return hnode;
}

void HuffDestroy (HuffNode * array)
{
  if (array == NULL)
    return;

  HuffDestroy(array -> left);
  HuffDestroy(array -> right);
  free(array);
}

/*************************************************
 * Tree Creation
 *
 ************************************************/
// Choose Char vs Bit Tree
HuffNode * CreateTree(FILE * file, char * fn)
{
  if(strstr(fn,"bit")==NULL)
    return createCharTree(file);
  else
    return createBitTree(file);
}

// Create a tree using a char input file
HuffNode * createCharTree(FILE * file)
{
  Stack * stackMem = NULL;
  char cmdBit;

  while((cmdBit=fgetc(file))!='\0')
    {
      if(cmdBit=='1') 
	{
	  cmdBit=fgetc(file);
	  HuffNode * leaf = HuffNodeCreate(cmdBit);
	  stackMem = StackPush(stackMem,leaf);
	}
      else 
	{
	  if(stackMem -> next==NULL)
            {
	      HuffNode * output = stackMem->node;
	      free(stackMem);
	      return output;
            }
	
	  HuffNode * BranchNode = HuffNodeCreate(0);
	  BranchNode -> right = stackMem-> node; 
	  BranchNode -> left = stackMem-> next -> node;
	  stackMem = StackPop(stackMem); 
	  stackMem = StackPop(stackMem); 
	  stackMem = StackPush(stackMem, BranchNode);
	  cmdBit++;
	}
    }
  return NULL; 
}

// Create a tree using a bit input file
HuffNode * createBitTree(FILE * file)
{
  Stack * stackMem = NULL;
  uint8_t leftBit = fgetc(file);
  uint8_t rightBit = 0;
  uint8_t currentBit = 0;
  uint8_t check = 0;
  uint8_t value = 0;
  int loc = 0;

  for(;;)    
    {
      check = leftBit >> (8-(loc+1));
      check = check % 2;
      if(check==1) 
	{
	  rightBit=fgetc(file);
	  currentBit = ((leftBit << (loc+1)) + (rightBit >> (7-loc))); //bit shift
	  HuffNode * leaf = HuffNodeCreate(currentBit);
	  stackMem = StackPush(stackMem,leaf);
	  leftBit = rightBit;
	}
      else 
	{
	  if(stackMem->next==NULL)
	    {
	      HuffNode * output = stackMem->node;
	      free(stackMem);
	      return output;
	    }
	  HuffNode * BranchNode = HuffNodeCreate(value); //create branch 
	  BranchNode -> right = stackMem-> node; // insert right node
	  BranchNode -> left = stackMem->next->node; // insert left node
	  stackMem = StackPop(stackMem); // free stack memory
	  stackMem = StackPop(stackMem); // free stack memory
	  stackMem = StackPush(stackMem, BranchNode); // push to tree                   
	}
      loc = (loc+1) % 8;
      if(loc==0)
	leftBit = fgetc(file);
    }
  return NULL;
}
     
