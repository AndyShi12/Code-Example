#include "reroot.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NODE head->stackNode
#define TLEFT tree->left
#define TRIGHT tree->right
#define TSPLIT tree->split

int main(int argc, char * * argv)
{
if (argc != 3)
{
  printf("usage: ./proj4 input output\n");
  return EXIT_FAILURE;
}

int index = 0;
double x = 0, y=0; 

// Build binary tree
stack * root = loadFile(argv[1], &index);
node * head = nodeCreate(root->stackNode->width, root->stackNode->height, root->stackNode->split, root->stackNode->index-1); //= buildTree(root);
root = StackPop(root);
buildTree(root, head, &head, index);
node * tree = NULL;
tree = nodeArrange(tree, &head);

// Packing
clock_t timeStart = clock();
assignCutline(tree);
setCoord(tree);
clock_t timeEnd = clock();
double packTime = (double) (timeEnd - timeStart) / CLOCKS_PER_SEC;
searchNode(tree, &x, &y, 1);
//printPostorderFull(tree);

//Reset output file and save output
FILE * fptr = fopen(argv[2], "w");
saveTree(tree, argv[2]);

// Screen dump
printf("Preorder: ");
printPreorder(tree);
printf("\n\nInorder: ");
printInorder(tree);
printf("\n\nPostorder: ");
printPostorder(tree);
printf("\n\nWidth: %le", tree->width);
printf("\nHeight: %le", tree->height);
printf("\n\nX-coordinate: %le", x);
printf("\nY-coordinate: %le", y); 
printf("\n");

// Rerooting
box * minBox = malloc(sizeof(box));
minBox->width = tree->width;
minBox->height = tree->height;

timeStart = clock();
// ------------------------------------ to run cases without rerooting, comment out the following lines
while (tree->right->split!='-')
{
tree = reroot(tree, minBox);
decideMin(minBox, tree);
//printPostorderFull(tree);
}
// ------------------------------------
timeEnd = clock();
double rootTime = (double) (timeEnd - timeStart) / CLOCKS_PER_SEC;


printf("\nElapsed Time: %le", packTime);
printf("\n\nBest width: %le", minBox->width);
printf("\nBest height: %le\n", minBox->height);
printf("\nElapsed Time for re-routing: %le\n", rootTime);

// Free stack
while(root!=NULL){
  root = StackPop(root);
}

// Memory management
free(root);
free(minBox);
deleteTree(head);
deleteTree(tree);
fclose(fptr);

return EXIT_SUCCESS;
}

/*************************************************
 * Stack Functions
 *
 *  - stackPush, push stack 
 *  - StackPop, pop stack
 *************************************************/
stack * StackPush(stack * st, node * headNode)
{
  stack * stackMem = malloc(sizeof(stack));
  stackMem -> stackNode = headNode;
  stackMem -> next = st;
  return stackMem;
}

stack * StackPop(stack * head)
{
  if(head==NULL)
    return NULL;
  
  free(NODE);
  stack * top  = head -> next; 
  free(head);
  return top;
}

/*************************************************
 * Stack Functions
 *
 *************************************************/
// nodeCreate, create and malloc node
node * nodeCreate(double width, double height, char split, int index)
{
  node * hnode = malloc(sizeof(node));
  hnode -> index = index+1;
  hnode -> width = width;
  hnode -> height = height;
  hnode -> split  = split;
  hnode -> xcoord = 0;
  hnode -> ycoord = 0;
  hnode -> left = NULL;
  hnode -> right = NULL;

  return hnode;
}

