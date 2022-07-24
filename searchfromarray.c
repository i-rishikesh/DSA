//Q6. WAP to search a particular number from the array.
#include <stdio.h> 
int main()

{
    int a[100],i,n,k;
   
    printf("Enter number  of the element in   array : ");
    scanf("%d", &n);
    printf("Enter elements in array : ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
     printf("Enter the key : ");
    scanf("%d", &k);
     
    for(i=0; i<n; i++)
    {
        if(a[i]==k)
        {
			printf("element found ");
            return 0;		 
        }

    }
    
	printf("element  not  found");
}