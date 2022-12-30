#include<stdio.h>
#include<stdlib.h>
struct node
{
    int d;
    struct node * pre;
    struct node * ne;
}* start = '\0' , * last = '\0';
void create(int x)
{
    struct node * n = (struct node *)malloc(sizeof(struct node));
    n->d = x;
    n->ne = '\0';
    n->pre = '\0';
    if (start == '\0')
    {
        start = n;
        last = n;
    }
    else
    {
        last->ne = n;
        n->pre = last;
        last = n;
    }
}
void prfor()
{
    struct node * n = start;
    while (n != '\0')
    {
        printf("%i \n",n->d);
        n = n->ne;
    }
}
void prbac()
{
    struct node * n = last;
    while (n != '\0')
    {
        printf("%i \n",n->d);
        n = n->pre;
    }
}
void inaf(int x, int y)
{
    struct node * s = start, * n = (struct node *)malloc(sizeof(struct node));
    n->d = x;
    n->ne ='\0';
    n->pre = '\0';
    while (s->d != y && s != '\0'){s = s->ne;}
    if (s == last)
    {
        s->ne = n;
        n->pre = s;
        last = n;
    }
    else if (s != '\0')
    {
        n->ne = s->ne;
        n->pre = s;
        s->ne->pre = n;
        s->ne = n;
    }
    else{printf("Entered Element Not Present In List");}
}
void inbf(int a, int s)
{
	struct node * x = (struct node *)malloc(sizeof(struct node)),* n = start;
	while(n->d != s && n != '\0'){n = n->ne;}
    if (n != '\0')
    {
        x->d = a;
        x->ne = '\0';
        x->pre = '\0';
        if (n->pre == '\0')
        {
            x->ne = n;
            n->pre = x;
            start = x;
        }
        else
        {
            x->ne = n;
            n->pre->ne = x;
            x->pre = n->pre;
            n->pre = x;
        }
    }
    else{printf("Entered Element Not Present In List");}
}
void delpos(int x)
{
	struct node * n = start;
	while(n->d != x && n != '\0'){n = n->ne;}
	if (n == last)
    {
        last = n->pre;
        n->pre->ne = '\0';
        free(n);
    }
    else if (n == start)
    {
        start = n->ne;
        n->ne->pre = '\0';
        free(n);
    }
    else if (n != '\0')
    {
	    n->pre->ne = n->ne;
        n->ne->pre = n->pre;
	    free(n);
    }
    else{printf("Entered Element Not Present In List");}
}
void addfirst(int a)
{
    struct node * n = (struct node *)malloc(sizeof(struct node));
    n->d = a;
    n->pre = '\0';
    n->ne = start;
    start->pre = n;
    start = n;
}
void delfirst()
{
    struct node * n = start;
    n->ne->pre = '\0';
    start = n->ne;
    free(n);
}
void rev()
{
    struct node * n = start, * s = last;
    while ((n != s) && (n->pre != s))
    {
        int t = n->d;
        n->d = s->d;
        s->d = t;
        n = n->ne;
        s = s->pre;
    }
}
void main()
{
    int n, s, z = 1, m;
    printf("Enter No. Of Nodes To Add :~ ");
    scanf("%i",&n);
    printf("Enter Values To Enter :~ ");
    for (int i = 0 ; i < n ; i++)
    {
        scanf("%i",&s);
        create(s);
    }
    printf("1-> Print List\n");
    printf("2-> Print List In Rev Order\n");
    printf("3-> Insert Node After Given Data\n");
    printf("4-> Insert Node Before Given Data\n");
    printf("5-> Delete Value\n");
    printf("6-> Add First Node\n");
    printf("7-> Delete First Node\n");
    printf("8-> Reverse Nodes\n");
    printf("9-> Exit Program\n");
    while(z)
    {
        printf("Enter Your Choice :~ ");
        scanf("%i",&n);
        if (n == 1){prfor();}
        else if (n == 2){prbac();}
        else if (n == 3)
        {
            printf("Enter Value :~ ");
            scanf("%i",&s);
            printf("Enter Data To Be Added After :~");
            scanf("%i",&m);
            inaf(s,m);
        }
        else if (n == 4)
        {
            printf("Enter Value :~ ");
            scanf("%i",&s);
            printf("Enter Data To Be Added Before :~");
            scanf("%i",&m);
            inbf(s,m);
        }
        else if (n == 5)
        {
            printf("Enter Value To Delete :~ ");
            scanf("%i",&s);
            delpos(s);
        }
        else if (n == 6)
        {
            printf("Enter Value To Add :~ ");
            scanf("%i",&s);
            addfirst(s);
        }
        else if (n == 7){delfirst();}
        else if (n == 8){rev();}
        else if (n == 9){z = 0;}
        else {printf("Enter Valid Command\n");}
    }
}