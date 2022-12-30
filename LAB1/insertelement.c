//Q8.WAP to insert a new element in a specified position in the array.
#include<stdio.h>  
int main()  
{  
    int n, i, pos, num;  
    printf("Enter number of elements:");
    scanf("%d",&n);
    int a[n];
    printf("Enter integer numbers\n", (n));  
    for(i = 0; i < (n); i++)  
        scanf("%d", &a[i]);  
  
    printf("Enter the position where new number has to be inserted\n");  
    scanf("%d", &pos);  
  
    if(pos < n)  
    {  
        printf("Enter a new number to be inserted at position %d\n", pos);  
        scanf("%d", &num);  
        for(i = n; i > pos; i--)  
                a[i] = a[i - 1];  
  
        a[pos] = num;  
  
        printf("Array after inserting %d at position %d\n", num, pos);  
        for(i = 0; i < n; i++)  
            printf("%d\n", a[i]);  
    }  
    else  
    {  
        printf("cannot be inserted ");  
    }  
  
    printf("\n");  
  
    return 0;  
}  