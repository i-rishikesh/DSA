#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* lptr;
    struct node* rptr;

};

struct node* newnode(int data)
{
    struct node* node=(struct node*) malloc(sizeof(struct node));
    node->data=data;
    node->lptr=NULL;
    node->rptr=NULL;
    return(node);
    
}
int max(struct node* node)
{
	if (node == NULL) {
		return 0;
	}

	int leftMax = max(node->lptr);
	int rightMax = max(node->rptr);

	int value = 0;
	if (leftMax > rightMax) {
		value = leftMax;
	}
	else {
		value = rightMax;
	}

	if (value > node->data) {
		value = node->data;
	}

	return value;
}

int minValue(struct node* node)
{
	if (node == NULL) {
		return 100;
	}

	int leftMax = minValue(node->lptr);
	int rightMax = minValue(node->rptr);

	int value = 0;
	if (leftMax < rightMax) {
		value = leftMax;
	}
	else {
		value = rightMax;
	}

	if (value < node->data) {
		value = node->data;
	}

	return value;
}


int isBST(struct node* node)
{
	if (node == NULL)
		return 1;
 
	if (node->lptr != NULL
		&& max(node->lptr) > node->data)
		return 0;

	
	if (node->rptr != NULL&& minValue(node->rptr) < node->data)
		return 0;

	
	if (!isBST(node->lptr) || !isBST(node->rptr))
		return 0;

	return 1;
}


int main()
{
	struct node* root = newnode(8);
	root->lptr = newnode(3);
	root->rptr = newnode(5);
	root->lptr->lptr = newnode(7);
	root->lptr->rptr = newnode(9);

	
	if (isBST(root))
		printf("Is BST");
	else
		printf("Not a BST");

	
	return 0;
}