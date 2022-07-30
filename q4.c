/*Given an unsorted array of size n, WAP to find and display the number of
elements between two elements a and b (both inclusive). E.g. Input : arr = [1, 2,
2, 7, 5, 4], a=2 and b=5, Output : 4 and the numbers are: 2, 2, 7, 5.*/
#include <stdio.h>

int main()
{
    int n, i, a, b, c = 0;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements of array: ");

    int arr[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nEnter lower limit element & upper limit element respectively: ");
    scanf("%d %d", &a, &b);
    int arj[10];
    for (i = 0; i < n; i++)
    {
        if (arr[i] == a || arr[i] == b)
        {
            c++;
        }

        if (arr[i] > a && arr[i] < b)
        {
            c++;
        }
    }
    printf("Number of elements in between two elements (Both Inclusive) = %d", c);
    printf("");

    return 0;
}