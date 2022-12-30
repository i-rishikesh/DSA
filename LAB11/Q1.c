#include <stdio.h>
int a[30],n;

void selection_sort()
{
    int i, j, smallest, temp;
    for (i=0; i<n; i++)
    {
        smallest = i;
        for (j=i+1; j<n; j++)
        {
            if (a[j] < a[smallest])
               smallest = j;
        }
        temp = a[i];
        a[i] = a[smallest];
        a[smallest] = temp;
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
    selection_sort();
    printf("\nAFTER SORTING\n");
    for(i=0;i<n;i++)
        printf("\n%d",a[i]);

}