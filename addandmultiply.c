//Q5.WAP Input N element into an array.find out sum of all even number and multiply all odd no.
#include <stdio.h>
void main()
{
    int i,n,oddmultiplication=1,evenSum=0;
     printf("Enter the number of elements you want to input: ");
    scanf("%d",&n);

    int a[n];
    for(int i=0; i<n; i++) {
        printf("Enter an integer for index %d: ", i);
        scanf("%d",&a[i]);
    }


    printf("\n\nThe integers entered are: \n");

    for(i=0; i<n; i++)
    {
        if(a[i]%2==0)
        {
        evenSum=evenSum+a[i];
        }
    else{
             oddmultiplication=oddmultiplication*a[i];
        }
    }
    printf("The multiplication of all odd numbers are: %d",oddmultiplication);
    printf("\nThe sum of even numbers are: %d",evenSum);
}