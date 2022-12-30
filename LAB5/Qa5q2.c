#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *SortedMerge(struct Node *a, struct Node *b)
{
    struct Node *c;

    if (a->data >= b->data)
    {
        c = b;
        b = b->next;
    }
    else
    {
        c = a;
        a = a->next;
    }
    struct Node *head = c;

    while (a != NULL && b != NULL)
    {

        if (a->data >= b->data)
        {
            c->next = b;
            c = c->next;
            b = b->next;
        }
        else
        {
            c->next = a;
            c = c->next;
            a = a->next;
        }
    }
    if (a == NULL)
    {
        while (b != NULL)
        {
            c->next = b;
            c = c->next;
            b = b->next;
        }
    }
    if (b == NULL)
    {

        while (a != NULL)
        {
            c->next = a;
            c = c->next;
            a = a->next;
        }
    }

    return head;
}
void push(struct Node **head_ref, int new_data)
{
    
    struct Node *new_node =
        (struct Node *)malloc(sizeof(struct Node));

    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}


void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main()
{

    int n, m;
    printf("enter no of node to be created of first ll");
    scanf("%d", &n);
    printf("enter no of node to be created of second ll");
    scanf("%d", &m);

    /* Start with the empty list */
    struct Node *res = NULL;
    struct Node *a = NULL;
    struct Node *b = NULL;
    int arr[n];
    printf("enter the value of first ll node in sorted form");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        push(&a, arr[i]);
    }
    printf("enter the value of second ll node in sorted form");
    int arr1[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for (int i = m - 1; i >= 0; i--)
    {
        push(&b, arr1[i]);
    }
    res = SortedMerge(a, b);
    printList(res);
    printf("\n");
    return 0;
}