#include "proj3.h"
#include <stdio.h>
#include <stdlib.h>

/*
* File I/O
*/
node * loadFile(char *Filename, int * packSize, int * indexNode)
{
    int n, scanSuccess, index, parentNode, left, right;
    double xcoord = 0;
    double ycoord = 0;
    char split = 'N';
    double width = 0;
    double height = 0;
    
    // Check for file errors
    FILE *fptr = fopen(Filename, "r");
    if(!fptr || feof(fptr))
    {
        printf("File loading failed: File does not exist or is empty.\n");
        return NULL;
    }
   // Height of Tree & Node
fscanf(fptr, "%d", packSize);
fscanf(fptr, "%d", indexNode);

   //  Create Tree
  node * root = malloc(sizeof(node));
  root = NULL;

   for (n=0; n<(*indexNode); n++)
   {
    scanSuccess = fscanf(fptr, "%d %d %d %d %c %lf %lf", &index, &parentNode, &left, &right, &split, &width, &height);
    if (!scanSuccess)
    {
        scanSuccess = fscanf(fptr, "%d %d %d %d %c", &index, &parentNode, &left, &right, &split);
        n--;
    }

if (scanSuccess)
    {
    //printf("insert: index %d, parent %d, left %d, right %d, split %c, width %f, height %f\n", index, parentNode, left, right, split, width, height);
    insert(&root, index, parentNode, left, right, split, width, height, xcoord, ycoord);
    }
    width = 0;
    height = 0;
}

return root;
}

int saveFile(char* filename, node tree[], int packSize)
{
  FILE* fptr = fopen(filename, "w");
  if(fptr == NULL) {
    printf("File loading failed: File does not exist or is empty.\n");
    return EXIT_FAILURE;
  }

  fprintf(fptr, "%d\n", packSize);

  int n;
  for(n = 0; n < packSize; n++) {
    fprintf(fptr, "%d %le %le %le %le\n", tree[n].index, tree[n].width, tree[n].height, tree[n].xcoord, tree[n].ycoord);
     }
   //printf("parent = %d, index = %d, left = %d, right =%d, width = %f, height = %f, split = %c, x = %f, y = %f\n",tree->value, tree->index, tree->leftVal, tree->rightVal, tree->width, tree->height, tree->split, *x, *y);
fclose(fptr);

  return EXIT_SUCCESS;
}


/*
* Build tree
*/
void insert(node ** tree, int index, int val, int left, int right, char split, double width, double height, double x, double y)
{
    node * temp = NULL;

    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->value = val;
        temp->index = index;
        temp->width = width;
        temp->height = height;
        temp->leftVal = left;
        temp->rightVal = right;
        temp->split = split;
        temp->xcoord = x;
        temp->ycoord = y;
        *tree = temp;
        return;
    }

 if(index < (*tree)->index)
    {
        insert(&(*tree)->left, index, val, left, right, split, width, height,x,y);
    }
    else if(index > (*tree)->index)
    { 
        insert(&(*tree)->right, index, val, left, right, split, width, height,x,y);
    }

}

/*
* Split tree into horizontal/vertical blocks
*/
void print_inorder_rect(node * tree, node * treeHead, double * x, double * y)
{    
    node * tempLeft;
    node * tempRight;

 if (tree)
    {

       if (tree->split=='V')
         {
         tempLeft = searchTree(treeHead, tree->leftVal);
         tempRight = searchTree(treeHead, tree->rightVal); 

          double lw = tempLeft->width; //searchTree(temp, tree->leftVal) -> width;
          double lh = tempLeft->height; //searchTree(temp, tree->leftVal) -> height;
          double rw = tempRight->width; // searchTree(temp, tree->rightVal) -> width;
          double rh = tempRight->height; //searchTree(temp, tree->rightVal) -> height;

         (*x)=(lw+rw);
         tree->width = *x;

         if(lh >= rh)
            (*y) = lh;
         else
            (*y) = rh;

         tree->height= *y;
         }

        if (tree->split=='H')
         {
          tempLeft = searchTree(treeHead, tree->leftVal);
          tempRight = searchTree(treeHead, tree->rightVal); 
 
          double lw = tempLeft->width; //searchTree(temp, tree->leftVal) -> width;
          double lh = tempLeft->height; //searchTree(temp, tree->leftVal) -> height;
          double rw = tempRight->width; // searchTree(temp, tree->rightVal) -> width;
          double rh = tempRight->height; //searchTree(temp, tree->rightVal) -> height;
         
         (*y)=(lh+rh);
         tree->height= *y;

         if(lw >= rw)
            (*x) = lw;
         else
            (*x) = rw;
         tree->width = *x;
         }

        print_inorder_rect(tree->left,treeHead, x, y);
        print_inorder_rect(tree->right,treeHead, x, y); 
   }
}

