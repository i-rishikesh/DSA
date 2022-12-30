//Wap to check palinrome using double ended queue.
#include<stdio.h>
#define size 6
int deque[size];
int f=-1,r=-1;

void palindrome()
{
    int p=1;
    int i=f+1;
    // for(int x=f;x<=r;x++)
    // {
    //     if(deque[x]!=deque[size-x])
    //     {
    //         p=0;
    //         break;
    //     }
    // }
    int j=r;
    while(i!=r+1)
    {
        if(deque[i]!=deque[j])
        {
            p=0;
            break;
        }
        //printf("%d ",q[i]);
        i=(++i)%size;
        j=(--j)%size;
    }
    if(p)
        printf("Palindrome");
    else
        printf("Not Palindrome");
}
void insert_front(int x)    
{    
    if((f==0 && r==size-1) || (f==r+1))    
    {    
        printf("Overflow");    
    }    
    else if((f==-1) && (r==-1))    
    {    
        f=r=0;    
        deque[f]=x;    
    }    
    else if(f==0)    
    {    
        f=size-1;    
        deque[f]=x;    
    }    
    else    
    {    
        f=f-1;    
        deque[f]=x;    
    }   
}    
        
void insert_rear(int x)    
{    
    if((f==0 && r==size-1) || (f==r+1))    
    {    
        printf("Overflow");    
    }  
     else
    {
        deque[++r%size]=x;
    }   
    
}
int main(){
    insert_front(1);    
    insert_front(2);    
    insert_rear(3);    
    insert_rear(3);    
    insert_rear(2);
    insert_front(1);
    palindrome();
}