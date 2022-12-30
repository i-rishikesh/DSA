/*Q5.Given a array, WAP to print the next greater element (NGE) for every element.
The next greater element for an element x is the first greater element on the right
side of x in array. Elements for which no greater element exist, consider next
greater element as -1. E.g. For the input array [2, 5, 3, 9, 7], the next greater
elements for each elements are as follows.*/
#include<stdio.h>
void printNGE(int arr[], int n)
{
	int next, i, j;
	for (i=0; i<n; i++)
	{
		next = -1;
		for (j = i+1; j<n; j++)
		{
			if (arr[i] < arr[j])
			{
				next = arr[j];
				break;
			}
		}
		printf("%d\n", next);
	}
}

int main()
{
	int arr[]= {2, 5, 3, 9, 7};
	int n = sizeof(arr)/sizeof(arr[0]);
	printNGE(arr, n);
	return 0;
}