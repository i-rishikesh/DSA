#include<stdio.h>
#include<stdlib.h>
struct list 
{
    int info;
    struct list *next;
}*start=NULL;
void addfirst(int num)
{
    struct list *ptr;
    ptr=(struct list *)malloc(sizeof(struct list));
    ptr->info=num;
    if(start==NULL)
    {
        ptr->next=NULL;
        start=ptr;
    }else 
    {
        struct list *p;
        p=start;
        ptr->next=p;
        start=ptr;
    }
}

void addlast(int num)
{
    struct list *ptr;
    ptr=(struct list *)malloc(sizeof(struct list));
    ptr->info=num;
    ptr->next=NULL;
    if(start==NULL)
    {
        start=ptr;
    }
    else 
    {
        struct list *p;
        p=start;
        while(p->next!=NULL)
            p=p->next;
        p->next=ptr;
    }
}

void delete()
{
    struct list *t;
    t=(struct list *)malloc(sizeof(struct list));
    if(start==NULL)
    {
        printf("no node is there");
    }
    else{
        struct  list *t2;
        t2=(struct list *)malloc(sizeof(struct list));
        t2=start;
        start=start->next;
        free(t2);
    }
}
void Deletelast()
    {
        struct node *t1;
        t1=(struct node *)malloc(sizeof (struct node));
        if(start==NULL)
        {
            start=t1;
        }
        else
        {
            struct node *t1;
            t1=(struct node *)malloc(sizeof (struct node));
            struct node *t2;
            t2=(struct node*)malloc(sizeof(struct node));
            t1=t2=start;
            while(t1->next!=NULL)
            {
                t2=t1;
                t1=t1->next
            }
            t2->next=NULL;
            free(t1);         
        }

    
    
    }
)
void show()
{
    int c=0;
    struct list *p;
    p=start;
    printf("START->");
    while(p->next!=NULL)
    {
        printf("%d->", p->info);
        c++;
        
        p=p->next;
    }
    printf("%d->", p->info);
    printf("NULL");
    printf("number of nodes:%d",c)
}
int main()
{
    int op;
    do
    {
        printf("\nlist operations");
        printf("\n1 to add at first");
        printf("\n2 to show list ");
        printf("\n3 to add at last");
        printf("\n4 delete first node");
        printf("\n5 delete last node");
        printf("\n0 to exit");
        printf("\nenter your choice : ");
        scanf("%d", &op);
        if(op==1)
        {
            int a;
            printf("\nenter the data : ");
            scanf("%d", &a);
            addfirst(a);
        }
        else if(op==2) show();
        else if(op==3)
        {
            int a;
            printf("\nenter data : ");
            scanf("%d", &a);
            addlast(a);
        }
        else if (op==4) delete();
    }while(op!=0);
    return 0;
}
