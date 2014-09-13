typedef struct tree
{
	int index;
	double width;
	double height;
	double xcoord;
	double ycoord;
	char split;
	struct tree * left;
	struct tree * right;
} node;

typedef	struct _box
{
	double width;
	double height;
} box;

typedef struct _stack {
    struct _stack * next;
    node * stackNode;
} stack;

// Stack Functions
stack * StackPush(stack * st, node * headNode);
stack * StackPop(stack * head);
stack * loadFile(char *Filename, int * index);
void printStackArray(stack * head, int n);

// Print Functions
void printPostorder(node * tree);
void printInorder(node * tree);
void printPreorder(node * tree);
void saveTree(node * tree, char *Filename);
void printPostorderFull(node * tree);

// Binary Tree Functions
node * nodeCreate(double width, double height, char split, int index);
node * nodeArrange(node * aTree, node ** head);
void buildTree(stack * root, node * head, node ** header, int index);
void deleteTree(node * tree);
void searchNode(node * tree, double * x, double * y, int n);

// Packing Functions
void setCoord(node * head);
void assignCutline(node * head);

// Re-rooting
node * reroot(node * tree, box * min);
void decideMin(box * min, node * tree);

