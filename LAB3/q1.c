//Write a program to add two matrices and display it using function.
#include <stdio.h>
#include <stdio.h>
void readmatrix(int m[10][10], int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("Enter element [%d,%d] : ", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }
}
void printmatrix(int m[10][10], int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int a[10][10], b[10][10], result[10][10];
    int i, j, rows1, cols1, rows2, cols2;

    printf("Number of Rows of Matrix 1: ");
    scanf("%d", &rows1);
    printf("Number of Columns of Matrix 1: ");
    scanf("%d", &cols1);

    printf("\nEnter Elements of matrix 1:\n");
    readmatrix(a, rows1, cols1);

    printf("Number of Rows of Matrix 2: ");
    scanf("%d", &rows2);
    printf("Number of Columns of Matrix 2: ");
    scanf("%d", &cols2);

    printf("\nEnter Elements of Matrix 2: \n");
    readmatrix(b, rows2, cols2);

    if (rows1 == rows2 && cols1 == cols2)
    {
        for (i = 0; i < rows1; i++)
        {
            for (j = 0; j < cols1; j++)
            {
                result[i][j] = a[i][j] + b[i][j];
            }
        }
        printf("\nMatrix after adding:\n");
        printmatrix(result, rows1, cols1);
    }
    else
    {
        printf("\nMatrix can not be added, Number of Rows & Columns are Different");
    }
    return 0;
}