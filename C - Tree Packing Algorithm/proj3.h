typedef struct tree
{
	int value;
	int index;
	int leftVal;
	int rightVal;
	char split;
	double width;
	double height;
	double xcoord;
	double ycoord;

	struct tree * left;
	struct tree * right;
} node;

int saveFile(char* Filename, node tree[], int packSize);
node * loadFile(char *Filename, int * packSize, int * indexNode);
void insert(node ** tree, int index, int val, int left, int right, char split, double width, double height, double x, double y);
void print_inorder_rect(node * tree, node * treeHead, double * x, double *y);

void deleteTree(node * tree);
node * searchTree(node * tree, int val);

void print_inorder_array(node treeHead[], int index);
void print_postorder_array(node head[], int index);
void print_preorder_array(node head[], int index);
//void print_all(node head[], int index);
void setCoord(node tree[], int n);

node searchArray(node tree[], int arraySize, int index);
