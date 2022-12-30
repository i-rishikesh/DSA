
#include <stdio.h>
#include <stdlib.h>
    struct Process
{
    int PID, cpuTime;
    struct Process *next;
} *first = NULL, *last = NULL;
struct Process *create(int PID, int cpuTime)
{
    struct Process *node = (struct Process *)malloc(sizeof(struct Process));
    node->cpuTime = cpuTime;
    node->PID = PID;
    node->next = NULL;
    return node;
}
void add(int PID, int cpuTime)
{
    struct Process *n = create(PID, cpuTime);
    if (first == NULL)
    {
        first = n;
        last = n;
        return;
    }
    // Otherwise
    last->next = n;
    n->next = first;
}
void execute(int T)
{
    first->cpuTime -= T;
    if (first->cpuTime <= 0)
    {
        // Last process
        if (first == last)
        {
            printf("All processes have finished executing.\n");
            exit(0);
        }
        printf("Process with PID %d finished executing.\n", first->PID);
        first = first->next;
        free(last->next);
        last->next = first;
    }
    else
    {
        // Since it's circular
        last = first;
        first = first->next;
        // Print something
        printf("Process with PID %d has been executed for given time slice.", last->PID);
        printf("\nRemaining CPU Time: %d ms\n", last->cpuTime);
    }
}
int main()
{
    while (1)
    {
        printf("1. Add process\n2. Execute\nYour choice: ");
        int in;
        scanf("%d", &in);
        if (in == 1)
        {
            int PID, cpuTime;
            printf("Enter PID and CPU Time: ");
            scanf("%d %d", &PID, &cpuTime);
            add(PID, cpuTime);
        }
        if (in == 2)
        {
            int tSlice;
            printf("Enter time slice: ");
            scanf("%d", &tSlice);
            execute(tSlice);
        }
    }
}