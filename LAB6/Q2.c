#include<stdio.h>
#include<stdlib.h>
struct node
{
	int d;
	struct node * ne;
} * start = '\0', * end;
void create(int x)
{
	struct node * n = (struct node *)malloc(sizeof(struct node));
	n->d = x;
	n->ne = start;
	if(start == '\0')
	{
		start = n;
		end = n;
	}
	else
	{
		end->ne = n;
		end = n;
	}
}
void print()
{
	struct node * n = start;
	while(n->ne != start)
	{
		printf("%i\n",n->d);
		n = n->ne;
	}
    printf("%i\n",n->d);
}
void addf(int x)
{
    struct node * n = (struct node *)malloc(sizeof(struct node));
	n->d = x;
	n->ne = start;
    end->ne = n;
    start = n;
}
void delf()
{
    struct node * n = start;
    end->ne = n->ne;
    start = n->ne;
    free(n);
}
void main()
{
    int n, s, z = 1;
    printf("Enter No. Of Nodes To Add :~ ");
    scanf("%i",&n);
    printf("Enter Values To List :~ ");
    for (int i = 0 ; i < n ; i++)
    {
        scanf("%i",&s);
        create(s);
    }
    printf("1-> Print List\n");
    printf("2-> Add First Node\n");
    printf("3-> Delete First Node\n");
    printf("4-> Exit Program\n");
    while(z)
    {
        printf("Enter Your Choice :~ ");
        scanf("%i",&n);
        if (n == 1){print();}
        else if (n == 2)
        {
            printf("Enter Value To Add :~ ");
            scanf("%i",&s);
            addf(s);
        }
        else if (n == 3){delf();}
        else if (n == 4){z = 0;}
        else {printf("Enter Valid Command\n");}
    }
}