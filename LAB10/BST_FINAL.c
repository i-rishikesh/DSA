#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *lptr;
    struct node *rptr;
}*root=NULL;
void create(int val)
{
    struct node *new; 
    struct node *node;
    struct node *par;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = val;
    new->lptr = NULL;
    new->rptr = NULL;

    node = root;
    par = NULL;

    if (node == NULL)
    {
        root = new;
    }
    else
    {
        while (node != NULL)
        {
            par = node;
            if (val < node->data)
            {
                node = node->lptr;
            }
            else
            {
                node = node->rptr;
            }
        }
        if (val < par->data)
        {
            par->lptr = new;
        }
        else
        {
            par->rptr = new;
        }
    }
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->lptr);
        printf(" %d ", root->data);
        inorder(root->rptr);
    }
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf(" %d ", root->data);
        preorder(root->lptr);
        preorder(root->rptr);
    }
}
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->lptr);
        postorder(root->rptr);
        printf(" %d ", root->data);
    }
}
// void levelOrder
int main()
{
    int n, ch;
    printf("1.Create a BST\n");
    printf("2.Inorder traversal\n");
    printf("3.Preorder traversal\n");
    printf("4.Postorder traversal\n");
    printf("5.Search a node\n");
    printf("6.Delete a node\n");
    printf("7.Exit\n");
    while (1)
    {
        printf("Enter your choice!!\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the data value :\n");
            scanf("%d", &n);
            create(n);
            break;
        case 2:
            inorder(root);
            printf("\n");
            break;
        case 3:
            preorder(root);
            printf("\n");
            break;
        case 4:
            postorder(root);
            printf("\n");
            break;
        case 7:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Wrong choice. Try Again!!\n");
            continue;
        }
    }
    return 0;
}