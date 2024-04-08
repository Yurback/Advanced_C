#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next; // (ll.tail.next) stored link to the last element
} node_t;

typedef node_t *ptrnode;

typedef struct LL
{
    node_t head;
    node_t tail;
    int size;
} link_list;

typedef link_list *ptrlinklist;

void displaylist(ptrlinklist ll);
void dispaymenu(void);
int appUP(ptrlinklist ll, int v);
int appEND(ptrlinklist, int);
int appTARG(ptrlinklist, int, int);
int delPOS(ptrlinklist, int);
int updPOS(ptrlinklist, int, int);
int findUP(ptrlinklist, int);

int main(void)
{
    link_list Linked_list = {0};
    // Linked_list.head = (node_t){0};
    int choice = 0;
    int value = 0;
    int position = 0;

    while (choice != 8)
    {
        dispaymenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            scanf("%d", &value);
            appUP(&Linked_list, value);
            break;
        case 2:
            scanf("%d", &value);
            appEND(&Linked_list, value);
            break;
        case 3:
            scanf("%d %d", &value, &position);
            appTARG(&Linked_list, value, position);
            break;
        case 4:
            scanf("%d", &position);
            int del = delPOS(&Linked_list, position);
            printf("%d deleted\n", del);
            break;
        case 5:
            scanf("%d %d", &value, &position);
            updPOS(&Linked_list, value, position);
            break;
        case 6:
            scanf("%d", &value);
            int pos = findUP(&Linked_list, value);
            printf("Index of element is %d", pos);
            break;
        case 7:
            displaylist(&Linked_list);
            break;
        }
    }

    return 0;
}

int appUP(ptrlinklist ll, int v)
{
    if ((*ll).size == 0) // head is not present
    {
        ll->head.data = v;
        ll->tail.data = v;
    }
    else
    {
        if (ll->head.data == v) // value in head == newvalue
            return 0;

        ptrnode second = ll->head.next;
        ptrnode newNode = malloc(sizeof(node_t));

        if (second != NULL)
        {
            newNode->next = second;
        }
        else
        {
            ll->tail.next = newNode;       // записываем в поле next адрес последнего нода
            ll->tail.data = ll->head.data; // значение берем из head;
        }
        ll->head.next = newNode;
        ll->head.next->data = ll->head.data;
        ll->head.data = v;
    }
    ll->size++;
    return 1;
}

int appEND(ptrlinklist ll, int v)
{
    if ((*ll).size == 0) // head is not present
    {
        ll->head.data = v;
        ll->tail.data = v;
    }
    else
    {
        if (ll->tail.data == v) // value in tail == newvalue
            return 0;
        ptrnode tail = ll->head.next;
        ptrnode newNode = malloc(sizeof(node_t));
        newNode->data = v;
        newNode->next = NULL;
        if (!tail)
        {
            ll->head.next = newNode;
            ll->tail.next = newNode; // записываем в поле next адрес последнего нода
            ll->tail.data = v;       // значение v - user input;
        }
        else
        {

            ll->tail.next->next = newNode;
            ll->tail.next = newNode;
            ll->tail.data = v;
        }
    }
    ll->size++;
    return 1;
}

