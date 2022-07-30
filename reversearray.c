//Q1.WAP to reverse the contents of a array of n elements.
#include <stdio.h>
int main()
{
    int n,i,t;
    printf("Enter number of element in array:");
    scanf("%d",&n);
    int a[n];

    printf("\n\nThe integers entered are: \n");

    for(i=0; i<n; i++)
    scanf("%d",&a[i]);

    for(int i = 0; i<n/2; i++){
        t = a[i];
        a[i] = a[n-i-1];
        a[n-i-1] = t;
}  
   printf("\nReversed array:");
   for(int i = 0; i < n; i++)
        
        printf("%d  ", a[i]);

   
}