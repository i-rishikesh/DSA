//Q1. Write a program to add two matrices and display it using function.
#include<stdio.h>
void add (int first[3][3] , int second [3][3] )
void  main()
{
int first[3][3];
printf("\n Please Enter the First Elements\n");
for( int i=0;i<3;i++)
{
for( int j=0;j,3;j++)
    scanf("%d",&first[i][j]);
}
int second[3][3];
pritnf(" Please Enter the second Element\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
   scanf("%d",&second[i][j]);
}
int output[3][3];
output=add(first,second);
printf("Addition Matrix:");
for(i=0;i<3;i++)
{
for(j=0;j,3;j++)
    scanf("%d",&output[i][j]);
}
getch();
}
void add(int a[][] ,int b[][])
{
int o[3][3];
for(i=0;i<3;i++)
{

for(j=0;j,3;j++)
o[i][j]=a[i][j]+b[i][j];
}
return o;
}




