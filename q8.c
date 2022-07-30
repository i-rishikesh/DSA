//8. let a be nXn square matrix. WAP by using appropriate user defined
//functions for the following: a) find the number of nonzero elements in
//A b) find the sum of the elements above the leading diagonal. c)
///Display the elements below the mirror diagonal. d) find the product of
//the diagonal elements.
#include <stdio.h>
void NonZeroElements(int (*Arr)[5], int n)
{
int a = 0;
for (int i = 0; i < n; i++)
{
for (int j = 0; j < n; j++)
{
if (*(*(Arr + i) + j) != 0)
a++;
}
}
printf("Number of non-zero elements in array: %d\n", a);
}
void sumOfElementsAboveLeadingDiagonal(int (*Arr)[5], int n)
{
int a;
for (int i = 0; i < n; i++)
{
for (int j = 0; j < n; j++)
{
if (j > i)
a += *(*(Arr + i) + j);
}
}
printf("Sum Of Elements Above Leading Diagonal: %d\n", a);
}
void ElementsBelowMinorDiagonal(int (*Arr)[5], int n)
{
printf("Elements below the minor diagonal: \n");
for (int i = 0; i < n; i++)
{
for (int j = 0; j < n; j++)
{
if (j >= n - i)
printf(" %d", *(*(Arr + i) + j));
else
printf(" ");
}
printf("\n");
}
}
void ProductOfdiagonalElements(int (*Arr)[5], int n)
{
int a = 1;
for (int i = 0; i < n; i++)
{
for (int j = 0; j < n; j++)
{
if (i == j)
a *= *(*(Arr + i) + j);
}
}
printf("Product of leading diagnal Elements: %d\n", a);
}
int main()
{
int mat[5][5] = {
{00, 01, 02, 03, 04},
{10, 11, 12, 13, 14},
{20, 21, 22, 23, 24},
{30, 31, 32, 33, 34},
{40, 41, 42, 43, 44},
};
int n = 5;
NonZeroElements(mat, n);
sumOfElementsAboveLeadingDiagonal(mat, n);
ElementsBelowMinorDiagonal(mat, n);
ProductOfdiagonalElements(mat, n);
}