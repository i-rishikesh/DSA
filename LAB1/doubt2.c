// WAP to remove a specific element from the array
#include <stdio.h>
int main()
{
    int n, k, i,j, flag = 0;
    printf("Enter the no. of elements you want in an array: ");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter the value of element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\nThe elements of the array are: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\nEnter the element which you wish to delete from the array: ");
    scanf("%d", &k);
  
    
    for (i = 0; i < n; i++)
    {
        for(j=i+1; j<n;j++)
        {
        if (k == arr[i])
        {
            flag = 1;
            arr[j] = arr[j + 1];
            n=n-1;
            j=i;
        }
    }
    if (flag == 0)
    {
        printf("\nElement not found in the array.");
    }
    if (flag == 1)
    {

        printf("\nNew array is: ");
        for (i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);

        }
    }
    return 0;
}
}
