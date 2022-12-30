/*Write a menu driven program to perform the following operation on a BST
1.Create
2.Traverse in preorder
3 Traverse in inorder
4.Traverse in postorder
6.Search given element 
7.deletion*/
#include<stdio.h>
struct node
{
          int data;
          struct node *lptr;
          struct node *rptr;

};
struct node *create(struct node *node,int value)
{
    struct node *new;
    struct node *par;
    struct node *root;
    new= (struct node *) malloc(sizeof(struct node));
    new->data=value;
    new->lptr=NULL;
    new->rptr=NULL;
    par=NULL;
    node=root;
    if(node==NULL)
        {
        node = (struct node *) malloc(sizeof(struct node));
        node->data = value;
        node->lptr = NULL;
        node->rptr = NULL;
        }
    elseif(value<node->data)
         node->lptr=value;
    elseif(value>node->data)
        node->rptr=value;
    else
        return node;
}    
void traversepreorder(struct node *node,int level) 
{
        int i;
        if(node == NULL )
                return;
        else
    {
                display(node->rptr, level+1);
                printf("\n");
                for (i=0; i<level; i++)
                        printf("    ");
                printf("%d", node->data);
                display(node->lptr, level+1);
        }
}     
 int main()
 {
     struct node *root=NULL,*ptr;
     int choice,k;
     while(1)
     {
        printf("\n");
        printf("1.Create\n");
        printf("2.Traverse\n");
        printf("3.Exit\n");
        printf("Enter your choice");
        scanf("%d",&choice);

        switch(choice)
        {
            case1:printf("\nenter the value to create");
                scanf("%d",&k);
                        node = insert(node, k);
                        break;
        }
     }

 }   