/*
* Tree helper functions
*/
void deleteTree(node * tree)
{
    if (tree)
    {
        deleteTree(tree->left);
        deleteTree(tree->right);
        free(tree);
    }
}

node * searchTree(node * tree, int index)
{
if (tree == NULL)
    return NULL;

  if (index == (tree -> index))
    return tree;
  else if (index < (tree -> index))
    return searchTree(tree -> left, index);
  else if (index > (tree -> index))
    return searchTree(tree -> right, index);

  return NULL;
}

void print_inorder_array(node head[], int index)
{
if(index < 0)
   return; 

int left = head[index].leftVal; 
int right = head[index].rightVal;


print_inorder_array(head,left-1);
printf("%d ", head[index].index); 
print_inorder_array(head, right-1);
}

void print_preorder_array(node head[], int index)
{
if(index < 0)
   return; 


int left = head[index].leftVal; 
int right = head[index].rightVal;

printf("%d ", head[index].index); 
print_inorder_array(head,left-1);
print_inorder_array(head, right-1);
}

void print_postorder_array(node head[], int index)
{
if(index < 0)
   return; 

int left = head[index].leftVal; 
int right = head[index].rightVal;

print_inorder_array(head,left-1);
print_inorder_array(head, right-1);
printf("%d ", head[index].index); 
}

/*void print_all(node head[], int index)
{
if(index < 0)
   return; 

int left = head[index].leftVal; 
int right = head[index].rightVal;

print_all(head,left-1);
printf("index = %d, cut = %c, width = %3.1f, height = %3.1f, xcoord = %3.1f, ycoord = %3.1f\n", head[index].index, head[index].split, head[index].width, head[index].height, head[index].xcoord, head[index].ycoord); 
print_all(head, right-1);
}*/


void setCoord(node head[], int n)
{
  if(n< 0)
   return;

if (head[n].split=='-')
{
 // printf("index = %d, cut = %c, width = %3.1f, height = %3.1f, xcoord = %3.1f, ycoord = %3.1f\n", head[n].index, head[n].split, head[n].width, head[n].height, head[n].xcoord, head[n].ycoord); 
  return;
}
else if (head[n].split=='H')
{
    head[ head[n].leftVal-1].xcoord = head[n].xcoord;
    head[ head[n].leftVal-1].ycoord = head[head[n].rightVal-1].height + head[n].ycoord;
    head[ head[n].rightVal-1].ycoord = head[n].ycoord;
    head[ head[n].rightVal-1].xcoord = head[n].xcoord;
}
else
{
    head[ head[n].rightVal-1].ycoord = head[n].ycoord;
    head[ head[n].rightVal-1].xcoord = head[head[n].leftVal-1].width + head[n].xcoord;
    head[ head[n].leftVal-1].ycoord = head[n].ycoord;
    head[ head[n].leftVal-1].xcoord = head[n].xcoord;
}


int left = head[n].leftVal; 
int right = head[n].rightVal;

//printf("index = %d, cut = %c, width = %3.1f, height = %3.1f, xcoord = %3.1f, ycoord = %3.1f\n", head[n].index, head[n].split, head[n].width, head[n].height, head[n].xcoord, head[n].ycoord); 

setCoord(head,left-1);
setCoord(head,right-1);
}