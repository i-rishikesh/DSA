#include<stdio.h>
int a[30],n;
void insertion_sort()
{
  int i, element, j; 
    for (i = 1; i < n; i++) 
    { 
        element = a[i]; 
        j = i - 1; 
    
    while (j >= 0 && a[j] > element) 
    { 
            a[j + 1] = a[j]; 
            j = j - 1; 
        } 
        a[j + 1] = element;  
}
}

int main()
{
    int i;
    printf("\nenter size of array\n");
    scanf("%d",&n);
    printf("\nEnter the  element in array\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    insertion_sort();
    printf("\nAFTER SORTING insertion sorting\n");
    for(i=0;i<n;i++)
        printf("\n%d",a[i]);
}