int appTARG(ptrlinklist ll, int val, int pos)
{
    // Sanitizg section
    if (pos > (ll->size + 1) || pos < 1)
        return 0;
    if (pos == 1)
    {
        appUP(ll, val);
        return 1;
    }
    if (pos == (ll->size + 1))
    {
        appEND(ll, val);
        return 1;
    }

    if (pos == 2)
    {
        if (ll->head.data == val || ll->head.next->data == val)
            return 0;
        ptrnode tail = ll->head.next;
        ptrnode newNode = malloc(sizeof(node_t));
        newNode->data = val;
        newNode->next = NULL;
        if (!tail)
        {
            ll->head.next = newNode;
            ll->tail.next = newNode; // записываем в поле next адрес последнего нода
            ll->tail.data = val;     // значение val - user input;
        }
        else
        {
            ll->head.next = newNode;
            ll->head.next->next = tail;
        }
        ll->size++;
        return 1;
    }
    // Operation section
    ptrnode prevnode = ll->head.next; // previous position 2-nd
    ptrnode curnode = prevnode->next; // current position 3-nd
    int shift = pos - 3;
    for (int i = 0; i < shift; prevnode = curnode, curnode = curnode->next, i++) // shift start from 3-rd ps
        ;
    if (val == prevnode->data || val == curnode->data)
        return 0;
    ptrnode newNode = malloc(sizeof(node_t));
    newNode->data = val;
    prevnode->next = newNode;
    newNode->next = curnode;
    ll->size++;
    return 1;
}

int delPOS(ptrlinklist ll, int pos)
{
    if (ll->size == 0)
    {
        printf("List empty\n");
        return 0;
    }
    if (pos < 1 || pos > ll->size)
        return 0;
    ptrnode prevnode = &(ll->head);
    ptrnode curnode = ll->head.next;
    if (pos == 1)
    {
        int value = prevnode->data;
        if (curnode == NULL)
        {
            prevnode->data = 0;
            prevnode->next = NULL;
            ll->tail.data = 0;
            ll->tail.next = NULL;
        }
        else
        {
            *prevnode = *curnode;
        }
        ll->size--;
        return value;
    }

    int shift = pos - 2;
    for (int i = 0; i < shift; prevnode = curnode, curnode = curnode->next, i++)
        ;
    prevnode->next = curnode->next;
    int value = curnode->data;
    free(curnode);
    curnode = NULL;
    if (pos == ll->size)
    {
        ll->tail.next = prevnode;
        ll->tail.data = prevnode->data;
    }
    ll->size--;
    return value;
}

int updPOS(ptrlinklist ll, int val, int pos)
{
    if (ll->size == 0)
    {
        printf("List empty\n");
        return 0;
    }
    if (pos < 1 || pos > ll->size)
        return 0;
    ptrnode prevnode = &(ll->head);
    ptrnode curnode = ll->head.next;
    if (pos == 1)
    {
        prevnode->data = val;
        if (curnode == NULL)
            ll->tail.data = val;
        return 1;
    }
    int shift = pos - 2;
    for (int i = 0; i < shift; curnode = curnode->next, i++)
        ;
    curnode->data = val;
    if (pos == ll->size)
    {
        ll->tail.data = val;
    }
    return 1;
}

int findUP(ptrlinklist ll, int val)
{
    if (ll->size == 0)
    {
        printf("List empty\n");
        return 0;
    }
    ptrnode prevnode = &(ll->head);
    if (prevnode->data == val)
        return 1;
    if (ll->size >= 2)
    {
        ptrnode curnode = ll->head.next;
        for (int i = 2; i <= ll->size; i++)
        {
            if (curnode->data == val)
                return i;
            curnode = curnode->next;
        }
    }
    return -1;
}

void displaylist(ptrlinklist ll)
{
    printf("\n");
    if (ll->size == 0)
    {
        printf("List empty\n");
        return;
    }
    node_t first = ll->head;
    printf("%d ", first.data);
    ptrnode nextnode = first.next;
    while (nextnode)
    {
        printf("%d ", nextnode->data);
        nextnode = nextnode->next;
    }
    printf("\n\n");
    printf("SIZE : %d\n", ll->size);
    return;
}

void dispaymenu(void)
{
    printf("-------------------------------------------------\n\n\
Operations on a linked list\n\n\
-------------------------------------------------\n\n\
1.Insert node at beginning\n\
2.Insert node at end\n\
3.Insert node at a specific place\n\
4.Delete node from any position\n\
5.Update node value\n\
6.Search element in the linked list\n\
7.Display list\n\
8.Exit\n\n\
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\
Enter your choice: ");
    return;
}