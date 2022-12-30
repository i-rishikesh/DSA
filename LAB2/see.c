/WAP to search an element in an array of n numbers
#include<stdio.h>
int main()
{
    int n,i,e;
    printf("Enter the no. of elements:");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements:");
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    printf("Enter the element to be searched:");
    scanf("%d", &e);
    search(int a, int n, int e);
    return 0;
}


    void search(int arr, int n1, int el)
    {
    int flag=0;
    for(int i=0;i<n1;i++)
    {
        if (arr[i]==el)
        {
            flag=1;
            printf("Element found at index %d", i+1);
        }

    }
    if (flag==0)
        printf("Element not found");
    }