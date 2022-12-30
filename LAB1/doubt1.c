#include<stdio.h>
int main()
{
    int a[11], i, pos, num;
    printf("enter %d interger numbers \n", (11-1));
    for(i=0; i<(11-1); i++);
        scanf("%d",&a[i]);
    printf("enter the position where the new number has to be insert\n");
    scanf("%d", &pos);
    if(pos<11)
    {
        printf("enter the new number to be inserted at position %d\n",pos);
        scanf("%d",&num);
        for(i=11-1; i>pos; i--)
        a[i]=a[i-1];
        a[pos]=num;
        printf("array after inserting %d at position %d \n", num, pos);
        for(i=0; i<11; i++)
        printf("%d\n", a[i]);
    }
    else
    {
        printf("enter the podition which the range/size of the array\n");
    }
    printf("\n");
    return 0;
}