// loadFile, load input file into a stack
stack * loadFile(char *Filename, int * n)
{ 
  char split;
  double width, height;
  int success;
  FILE *fptr = fopen(Filename, "r");

  if(!fptr || feof(fptr))
  {
    printf("File loading failed: File does not exist or is empty.\n");
    return NULL;
  }

  stack * stackMem = NULL;
  success = fscanf(fptr, "%lf %c %lf %c", &width, &split, &height, &split);
  if(success){};
  node * leaf;

while(fscanf(fptr, "%c", &split) != EOF)
{
  if (split=='(')
  {
    success = fscanf(fptr, "%lf %c %lf %c", &width, &split, &height, &split);
    leaf = nodeCreate(width,height,'-',*n);
    stackMem = StackPush(stackMem, leaf);
    (*n)++;
  }
  else if (split=='H')
  {
     leaf = nodeCreate(0,0,split,*n);
     stackMem = StackPush(stackMem, leaf);
     (*n)++;
  }
  else if (split=='V')
  {
    leaf = nodeCreate(0,0,split,*n);
    stackMem = StackPush(stackMem, leaf);
    (*n)++;
  }
else
  printf("\n");
}
fclose(fptr);
return stackMem;
}

/*
*  Node Functions
*
*/
// buildTree, build tree from stack
void buildTree(stack * head, node * root, node ** topHead, int n)
{
  if(head==NULL || root == NULL)
  {
    printf("Error, Tree is NULL\n");
    return;
  }
  while(head)
  {
    root -> left = nodeCreate(NODE->width, NODE->height, NODE->split, NODE->index-1);
    root = root -> left;
    head = head->next;
  }
}

// nodeArrange, arrange node into ordered binary tree
node * nodeArrange (node * tree, node ** head)
{
if (*head==NULL)
return tree;

tree = *head;
*head = (*head)->left;

if(TSPLIT!='-') 
{
  if(*head == NULL)
  {
    TLEFT = NULL; 
    TRIGHT = NULL;
  }
  else if((*head)->split=='-')
  {
    TRIGHT = *head;
    *head = (*head)->left;
    TRIGHT->left = NULL;
    TRIGHT->right = NULL;

    if((*head)->split=='-')
    {
       TLEFT = (*head);
      *head = (*head)->left;
       TLEFT->left = NULL;
       TLEFT->right = NULL;
    }
    else
       TLEFT = nodeArrange(TLEFT, head);
  }
  else
  {
     TRIGHT = nodeArrange(TLEFT, head);
     TLEFT = nodeArrange(TLEFT, head);
  }
}
else
{
  TRIGHT = NULL; 
  TLEFT = NULL; 
}
return tree;
}

// Delete binary tree
void deleteTree(node * tree)
{
  if (tree)
  {
      deleteTree(TLEFT);
      deleteTree(TRIGHT);
      free(tree);
  }
}


/*
*  Packing Functions
*
*/

// assignCutline, Assign width/height to cutline nodes
void assignCutline(node * tree)
{
if (tree == NULL) 
return;

double maxX, maxY;

assignCutline(TLEFT);
assignCutline(TRIGHT);
if (tree->split == 'H')
{
    double lw = TLEFT->width; 
    double lh = TLEFT->height; 
    double rw = TRIGHT->width; 
    double rh = TRIGHT->height;

  maxY = (lh+rh);
   if(lw >= rw)
      maxX = lw;
   else
      maxX = rw;

    tree->width = maxX;
    tree->height = maxY;
}
else if (tree->split == 'V')
{
    double lw = TLEFT->width; 
    double lh = TLEFT->height; 
    double rw = TRIGHT->width; 
    double rh = TRIGHT->height; 
    maxX = (lw+rw);
   if(lh >= rh)
      maxY = lh;
   else
      maxY = rh;
    
    tree->width = maxX;
    tree->height = maxY;
}
else {}
}

// setCoord, assign coordinates
void setCoord(node * tree)
{
if(tree==NULL)
  return;

if (tree->split=='H')
{
  TLEFT->xcoord = tree->xcoord;
  TLEFT->ycoord = TRIGHT->height + tree->ycoord;
  TRIGHT->ycoord = tree->ycoord;
  TRIGHT->xcoord = tree->xcoord;
}
else if (tree->split=='V')
{
  TRIGHT->ycoord = tree->ycoord;
  TRIGHT->xcoord = TRIGHT->width + tree->xcoord;
  TLEFT->ycoord = tree->ycoord;
  TLEFT->xcoord = tree->xcoord;
}
setCoord(TLEFT);
setCoord(TRIGHT);
}


