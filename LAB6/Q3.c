#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char name[16];
    int roll;
    float cgpa;
    char adr[16];
    int branch;
    struct node * ne;
} * end;
struct head
{
    int c;
    struct node * ne;
} * start;
void create()
{
    struct node * n = (struct node *)malloc(sizeof(struct node));
    printf("Enter Name :~ ");
    scanf("%s",&n->name);
    printf("Enter Roll No. :~ ");
    scanf("%i",&n->roll);
    printf("Enter C.G.P.A :~ ");
    scanf("%f",&n->cgpa);
    printf("Enter Address :~ ");
    scanf("%s",&n->adr);
    printf("Enter Branch No. :~ ");
    scanf("%i",&n->branch);
    n->ne = '\0';
    if (start->ne == '\0')
    {
        start->ne = n;
        end = n;
    }
    else
    {
        end->ne = n;
        end = n;
    }
}
void display()
{
    struct node * n = start->ne;
    while (n != '\0')
    {
        printf("Name :~ %s\n",n->name);
        printf("Roll No. :~ %i\n",n->roll);
        printf("C.G.P.A :~ %0.2f\n",n->cgpa);
        printf("Address :~ %s\n",n->adr);
        printf("Branch No. :~ %i\n\n",n->branch);
        n = n->ne;
    }
}
void disno(){printf("No. Of Records Present Are :~ %i\n",start->c);}
void disbac(int x)
{
    struct node * n = start->ne;
    while (n != '\0')
    {
        if (n->branch == x)
        {
            printf("Name :~ %s\n",n->name);
            printf("Roll No. :~ %i\n",n->roll);
            printf("C.G.P.A :~ %0.2f\n",n->cgpa);
            printf("Address :~ %s\n",n->adr);
            printf("Branch No. :~ %i\n",n->branch);
        }
        n = n->ne;
    }
}
void dis75(int x)
{
    struct node * n = start->ne;
    while (n != '\0')
    {
        if (n->branch == x && n->cgpa >= 7.5)
        {
            printf("Name :~ %s\n",n->name);
            printf("Roll No. :~ %i\n",n->roll);
            printf("C.G.P.A :~ %0.2f\n",n->cgpa);
            printf("Address :~ %s\n",n->adr);
            printf("Branch No. :~ %i\n",n->branch);
        }
        n = n->ne;
    }
}
void main()
{
    start = (struct head *)malloc(sizeof(struct head));
    start->c = 0;
    start->ne = '\0';
    int n, s, z = 1;
    printf("Enter No. Of Nodes To Add :~ ");
    scanf("%i",&n);
    for (int i = 0 ; i < n ; i++)
    {
        create();
        start->c++;
    }
    printf("1-> Print List\n");
    printf("2-> Print Count\n");
    printf("3-> Display Data Of Department\n");
    printf("4-> Display Data Of Department With 7.5+ C.G.P.A\n");
    printf("5-> Exit Program\n");
    while(z)
    {
        printf("Enter Your Choice :~ ");
        scanf("%i",&n);
        if (n == 1){display();}
        else if (n == 2){disno();}
        else if (n == 3)
        {
            printf("Enter Department No. :~ ");
            scanf("%i",&s);
            disbac(s);
        }
        else if (n == 4)
        {
            printf("Enter Department No. :~ ");
            scanf("%i",&s);
            dis75(s);
        }
        else if (n == 5){z = 0;}
        else {printf("Enter Valid Command\n");}
    }
}