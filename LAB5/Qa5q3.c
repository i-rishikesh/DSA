#include <stdio.h>
#include <stdlib.h>
struct node
{
    int cof;
    int exp;
    struct node *next;
};
struct node *createNode(int cof, int exp)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->cof = cof;
    p->exp = exp;
    p->next = NULL;
}
void push(struct node **head, int cof, int exp)
{
    struct node *t = *head;
    struct node *p = createNode(cof, exp);
    if (*head == NULL)
    {
        *head = p;
    }
    else
    {

        struct node *prev = t;
        while (t->next != NULL && t->exp > p->exp)
        {
            prev = t;
            t = t->next;
        }
        if (prev->exp > p->exp)
        {
            t->next = p;
        }
    }
}
void traverse(struct node *head)
{
    while (head != NULL)
    {
        printf("%dx^%d ", head->cof, head->exp);
        head = head->next;
    }
    printf("\n");
}
void add(struct node *head, struct node *second, struct node **third)
{

    struct node *t = *third;
    while (head != NULL && second != NULL)
    {
        if (head->exp == second->exp)
        {
            int sum = head->cof + second->cof;
            push(&t, sum, head->exp);
            head = head->next;
            second = second->next;
        }
        else
        {
            if (head->exp > second->exp)
            {
                push(&t, head->cof, head->exp);
                head = head->next;
            }
            else
            {
                push(&t, second->cof, second->exp);
                second = second->next;
            }
        }
    }
    if (head == NULL)
    {

        while (second != NULL)
        {
            push(&t, second->cof, second->exp);
            second = second->next;
        }
    }
    if (second == NULL)
    {

        while (head != NULL)
        {
            push(&t, head->cof, head->exp);
            head = head->next;
        }
    }
    traverse(t);
}
int main()
{
    struct node *head = NULL;
    push(&head, 3, 3);
    push(&head, 3, 2);
    push(&head, 2, 1);
    traverse(head);
    struct node *second = NULL;
    push(&second, 4, 3);
    push(&second, 5, 2);
    push(&second, 8, 1);
    push(&second, 7, 0);
    struct node *third = NULL;
    traverse(second);

    add(head, second, &third);
    return 0;
}