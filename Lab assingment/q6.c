//Write a program to construct a binary tree from given sequence of preorder and inorder traversals.
 /* program to construct tree using inorder and preorder traversals */
#include <stdio.h>
#include <stdlib.h>


struct node {
	int data;
	struct node* left;
	struct node* right;
};


int search(int  a[], int strt, int end, int value);
struct node* newNode(int data);


struct node*createTree(int in[], int pre[], int instart, int inlast)
{
	static int preIndex = 0;

	if (instart > inlast)
		return NULL;

	
	struct node* tNode = newNode(pre[preIndex++]);

	
	if (instart == inlast)
		return tNode;

	
	int inIndex = search(in, instart, inlast, tNode->data);

	
	tNode->left = createTree(in, pre, instart, inIndex - 1);
	tNode->right = createTree(in, pre, inIndex + 1, inlast);

	return tNode;
}


int search(int arr[], int strt, int end, int value)
{
	int i;
	for (i = strt; i <= end; i++) {
		if (arr[i] == value)
			return i;
	}
}


struct node* newNode(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}


void printInorder(struct node* node)
{
	if (node == NULL)
		return;


	printInorder(node->left);

	
	printf("%d ", node->data);

	
	printInorder(node->right);
}


int main()
{
	int  in[] = {4,3,2,1,5,6,7,8 };
	int pre[] = { 1,2,3,4,5,6,7,8 };
	int len = sizeof(in) / sizeof(in[0]);
	struct node* root = createTree(in, pre, 0, len - 1);

	
	printf("Inorder traversal of the constructed tree is \n");
	printInorder(root);
	
}
