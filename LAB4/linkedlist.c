#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;

};
void traversal(struct Node *ptr )
{
    while(ptr!=NULL)
    {
    printf("%d \n",ptr->data);
    ptr=ptr->next;
    }
}
int main() 
{
    struct Node*start;
    struct Node*start1;
    struct Node*start2;

    start=(struct Node*) malloc(sizeof(struct Node));
    start1=(struct Node*) malloc(sizeof (struct Node));
    start2=(struct Node*) malloc(sizeof(struct Node));
start->data=7;
start->next=start1;

start1->data=11;
start1->next=start2;

start2->data=66;
start2->next=NULL;
traversal(start);
return 0;

}