#include<stdio.h>
int stack[100];

void push(int top,int n)
{
    int x;
    if(top>=n-1)
    {
        printf("\noverflowed!!");
        
    }
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}

void pop(int top)
{
    if(top<=-1)
    {
        printf("\n underflowed!!");
    }
    else
    {
        printf("\n The popped elements is %d",stack[top]);
        top--;
    }
}

void display(int top)
{   
    if(top>=0)
    {
        printf("\n The elements in STACK \n");
        for(int i=top; i>=0; i--)
            printf("\n%d",stack[i]);
        printf("\n Press Next Choice");
    }
    else
    {
        printf("\n The STACK is empty");
    }
    
}
int main()
{   
    int choice,n,top,x,i;
    top=-1;
    printf("\n Enter the size of STACK:");
    scanf("%d",&n);
    printf("\n STACK OPERATIONS USING ARRAY\n\n");
    
    
    printf("\n 1.PUSH\n 2.POP\n 3.DISPLAY\n 4.EXIT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push(top,n);
                break;
            }
            case 2:
            {
                pop(top);
                break;
            }
            case 3:
            {
                display(top);
                break;
            }
            case 4:
            {
                printf("\n ::EXIT:: ");
                break;
            }
            default:
            {
                printf ("\n Please Enter your choice: ");
            }
                
        }
    }
    while(choice!=4);
    return 0;
}