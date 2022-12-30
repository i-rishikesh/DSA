// Write a menu driven program to perform the following operations in a single linked list by using suitable user defined functions for each case.
//  Traverse the list.
//  Check if the list is empty. [This function will be called to check underflow condition during the delete operation]
//  Insert a node after a given data item
//  Insert a node before a given data item
//  Delete a node after a given data item
//  Delete a node before a given data item
//  Insert a node at the certain position (at beginning/end/any position).
//  Delete a node at the certain position (at beginning/end/any position).
//  Delete a node for the given key.
//  Search for an element in the linked list.
//  Sort the elements of the linked list
//  Print the elements of the linked list in the reverse order.
//  Reverse the nodes of the linked list.
//  Print n th node from the last of a linked list.
//  Delete the duplicate elements in a linked list.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *start = NULL;
void createlist()
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
        printf("\n %d    ", temp->data);
        temp = temp->next;
    }
}
void empty_list()
{
    if (start == NULL)
    {
        printf("the list is empty");
    }
    else
    
        printf("the list is not empty");
    
}
void node_after_item()
{
    struct node *temp, *n;
    temp = (struct node *)malloc(sizeof(struct node));
    n = (struct node *)malloc(sizeof(struct node));
    int item;
    printf("\nenter the given item after which you want to create a node\n");
    scanf("%d", &item);
    int p;
    printf("enter the data for the node to be inserted\n");
    scanf("%d", &p);
    n->data = p;
    temp = start;
    while (temp->data != item)
    {
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
}
void node_before_item()
{
    int val;
    struct node *n, *t2, *t1;
    n = (struct node *)malloc(sizeof(struct node *));
    printf("\nEnter the data for new node to be added before a node : ");
    scanf("%d", &n->data);
    n->next = NULL;
    if (start == NULL)
    {
        start = n;
    }
    else
    {
        printf("\nEnter the value from list before which new node to insert : ");
        scanf("%d", &val);
        t2 = start;
        while (t2->data != val)
        {
            t1 = t2;
            t2 = t2->next;
        }
        n->next = t2;
        t1->next = n;
    }
}
void delete_after_item()
{
    struct node *temp, *n;
    temp = (struct node *)malloc(sizeof(struct node));
    n = (struct node *)malloc(sizeof(struct node));
    int item;
    printf("\nenter the given item after which you want to delete a node\n");
    scanf("%d", &item);
    temp = start;
    while (temp->data != item)
    {
        temp = temp->next;
    }
    n = temp->next;
    temp->next = n->next;
    free(n);
}
void delete_before_item()
{
    int val;
    struct node *n, *t, *t2;
    n = (struct node *)malloc(sizeof(struct node *));
    if (start == NULL)
    {
        start = n;
    }
    else
    {
        printf("\nEnter the value from list before which new node to delete : ");
        scanf("%d", &val);
        t = start;
        while (t->next->next->data != val)
        {
            t = t->next;
        }
        t2 = t->next;
        t->next = t->next->next;
        free(t2);
    }
}
void insert_nthpos()
{
    int val, n;
    struct node *temp1 = malloc(sizeof(struct node));
    printf("enter the number to be inserted : \n");
    scanf("%d", &val);
    printf("enter the position : \n");
    scanf("%d", &n);
    temp1->data = val;
    temp1->next = NULL;
    if (n == 1)
    {
        temp1->next = start;
        start = temp1;
    }
    struct node *temp2 = malloc(sizeof(struct node));
    temp2 = start;
    for (int i = 0; i < n - 2; i++)
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}
void delete_nthpos()
{
    struct node *temp = start;
    int i, pos;
    printf("enter the position : \n");
    scanf("%d", &pos);
    if (pos == 0)
    {
        start = start->next;
        temp->next = NULL;
        free(temp);
    }
    else
    {
        for (i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        struct node *del = temp->next;
        temp->next = temp->next->next;
        del->next = NULL;
        free(del);
    }
    printf("\nUpdated Linked List is : \n");
}
void delete_By_Key()
{
    int key;
    printf("\nenter the key : \n");
    scanf("%d", &key);
    struct node *temp = start, *prev;
    if (temp != NULL && temp->data == key)
    {
        start = temp->next;
        free(temp);
    }
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return;
    }
    prev->next = temp->next;
    free(temp);
}
int search_element()
{
    int key;
    printf("\nenter the key : \n");
    scanf("%d", &key);
    struct node *temp = start;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
void sort_elements()
{
    struct node *t1, *t2;
    t1 = start;
    while (t1 != NULL)
    {
        t2 = t1->next;
        while (t2 != NULL)
        {
            if (t1->data > t2->data)
            {
                int temp;
                temp = t2->data;
                t2->data = t1->data;
                t1->data = temp;
            }
            t2 = t2->next;
        }
        t1 = t1->next;
    }
}
void printReverse(struct node *start)
{
    if (start != NULL)
    {
        printReverse(start->next);
        printf("%d  ", start->data);
    }
}
void reverse_nodes()
{
    struct node *prev = NULL;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *next = NULL;
    temp = start;
    while (temp != NULL)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    start = prev;
}
int getnth()
{
    int pos;
    printf("\nenter the position you want to enter: \n");
    scanf("%d", &pos);
    struct node *temp = start;
    int count = 1;
    while (temp != NULL)
    {
        if (count == pos)
            return (temp->data);
        count++;
        temp = temp->next;
    }
}
void removeDuplicates()
{
    struct node *ptr1, *ptr2, *dup;
    ptr1 = start;

    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (ptr1->data == ptr2->next->data)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
int main()
{
    int ch, n = 1;
    printf("\n\n 1. create list \n 2. traverse list \n 3. check list is empty \n 4. insert a node after a given item \n 5. insert a node before a given item \n 6. delete a node after a given item \n 7.delete a node before a given item \n 8. insert a node at nth position \n 9. delete a node at nth position \n 10. delete the given key \n 11. search for an element in the linked list \n 12. sort the elements of the linked list \n 13. print the elements in the reverse order \n 14. reverse the nodes \n 15. print nth node from the last of th elinked list \n 16. delete the duplicate element \n 17. Exit \n\n");
    scanf("%d", &ch);
    while (n == 1)
    {
        switch (ch)
        {
        case 1:
            createlist();
            break;

        case 2:
            traverse();
            break;

        case 3:
            empty_list();
            break;

        case 4:
            node_after_item();
            break;

        case 5:
            node_before_item();
            break;

        case 6:
            delete_after_item();
            break;

        case 7:
            delete_before_item();
            break;

        case 8:
            insert_nthpos();
            break;

        case 9:
            delete_nthpos();
            break;

        case 10:
            delete_By_Key();
            break;

        case 11:
            if (search_element() == 1)
            {
                printf("\n Yes the element is present \n");
            }
            else
            {
                printf("\n No the element is absent \n");
            }
            break;

        case 12:
            sort_elements();
            break;

        case 13:
            printReverse(start);
            break;

        case 14:
            reverse_nodes();
            break;

        case 15:
            printf("the element in the position is %d", getnth());
            break;

        case 16:
            removeDuplicates();
            break;

        case 17:
            exit(0);
            break;
        }
        printf("\n\n 1. create list \n 2. traverse list \n 3. check list is empty \n 4. insert a node after a given item \n 5. insert a node before a given item \n 6. delete a node after a given item \n 7.delete a node before a given item \n 8. insert a node at nth position \n 9. delete a node at nth position \n 10. delete the given key \n 11. search for an element in the linked list \n 12. sort the elements of the linked list \n 13. print the elements in the reverse order \n 14. reverse the nodes \n 15. print nth node from the last of th elinked list \n 16. delete the duplicate element \n 17. Exit \n\n");
        scanf("%d", &ch);
    }

    return 0;
}