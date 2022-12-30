// write a menu driven program to perform the following operation on a single linklist. 1. create and 2. traverse
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *start = NULL;
void createList()
{
    int n;
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    if (n != 0)
    {
        int ch;
        struct node *newnode;
        struct node *temp;
        newnode = (struct node *)malloc(sizeof(struct node));
        start = newnode;
        temp = start;
        printf("\nEnter number to be inserted : ");
        scanf("%d", &ch);
        start->data = ch;
        for (int i = 2; i <= n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            temp->next = newnode;
            printf("\nEnter number to be inserted : ");
            scanf("%d", &ch);
            newnode->data = ch;
            newnode->next = NULL;
            temp = temp->next;
        }
    }
    printf("\nThe list is created\n");
}
void traverse()
{
    struct node *temp = start;
    while (temp != NULL)
    {
        printf("%d    \n", temp->data);
        temp = temp->next;
    }
}
int main()
{
    int ch, n = 1;
    printf("1. create list \n 2. Display list \n 3. Exit \n");
    scanf("%d", &ch);
    while (n == 1)
    {
        switch (ch)
        {
        case 1:
            createList();
            break;

        case 2:
            traverse();
            break;

        case 3:
            exit(0);
            break;
        }
        printf("1. create list \n 2. Display list \n 3. Exit \n");
        scanf("%d", &ch);
    }

    return 0;
}