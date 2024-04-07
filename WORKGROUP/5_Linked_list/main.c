#include <stdio.h>
#include <stdlib.h>

// self-referential structer
typedef struct node
{
    char data;
    struct node *nextPtr;
} node_t;

typedef node_t *ListNodePtr;
void insert(ListNodePtr *head, char val);
void insertAtEnd(ListNodePtr *head, char val);
void insertAtBeginning(ListNodePtr *head, char val);
char delete(ListNodePtr *head, char val);
void deleteAtBeginning(ListNodePtr *head);
int isEmpty(ListNodePtr head);
void printList(ListNodePtr curPtr);

int main(void)
{
    ListNodePtr head = NULL; // initialy there are no nodes
    int choice = 0;          // user's choice
    char item = '\0';        // char entered by user

    // Display the menu
    printf("Enter your choice:\n"
           "    1 to insert an element into the list in alphabetical order\n"
           "    2 to insert an element at the end of the list.\n"
           "    3 to insert an element at the beginning of the list.\n"
           "    4 to delete an element from the list.\n"
           "    5 to delete an element from the beginning of the list.\n"
           "    6 to end.\n");

    printf(":: ");
    scanf("%d", &choice);

    while (choice != 6)
    {
        switch (choice)
        {
        case 1:
            printf("Enter a character: ");
            scanf("\n%c", &item);
            insert(&head, item); // insert item in list
            printList(head);
            break;

        case 2:
            printf("Enter a character: ");
            scanf("\n%c", &item);
            insertAtEnd(&head, item);
            printList(head);
            break;
        case 3:
            printf("Enter a character: ");
            scanf("\n%c", &item);
            insertAtBeginning(&head, item);
            printList(head);
            break;
        case 4: // delete an element
            if (!isEmpty(head))
            {
                printf("Enter character to be deleted: ");
                scanf("\n%c", &item);
                if (delete (&head, item))
                {
                    printf("%c deleted.\n", item);
                    printList(head);
                }
                else
                {
                    printf("%c not found.\n\n", item);
                }
            }
            break;
        case 5: // deletion at the beginning
            if (!isEmpty(head))
            {
                deleteAtBeginning(&head);
                printf("%c deleted.\n", item);
            }
            else
            {
                printf("List is empty\n");
            }
            break;
        case 7:
            printList(head);
            break;
        default:
            printf("Invalid choice.\n\n");

            // Display the menu
            printf("Enter your choice:\n"
                   "    1 to insert an element into the list.\n"
                   "    2 to delete an element from the list.\n"
                   "    3 to end.\n");
            break;
        }

        printf("? ");
        scanf("%d", &choice), getchar();
    }

    printf("End of run");

    return 0;
}

void insertAtBeginning(ListNodePtr *head, char val)
{
    ListNodePtr new_node = malloc(sizeof(node_t));
    new_node->data = val;
    new_node->nextPtr = *head;
    *head = new_node;
    return;
}

void insertAtEnd(ListNodePtr *head, char val)
{
    ListNodePtr current = *head;

    if (current != NULL)
    {
        while (current->nextPtr != NULL)
        {
            current = current->nextPtr;
        }
        // now we can add a new variable
        current->nextPtr = malloc(sizeof(node_t));
        current->nextPtr->data = val;
        current->nextPtr->nextPtr = NULL;
    }
    else
    {
        current = malloc(sizeof(node_t));
        current->data = val;
        current->nextPtr = NULL;
        *head = current;
    }
    return;
}

void insert(ListNodePtr *head, char val)
{
    ListNodePtr newPtr;
    ListNodePtr previousPtr;
    ListNodePtr currentPtr;

    newPtr = malloc(sizeof(node_t));

    if (newPtr != NULL)
    {
        newPtr->data = val;
        newPtr->nextPtr = NULL;

        previousPtr = NULL;
        currentPtr = *head;

        while (currentPtr != NULL && val > currentPtr->data)
        {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        if (previousPtr == NULL)
        {
            newPtr->nextPtr = *head;
            *head = newPtr;
        }
        else
        {
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else
    {
        printf("%c not inserted. No memory available.\n", val);
    }
    return;
}

void deleteAtBeginning(ListNodePtr *head)
{
    ListNodePtr tmpPtr = NULL;

    if (head == NULL)
    {
        return;
    }
    else
    {
        tmpPtr = *head;
        *head = (*head)->nextPtr;
        free(tmpPtr);
    }
    return;
}

char delete(ListNodePtr *head, char val)
{
    ListNodePtr previousPtr;
    ListNodePtr currentPtr;
    ListNodePtr tmpPtr;

    if (val == (*head)->data)
    {
        tmpPtr = *head;
        *head = (*head)->nextPtr;
        free(tmpPtr);
        return val;
    }
    else
    {
        previousPtr = *head;
        currentPtr = (*head)->nextPtr;

        while (currentPtr != NULL && currentPtr->data != val)
        {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        if (currentPtr != NULL)
        {
            tmpPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tmpPtr);
            return val;
        }
    }
    return '\0';
}

void printList(ListNodePtr curPtr)
{
    if (curPtr == NULL)
    {
        printf("List is empty.\n\n");
    }
    else
    {
        printf("The list is:\n");
        while (curPtr != NULL)
        {
            printf("%c --> ", curPtr->data);
            curPtr = curPtr->nextPtr;
        }

        printf("NULL\n\n");
    }
    return;
}

int isEmpty(ListNodePtr head)
{
    return head == NULL;
}