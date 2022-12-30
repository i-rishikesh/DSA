//Implement a queue ADT
#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int q[100];
    int front, rear;
};
void initialise(struct Queue *q)
{
    q->front = -1;
    q->rear = -1;
}
void insert(struct Queue *q1, int n)
{
    if ((q1->front == 0 && q1->rear == 99) || (q1->front == q1->rear + 1))
    {
        printf("Overflow\n");
        return;
    }
    else
    {
        q1->front = 0;
        q1->rear = ((q1->rear) + 1) % 100;
        q1->q[q1->rear] = n;
    }
}
int delete (struct Queue *q1, int *n)
{
    if ((q1->front == -1 && q1->rear == -1))
    {
        return 0;
    }
    else if (q1->front == q1->rear)
    {
        q1->front = -1;
        q1->rear = -1;
        printf("The list is empty\n");
    }
    else
    {
        n = &q1->q[q1->front];
        q1->front = ((q1->front + 1)) % 100;
    }
    return *n;
}
void display(struct Queue *q1)
{
    int i;

    if ((q1->front == q1->rear) || (q1->front == -1 && q1->rear == -1))
    {
        printf("The list is empty\n");
    }
    else
    {
        i = q1->front;

        do

        {
            printf("%d", q1->q[i]);
            i = (i + 1) % 100;
        } while (i != ((q1->rear) + 1));
    }
}

int main()
{
    struct Queue q;
    int n, ch, val, prev;

    printf("Enter 1 to Insert\n");
    printf("Enter 2 to Delete\n");
    printf("Enter 3 to display\n");
    printf("Enter 4 to exit\n");
    initialise(&q);
    while (1)
    {
        printf("\nEnter your choice :\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter size of Queue :\n");
            scanf("%d", &n);

            printf("Enter the elements :\n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &val);
                insert(&q, val);
            }
            printf("The elements are: \n");
            display(&q);
            break;

        case 2:
            prev = delete (&q, &prev);
            if (prev != 0)
            {
                printf("The deleted item : %d\n", prev);
            }
            else
                printf("Underflow!!\n");
            break;

        case 3:
            printf("The elements are: \n");
            display(&q);
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Wrong choice!!\n");
            continue;
        }
    }
    return 0;
}