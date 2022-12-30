#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
}*start=NULL; 



int pop() {
    if (start == NULL) {
        printf("\nEMPTY STACK");
    } 
    else{
        struct Node *temp = start;
        int temp_data = start->data; 
        start = start->next; 
        free(temp); 
        return temp_data;
    }
}

void push(int value) {
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = value; 
    if (start == NULL) {
        n->next = NULL;
    } else {
        n->next = start; 
    }
    start = n; 
    printf("Node is Inserted\n\n");
}

void display() {
    
    if (start == NULL) {
        printf("Underflow!!\n");
    } else {
        printf("The stack data is: \n");
        struct Node *temp = start;
        while (temp->next != NULL) {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("%d\t\n\n", temp->data);
    }
}

int main() {
    int choice, value;
    printf("\n Stack using Linked List\n");
    while (1) {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            printf("Popped element is :%d\n", pop());
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\n Enter correct Choice!!\n");
        }
    }
}

