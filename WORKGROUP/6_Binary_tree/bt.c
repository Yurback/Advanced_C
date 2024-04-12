#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// self-referential structure
struct treeNode
{
    int data;
    struct treeNode *leftPtr;
    struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

void insertNode(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);

int main(void)
{
    int i = 0; // couter to loop from 1-10
    int item = 0;
    TreeNodePtr rootPtr = NULL;

    srand(time(NULL));
    printf("The numbers being placed in the tree are:\n");

    for (i = 1; i <= 5; i++)
    {
        item = rand() % 15;
        printf("%3d", item);
        insertNode(&rootPtr, item);
    }

    // traverse the tree preOrder
    printf("\n\nThe preOrder traversal is:\n");
    preOrder(rootPtr);

    // traverse the tree inOrder
    printf("\n\nThe inOrder traversal is:\n");
    inOrder(rootPtr);

    // traverse the tree postOrder
    printf("\n\nThe postOrder traversal is:\n");
    postOrder(rootPtr);

    return 0;
}

void insertNode(TreeNodePtr *treePtr, int value)
{
    if (*treePtr == NULL)
    {
        *treePtr = malloc(sizeof(TreeNode));

        // if memory was allocated then assign data
        if (treePtr != NULL)
        {
            (*treePtr)->data = value;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        }
        else
        {
            printf("%d not inserted. No memory available.\n", value);
        }
    }
    else
    {
        // data to insert is less than in current node
        if (value < (*treePtr)->data)
        {
            insertNode(&((*treePtr)->leftPtr), value);
        }
        // data to insert is greater than data in current node
        else if (value > (*treePtr)->data)
        {
            insertNode(&((*treePtr)->rightPtr), value);
        }
        else
        { // duplicate data value ignored
            printf("dup\n");
        }
    }
}

void inOrder(TreeNodePtr treePtr)
{
    if (treePtr != NULL)
    {
        inOrder(treePtr->leftPtr);
        printf("%3d", treePtr->data);
        inOrder(treePtr->rightPtr);
    }
}

void preOrder(TreeNodePtr treePtr)
{
    if (treePtr != NULL)
    {
        printf("%3d", treePtr->data);
        preOrder(treePtr->leftPtr);
        preOrder(treePtr->rightPtr);
    }
}

void postOrder(TreeNodePtr treePtr)
{
    if (treePtr != NULL)
    {
        postOrder(treePtr->leftPtr);
        postOrder(treePtr->rightPtr);
        printf("%3d", treePtr->data);
    }
}