/*
*  Print functions
*
*/

void printPostorder(node * tree)
{
  if (tree == NULL) 
  return;

  printPostorder(TLEFT);
  printPostorder(TRIGHT);
  
  if (tree->split=='-')
  printf("(%le,%le)",tree->width,tree->height);
  else
  printf(("%c"),tree->split);
//printf("Index = %d, width = %f, height = %f, split = %c, xcoord = %f, ycoord = %f, parNode = %d\n", tree->index, tree->width, tree->height, tree->split, tree->xcoord, tree->ycoord, tree->parNode);
}

void printPreorder(node * tree)
{
  if (tree == NULL) 
  return;
      
  if (tree->split=='-')
  printf("(%le,%le)",tree->width,tree->height);
  else
  printf(("%c"),tree->split);

  printPreorder(TLEFT);
  printPreorder(TRIGHT);
}

void printInorder(node * tree)
{
  if (tree == NULL) 
  return;

  printInorder(TLEFT);
  if (tree->split=='-')
  printf("(%le,%le)",tree->width,tree->height);
  else
  printf(("%c"),tree->split);
  printInorder(TRIGHT);
}

void printStackArray(stack * head, int n)
{
  int m;
  if(head==NULL)
  return;

  for (m=0; m<n; m++)
  {
  printf("Index = %d, width = %f, height = %f, split = %c, xcoord = %f, ycoord = %f\n", NODE->index, NODE->width, NODE->height, NODE->split, NODE->xcoord, NODE->ycoord);
  head = head->next;//StackPop(head);
  }
} 

void saveTree(node * tree, char * Filename)
{
  if (tree == NULL) 
  return;

  FILE * fptr = fopen(Filename, "a");
  if(fptr == NULL) 
  {
    printf("File loading failed: File does not exist or is empty.\n");
    return;
  }

  saveTree(TLEFT, Filename);
  saveTree(TRIGHT, Filename);

  if (tree->split=='-')
      fprintf(fptr, "%le %le %le %le\n",tree->width, tree->height, tree->xcoord, tree->ycoord);
  fclose(fptr);
}

void printPostorderFull(node * tree)
{
  if (tree == NULL) 
  return;

    printf("Index = %d, width = %f, height = %f, split = %c, xcoord = %f, ycoord = %f\n", tree->index, tree->width, tree->height, tree->split, tree->xcoord, tree->ycoord);

  printPostorderFull(TLEFT);
  printPostorderFull(TRIGHT);
}

void searchNode(node * tree, double * x, double * y, int n)
{
  if (tree == NULL) 
  return;
  if(tree->index==n)
  {
    *x = tree->xcoord;
    *y = tree->ycoord;
    return;
  }
  searchNode(TLEFT,  x,y,n);
  searchNode(TRIGHT, x,y,n);
}

// reroot function, find best case width/height
node * reroot(node * tree, box * min)
{
node * temp;
node * prevHead = tree;

if(tree->split=='H')
{
  if(tree->right->left->split=='-')
  {
    temp = tree->right->left;
    tree = tree->right;
    prevHead->right = temp;
    tree->left = prevHead;
  }
  else
  {
    temp = tree->right->right;
    tree = tree->right;
    prevHead->right = temp;
    tree->right = prevHead;
  }
}

else if (tree->split=='V') 
{
  if(tree->left->right->split=='-') 
  {
    temp = tree->left->right;
    tree = tree->left;
    prevHead->left = temp;
    tree->right = prevHead;
  }
  else
  {
    temp = tree->left->left;
    tree = tree->left;
    prevHead->left = temp;
    tree->left = prevHead;
  }
}
assignCutline(tree);
setCoord(tree);
return tree;
}

//decideMin, decide best case min/help helper function
void decideMin(box * min, node * tree)
{
double area = min->width * min->height;
double newArea = tree->width * tree->height;
if(newArea < area)
{
  min->width = tree->width;
  min->height = tree->height;
  }
}
