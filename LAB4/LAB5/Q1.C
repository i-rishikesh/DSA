#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

void create(struct node** p){
    struct node* t= (struct node*)malloc(sizeof(struct node)), *q= *p;
    printf("Enter data: ");
    scanf("%d",&t->data);
    t->prev= NULL;
    t->next= NULL;
    if (*p){
        while(q->next)
            q= q->next;
        q->next= t;
        t->prev= q;
    }
    else
        *p= t;
}

void forward(struct node* p){
    struct node* q= p;
    while (p){
        printf("%d ",p->data);
        p= p->next;
    }
    printf("\n");
}

void backward(struct node* p){
    struct node* q= p;
    while (p->next)
        p= p->next;
    while (p){
        printf("%d ",p->data);
        p= p->prev;
    }
    printf("\n");
}

void addafter(struct node** p){
    int key;
    struct node t= (struct node)malloc(sizeof(struct node)), *q= *p;
    printf("Enter data value to insert after: ");
    scanf("%d",&key);
    if (*p){
        while (q->next)
    }
}

int main(){
    struct node* q=NULL;
    int c=1;
    while (c!=0){
        printf("0: Exit\n1: Create/append\n2: Traverse forward\n3: Traverse backward\n>");
        scanf("%d",&c);
        printf("-------------------\n");
        switch(c){
            case 0:
                break;
            case 1:
                create(&q);
                break;
            case 2:
                forward(q);
                break;
            case 3:
                backward(q);
                break;
            default:
                printf("Error\n");
                break;
        }
        printf("-------------------\n");
    }
    create(&q);
    create(&q);
    create(&q);
    forward(q);
    backward(q);
}