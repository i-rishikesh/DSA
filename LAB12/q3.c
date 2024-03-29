//WAP to implement a tree in post order 

#include <stdio.h>
#define MAX_SIZE 100
 
struct Node
{
    int data;
    struct Node *left, *right;
};
 
struct Stack
{
    int size;
    int top;
    struct Node* *array;
};

struct Node* newNode(int data)
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Stack* createStack(int size)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (struct Node*) malloc(stack->size * sizeof(struct Node));
    return stack;
}
 
int isFull(struct Stack* stack)
{ return stack->top - 1 == stack->size; }
 
int isEmpty(struct Stack* stack)
{ return stack->top == -1; }
 
void push(struct Stack* stack, struct Node* node)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = node;
}
 
struct Node* pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}
 
struct Node* peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top];
}
 
void postOrderIterative(struct Node* root)
{
    if (root == NULL)
        return;
     
    struct Stack* stack = createStack(MAX_SIZE);
    do
    {
        while (root)
        {
            if (root->right)
                push(stack, root->right);
            push(stack, root);
 
            root = root->left;
        }
 
        root = pop(stack);
 
        if (root->right && peek(stack) == root->right)
        {
            pop(stack); 
            push(stack, root); 
            root = root->right; 
            
        }
        else 
        {
            printf("%d ", root->data);
            root = NULL;
        }
    } while (!isEmpty(stack));
}
 

int main()
{
    
    struct Node* root = NULL;
    root = newNode(02);
    root->left = newNode(60);
    root->right = newNode(90);
    root->left->left = newNode(100);
    root->left->right = newNode(10);
    root->right->left = newNode(40);
    root->right->right = newNode(30);
    printf("Post order traversal of binary tree is :\n");
    printf("[");
    postOrderIterative(root);
    printf("]");
     
 
    return 0;
}