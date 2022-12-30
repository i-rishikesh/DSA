#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int val;
    int row;
    int column;
    struct Node *ne;
} * s = '\0';
void create(struct Node ** start, int nz,int rw, int c )
{
    struct Node *t, *r;
    t = *start;
    if (t == '\0')
    {
        t = (struct Node *) malloc (sizeof(struct Node));
        t->val = nz;
        t->row = rw;
        t->column = c;
        t->ne = '\0';
        *start = t;
 
    }
    else
    {
        while (t->ne != '\0')
            t = t->ne;
        r = (struct Node *) malloc (sizeof(struct Node));
        r->val = nz;
        r->row = rw;
        r->column = c;
        r->ne = '\0';
        t->ne = r;
 
    }
}
void PrintList(struct Node* start)
{
    struct Node *t, *r, *s;
    t = r = s = start;
    printf("Row_position :~   ");
    while(t != '\0')
    {
        printf("%d ", t->row);
        t = t->ne;
    }
    printf("\n");
    printf("Column_postion :~ ");
    while(r != '\0')
    {
        printf("%d ", r->column);
        r = r->ne;
    }
    printf("\n");
    printf("Value :~          ");
    while(s != '\0')
    {
        printf("%d ", s->val);
        s = s->ne;
    }
    printf("\n");
}
void add(struct Node * s1, struct Node * s2)
{
    struct Node * t1 = s1, * t2 = s2;
    while (t1 != '\0' && t2 != '\0')
    {
        if (t1->row < t2->row)
        {
            create(&s,t1->val,t1->row,t1->column);
            t1 = t1->ne;
        }
        else if (t1->row == t2->row)
        {
            if (t1->column < t2->column){create(&s,t1->val,t1->row,t1->column);}
            else if (t1->column == t2->column){create(&s,t1->val+t2->val,t1->row,t1->column);}
            else {create(&s,t2->val,t1->row,t2->column);}
            t1 = t1->ne;
            t2 = t2->ne;
        }
        else
        {
            create(&s,t2->val,t2->row,t2->column);
            t2 = t2->ne;
        }
    }
    while (t1 != '\0')
    {
        create(&s,t1->val,t1->row,t1->column);
        t1 = t1->ne;
    }
    while (t2 != '\0')
    {
        create(&s,t2->val,t2->row,t2->column);
        t2 = t2->ne;
    }
}
void main()
{
    int m1[4][5] =
    {
        {0 , 0 , 3 , 0 , 4 },
        {0 , 0 , 5 , 7 , 0 },
        {0 , 0 , 0 , 0 , 0 },
        {0 , 2 , 6 , 0 , 0 }
    };
    int m2[4][5] =
    {
        {5 , 0 , 3 , 0 , 8 },
        {0 , 0 , 5 , 0 , 0 },
        {0 , 9 , 0 , 0 , 0 },
        {0 , 0 , 6 , 0 , 3 }
    };
    struct Node * s1 = '\0', * s2 = '\0';
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            if (m1[i][j] != 0)
                create(&s1, m1[i][j], i, j);
    printf("First Matrix :~ \n");
    PrintList(s1);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            if (m2[i][j] != 0)
                create(&s2, m2[i][j], i, j);
    printf("Second Matrix :~ \n");
    PrintList(s2);
    add(s1,s2);
    PrintList(s);
}