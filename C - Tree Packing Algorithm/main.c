#include "proj3.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char * * argv)
{

if (argc != 3)
{
  printf("usage: ./proj3 input.txt output.pck\n");
  return EXIT_FAILURE;
}

	int packSize;
    int indexNode;
    int success;
    int n = 0;
    double x = 0;
    double y = 0;

    node * root = loadFile(argv[1], &packSize, &indexNode);
   node * tree = root;
    struct tree head[indexNode];

    //printf("packSize is %d\n", packSize);
    //printf("indexnode is %d\n", indexNode);

	
  print_inorder_rect(root, root, &x, &y);


clock_t tStart = clock();
for (n=0; n<indexNode; n++)
{
    head[n] = *tree;
    if (tree->left)
        tree=tree->left;
    else if (tree->right)
        tree=tree->right;
}
setCoord(head, indexNode-1);
clock_t tEnd = clock();


printf("Preorder: ");
print_preorder_array(head, indexNode-1);
printf("\n\nInorder: ");
print_inorder_array(head, indexNode-1);
printf("\n\nPostorder: ");
print_postorder_array(head, indexNode-1);
printf("\n\n");
printf("Width:  %le\n", x);
printf("Height:  %le\n", y);
printf("\n");
printf("X-coordinate:  %le\n", head[packSize-1].xcoord);
printf("Y-coordinate:  %le\n", head[packSize-1].ycoord);
printf("\n");
printf("Elapsed Time %le\n", (double) (tEnd - tStart) / CLOCKS_PER_SEC);

//printf("\n\n\n");
//print_all(head, indexNode-1);

 success = saveFile(argv[2], head, packSize);
    deleteTree(root);

if (success)
    return EXIT_SUCCESS;

return EXIT_FAILURE;
}