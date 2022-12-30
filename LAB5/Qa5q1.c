#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *createNode(int value)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = value;
    p->next = NULL;
    return p;
}
void push(struct node **head, int value)
{
    struct node *p = createNode(value);
    struct node *temp;
    if (*head == NULL)
    {
        *head = p;
    }
    else
    {
        temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
    }
}
void traverse(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
int length(struct node **head)
{
    struct node *t = *head;
    int c = 0;
    while (t != NULL)
    {
        c++;
        t = t->next;
    }
    return c;
}
void condition(struct node **head, int value)
{
    struct node *t = *head;
    struct node *prev;
    struct node *temp;
    while (t->data != value && t != NULL)
    {
        prev = t;
        t = t->next;
    }
    temp = t;
    prev->next = t->next;
    temp->next = *head;
    *head = temp;
}
void middle(struct node **head)
{
    struct node *fast = *head;
    struct node *slow = *head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    printf("middle node element is %d\n", slow->data);
}
int checkSort(struct node **head)
{
    struct node *t = *head;
    struct node *q = t->next;
    while (t->next != NULL)
    {
        if (t->data > q->data)
        {
            return 0;
        }
        else
        {
            q = q->next;
        }
        if (q == NULL)
        {
            t = t->next;
            q = t->next;
        }
    }
    return 1;
}
void insertElement(struct node **head)
{
    struct node *t = *head;
    printf("enter the value ");
    int val;
    scanf("%d", &val);
    struct node *new = createNode(val);
    struct node *prev;
    while (t->next != NULL)
    {
        prev = t;
        t = t->next;
        if (val < t->data && prev->data < val)
        {
            printf("1\n");
            new->next = t;
            prev->next = new;
            break;
        }
    }
    if (t->data <= new->data)
    {
        t->next = new;
    }

    traverse(*head);
}
void insertionTwoll(struct node **first, struct node **second)
{
    struct node *t = *first;
    struct node *t1 = *second;
    struct node *third = NULL;
    struct node *t3 = third;
    while (t->next != NULL || t1->next != NULL)
    {
        if (t->data == t1->data && third == NULL)
        {

            t3->data = t->data;
            t = t->next;
            t1 = t1->next;
        }

        else if (t->data == t1->data && third != NULL)
        {
            struct node *p = createNode(t->data);
            t3->next = p;
            t3 = p;
            t = t->next;
            t1 = t1->next;
        }
        else
        {
            t = t->next;
            t1 = t1->next;
        }
    }
    traverse(third);
}
void modify1(struct node **head)
{
    struct node *eve = NULL;
    struct node *odd = NULL;
    struct node *t = *head;
    struct node *todd;
    while (t != NULL)
    {
        if (t->data % 2 == 0)
        {
            if (eve == NULL)
            {
                eve = t;
                *head = eve;
            }
            else
            {
                struct node *p = createNode(t->data);
                eve->next = p;
                eve = eve->next;
            }
        }
        else
        {
            if (odd == NULL)
            {
                odd = t;
                todd = odd;
            }
            else
            {
                struct node *p = createNode(t->data);
                todd->next = p;
                todd = todd->next;
            }
        }
        t = t->next;
    }
    eve->next = odd;
    traverse(*head);
}
void reverseNode(struct node *current, struct node *previous, struct node **head)
{
    if (!current->next)
    {
        *head = current;
        current->next = previous;
        return;
    }
    struct node *next = current->next;
    current->next = previous;
    reverseNode(next, current, head);
}
void palindrom(struct node **head) // wrong
{
    struct node *t = *head;
    struct node *p = *head;
    reverseNode(t, NULL, &t);
    traverse(t);
    printf("\n");
    traverse(p);
    //    while (p!=NULL)
    //    {
    //       if (p->data ==t->data)
    //       {
    //         t=t->next;
    //         p=p->next;
    //       }
    //       else{
    //         return 0;
    //       }

    //    }
    //    return 1;
}
int cycle(struct node **head)
{
    int n = 3;
    int c = 0;
    while (c == 0)
    {
        struct node *t = *head;
        struct node *prev = t;
        for (int i = 0; i < n - 1; i++)
        {
            t = t->next;
        }
        while (prev->data != t->next->data && t != NULL)
        {
            t = t->next;
            prev = prev->next;
        }
        if (prev->data == t->next->data)
        {
            c++;
        }
        else
            n++;
    }
    if (c > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void reverseEven(struct node **head)
{
    struct node *t = *head;
    struct node *eve = NULL;
    struct node *teve;

    while (t != NULL)
    {
        if (t->data % 2 == 0)
        {
            if (eve == NULL)
            {
                eve = t;
                teve = eve;
            }
            else
            {
                struct node *p = createNode(t->data);
                teve->next = p;
                teve = teve->next;
            }
        }
        t = t->next;
    }
    reverseNode(eve, NULL, &eve);
    traverse(eve);
}
void swapNode(struct node **head, int k1, int k2)
{
    int len = length(head) - k2 + 1;
    struct node *t = *head;
    struct node *j = t;
    for (int i = 0; i < k1; i++)
    {
        t = t->next;
    }
    for (int i = 0; i < len; i++)
    {
        j = j->next;
    }
    int temp = t->data;
    t->data = j->data;
    j->data = temp;
    traverse(*head);
}
struct node *reverseKNode(struct node **head, int k)
{
    struct node *t = *head;
    struct node *rev = t;
    struct node *prev;
    int n = k;
    if (t == NULL)
        return rev;

    while (k > 0 && t != NULL)
    {
        prev = t;
        t = t->next;
        k--;
    }
    prev->next = NULL;
    int temp = rev->data;
    rev->data = prev->data;
    prev->data = temp;
    struct node *p = reverseKNode(&t, n);
    prev->next = p;
    return *head;
}
struct node *  counterClockwise(struct node ** head,int k)
{
    struct node *t =*head;
    struct node *rev = t;
    struct node *prev;
    while (k > 0 && t != NULL)
    {
        prev = t;
        t = t->next;
        k--;
    }
    prev->next = NULL;
    if (t!=NULL)
    *head =t;
    while (t->next!=NULL)
    {
        t=t->next;
    }
    if (t!=NULL)
    {
       
    t->next=rev;
    }
    
    return *head;
    
}
int main()
{
    struct node *head = NULL;
    push(&head, 1);
    push(&head, 6);
    push(&head, 4);
    push(&head, 2);
    push(&head, 1);
    traverse(head);
    struct node *p = NULL;
    push(&p, 2);
    push(&p, 3);
    push(&p, 40);
    push(&p, 55);
    push(&p, 61);
    push(&p, 67);
    printf("This is menu drive program \n");

    int a;
    printf("1.search an element ,delete it and add at first\n2. find middle node element \n3.reverse m element\n4.check sorted or not\n5. insert an element into the linked list in sorted way\n6.the intersections elements of two linked list and store them in a third linked list.\n7. program to modify the linked list such that\n8. palindrom \n9. cycle in ll \n10.reverse only even position nodes\n11. swap kth node from beginning with kth node from end\n12.reverse every k nodes.\n13.rotate the linked list counter-clockwise by k nodes.\n14.EXIT\n");
    while (a != 14)
    {
        printf("enter your choice\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            condition(&head, 21);
            traverse(head);
            break;
        case 2:
            middle(&head);
            break;
        case 3:

            break;
        case 4:
            if (checkSort(&head))
            {
                printf("sorted");
            }
            else
                printf("not sorted");

            break;
        case 5:
            insertElement(&p);
            break;
        case 6:
            insertionTwoll(&head, &p);
            break;
        case 7:
            modify1(&p);
            break;
        case 8:
            // if (palindrom(&head))
            // {
            //     printf("the ll is palindromic ");
            // }else{
            //     printf("the ll is not a plaindromic");
            // }
            palindrom(&head);
            break;
        case 9:
            if (cycle(&head))
            {
                printf("cycle is present ");
            }
            else
            {
                printf("cycle not present");
            }

            break;
        case 10:
            reverseEven(&head);
            break;
        case 11:
            printf("enter kth node from beginning");
            int k1;
            scanf("%d", &k1);
            printf("enter kth node from end");
            int k2;
            scanf("%d", &k2);
            swapNode(&head, k1, k2);
            break;
        case 12:
            printf("enter no of node ");
            int k;
            scanf("%d", &k);
            traverse(reverseKNode(&head, k));
            break;
        case 13:
           printf("enter no of node ");
            int v;
            scanf("%d", &v);
           traverse( counterClockwise(&head,v));
            break;
        case 14:
            exit(0);
            break;
        default:
            printf("you enter a invalid input\n");
            break;
        }
    }
}