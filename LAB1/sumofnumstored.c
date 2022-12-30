//Q2. WAP to find out the sum of the numbers stored in an array of integers.
#include <stdio.h>

void main() 
{
    int n, sum=0; 
    printf("Enter the number of elements you want to input: ");
    scanf("%d",&n);
  
    int arr[n];
    for(int i=0; i<n; i++) {
        printf("Enter an integer for index %d: ", i);
        scanf("%d",&arr[i]);
    }
     printf("\n\nThe integers entered are: \n");
  
    for(int i=0; i<n; i++) 
    {
        printf("%d\n",arr[i]);
        sum+=arr[i];
    }
    printf("\nSum of the elements is %d", sum);
}
