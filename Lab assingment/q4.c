//Write  a program to implement four number of D-queues in an array.
 #include<stdio.h>
    #include<stdlib.h>
    #define MAX 10
    int front1=-1,rear1=-1,front2=-1,rear2=-1,front3=-1,rear3=-1,front4=-1,rear4=-1;
    int queue[MAX];
    void insert1(int item)
    {
        if(rear1==MAX-1)
        {
            printf("Queue is full");
        }
        else
        {
            if(front1==-1)
            {
                front1=0;
            }
            rear1=rear1+1;
            queue[rear1]=item;
        }
    }
    void insert2(int item)
    {
        if(rear2==MAX-1)
        {
            printf("Queue is full");
        }
        else
        {
            if(front2==-1)
            {
                front2=0;
            }
            rear2=rear2+1;
            queue[rear2]=item;
        }
    }
    void insert3(int item)
    {
        if(rear3==MAX-1)
        {
            printf("Queue is full");
        }
        else
        {
            if(front3==-1)
            {
                front3=0;
            }
            rear3=rear3+1;
            queue[rear3]=item;
        }
    }
    void insert4(int item)
    {
        if(rear4==MAX-1)
        {
            printf("Queue is full");
        }
        else
        {
            if(front4==-1)
            {
                front4=0;
            }
            rear4=rear4+1;
            queue[rear4]=item;
        }
    }
    void delete1()
    {
        if(front1==-1)
        {
            printf("Queue is empty");
        }
        else
        {
            printf("Deleted element is %d",queue[front1]);
            front1=front1+1;
        }
    }
    void delete2()
    {
        if(front2==-1)
        {
            printf("Queue is empty");
        }
        else
        {
            printf("Deleted element is %d",queue[front2]);
            front2=front2+1;
        }
    }
    void delete3()
    {
        if(front3==-1)
        {
            printf("Queue is empty");
        }
        else
        {
            printf("Deleted element is %d",queue[front3]);
            front3=front3+1;
        }
    }
    void delete4()
    {
        if(front4==-1)
        {
            printf("Queue is empty");
        }
        else
        {
            printf("Deleted element is %d",queue[front4]);
            front4=front4+1;
        }
    }
    void display()
    {
        int i;
        if(front1==-1)
        {
            printf("Queue is empty");
        }
        else
        {
            printf("Queue elements are:");
            for(i=front1;i<=rear1;i++)
            {
                printf("%d ",queue[i]);
            }
        }
    }
    void main()
    {
        int choice,item;
        while(1)
        {
            printf("\n");
            printf("1.Insert element to queue1\n");
            printf("2.Insert element to queue2\n");
            printf("3.Insert element to queue3\n");
            printf("4.Insert element to queue4\n");
            printf("5.Delete element from queue1\n");
            printf("6.Delete element from queue2\n");
            printf("7.Delete element from queue3\n");
            printf("8.Delete element from queue4\n");
            printf("9.Display all elements of queue\n");
            printf("10.Quit\n");
            printf("Enter your choice:");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                    printf("Enter the element to be inserted:");
                    scanf("%d",&item);
                    insert1(item);
                    break;
                case 2:
                    printf("Enter the element to be inserted:");
                    scanf("%d",&item);
                    insert2(item);
                    break;
                case 3:
                    printf("Enter the element to be inserted:");
                    scanf("%d",&item);
                    insert3(item);
                    break;
                case 4:
                    printf("Enter the element to be inserted:");
                    scanf("%d",&item);
                    insert4(item);
                    break;
                case 5:
                    delete1();
                    break;
                case 6:
                    delete2();
                    break;
                case 7:
                    delete3();
                    break;
                case 8:
                    delete4();
                    break;
                case 9:
                    display();
                    break;
                case 10:
                    exit(1);
                default:
                    printf("Wrong choice");
            }
        }
    }
    