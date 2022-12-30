//Q7.WAP to remove a specific element from the array
#include<stdio.h>
void main()
{
    int key,n, i, index = -1;
    printf("Enter number of element in array:");
    scanf("%d",&n);
    int a[n];
     for(int i=0; i<n; i++) 
     {
        printf("Enter an integer for index %d: ", i);
        scanf("%d",&a[i]);
    }
     printf("Enter element to delete\n");
    scanf("%d",&key);
    
    for(i = 0; i < n; i++)
    {
        if(a[i] == key)
        {
            index = i;
            break;
        }
    }
     if(index != -1)
    {
        
        for(i = index; i < n - 1; i++)
            a[i] = a[i+1];

        printf("New Array : ");
        for(i = 0; i < n - 1; i++)
            printf("%d ",a[i]);
    }
    else
        printf("Element Not Found\n");

}