#include<stdio.h>
int main()
{
    int i,j,k,x;
    printf("No. of array elements?\n");
    scanf("%d",&x);
    int a[x];
    printf("Enter the integers",x);
    for (i=0;i<x;i++)
        scanf("%d", &a[i]); 
    for (i=0;i<x;i++)
    {
        for(j=i+1;j<x;j++)
        {
            if (a[i]==a[j])
            {
                for(k=j;k<-1;k++)
                {
                    a[k]=a[k+1];
                }
            x--;
            j--;
            }
        }
    }
    printf("\nNew Array:\n");
    for(i=0;i<x;i++)
        printf("%d\n",a[i]);
    return 0;
}