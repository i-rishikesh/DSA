//Q1. Write a program to add two matrices and display it using function.
#include<stdio.h>
void add(int [100][100], int [100][100], int, int);
int main()
{
    int a[100][100], b[100][100], r,c,i,j;
    printf("Enter no. of rows\n");
    scanf("%d", &r);
    printf("Enter no. of columns\n");
    scanf("%d", &c);
    printf("\nFirst Matrix\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("\nEnter element %d%d", i,j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nSecond Matrix\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("Enter element %d%d", i,j);
            scanf("%d", &b[i][j]);
        }
    }
    add(a, b, r, c);
    return 0;
}

void add(int a[100][100], int b[100][100], int r, int c)
{
    int sum[100][100], i, j;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            sum[i][j]=a[i][j]+b[i][j];
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            printf("%d\t", sum[i][j]);


}
