#include "proj2.h"
#include <stdio.h>
#include <stdlib.h>

/* 
*Loads an input file and return an array with values
*/

Node * Load_File(char *Filename)
{
    int success;
    long val = 0;
    int counter = -1;
    FILE *fptr = fopen(Filename, "r");
    
    if(!fptr || (feof(fptr)) )
    {
        printf("File loading failed: File does not exist or is empty.\n");
        return NULL;
    }
    else
    {
        while(!feof(fptr))
        if(fscanf(fptr, "%ld", &val))
        counter++;
    }

    rewind(fptr);
  
   success = fscanf(fptr, "%ld", &val);
    if(!success)
        {
                printf("File loading failed: format incorrect.\n");
                fclose(fptr);
                return NULL;
        }
    Node * head = nodeConstruct(val); 
    Node * nodeArray = head;

    while(!feof(fptr) && counter!=1)
    {
        success = fscanf(fptr, "%ld", &val);
        nodeArray -> next = nodeConstruct(val);
        nodeArray = nodeArray->next;
        counter--;
    }
return head;
}

/*
* Linked list helper functions
*/

Node * nodeConstruct(long val)
{
Node * n = malloc(sizeof(Node));
n -> value = val;
n -> next = NULL;
return n;
}

void printNode (Node * head)
{
    while(head!=NULL)
    {
        printf("%ld\n",head->value);
        head = head -> next;
    }
}

void destroyNode (Node * head)
{
    while(head!=NULL)
    { 
        Node * p = head -> next;
        free (head);
        head = p;
    }
}

int countNode(Node * head)
{
    int counter = 0;
    while(head!=NULL)
    { 
        counter++;
        head = head->next;
    }
    return counter;
}

/*
*Write the sorted array to a file
*/
int Save_File(char *Filename, Node * head)
{
    int counter = 0;
    // File checking
    FILE * fptr = fopen(Filename, "w");
    if(!fptr)
    {
        printf("File loading failed: File does not exist.\n");
        return 0;
    }

    // Write the pointer Array to file  
    while(head!=NULL)
    {
        fprintf(fptr, "%ld\n", head->value);
        head = head -> next;
        counter++;
    }
    // Close file pointer
    fclose(fptr);
return counter;
}

long pwr(int base, int exp)
{
    long ans = 1;
    int n = 0;
    for (n=0; n<exp; n++)
    {
        ans *= base;
    }
    return ans;
}

Node *Shell_Sort(Node * list)
{
 //initialize variables
    long x = 0, y = 0; //p = 0;
    int size = countNode(list);
    Node * temp;
   // Node * hold;
    long tempVal;

    //sort shells
    //for(x=0; x<size; x++)
    for (x = 1; x <= size / 3; x = 3*x+ 1);
    {
        for(y=0; y<size-1; y++)
        {
            //sort
            //for (temp = list; temp && temp->next; temp = temp->next)
            for (temp = list; temp && temp->next; temp = temp->next)
            {
               // hold = temp;
                if(temp->value > temp->next->value)
                {
                tempVal = temp->value;
                temp->value = temp->next->value;
                temp->next->value = tempVal;
                }
            }            
        }
    }
return list;
}
