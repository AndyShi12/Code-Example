#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

typedef struct _stack {
    struct _stack * next;
    HuffNode * node;
} Stack;

void HuffDestroy (HuffNode * array);
void Huff_postOrderPrintFile(HuffNode *tree, FILE * file);
int stackRemain (Stack *st);

Stack * StackPush(Stack * st, HuffNode * hnode);
Stack * StackPop(Stack * head);
HuffNode * HuffNodeCreate(int value);
HuffNode * Read_ch(FILE * fptr);
HuffNode * CreateTree(FILE * file, char * fn);
HuffNode * createCharTree(FILE * file);
HuffNode * createBitTree(FILE * file);
HuffNode * CreateHuffTreeFromBitFile(FILE * file);