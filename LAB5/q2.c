#include <stdio.h>
#include <stdlib.h>
void create();
void traverse();
struct node
{
    int data;
    struct node *prev;
    struct node *next;
} * start, *end;
void create()
{
    struct node *p;
    int data;
    p = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &data);
    if (start == NULL)
    {
        start = p;
        p->prev = NULL;
        p->data = data;
        p->next = NULL;
        end = p;
    }
    else
    {
        end->next = p;
        p->prev = end;
        p->data = data;
        p->next = NULL;
        end = p;
    }
}
void traverse()
{
    struct node *temp;
    temp = start;
    printf("Contents of the list is/are ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void backward()
{
    struct node *temp;
    temp = end;
    printf("Contents of the list is/are ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
int main()
{
    int n = 1, ch;
    while (n == 1)
    {
        printf("1. Create a node\n2. Traverse the list\n3. Backward traversal\n4. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            traverse();
            break;
        case 3:
            backward();
            break;
        case 4:
            exit(0);
        }
        printf("Enter 1 to continue || 0 to exit: \n");
        scanf("%d", &n);
        if (n == 0)
        {
            exit(0);
        }
    }
    return 0;
}