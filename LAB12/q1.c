/*1. Write a C program to the following sorting 
operations on the give sequence in ascending 
order

1. Merge Sort
2. Quick Sort*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *n,int *m){
    int temp=n;
    n=m;
    m=temp;
}

void merge(int arr[],int l,int mid,int r){
    int i,j,k;
    int n1=mid-l+1;
    int n2=r-mid;
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
    {
        L[i]=arr[l+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=arr[mid+1+j];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k++]=L[i++];
        }
        else
        {
            arr[k++]=R[j++];
        }
    }

    while(i<n1)
    {
        arr[k++]=L[i++];
    }
    while(j<n2)
    {
        arr[k++]=R[j++];
    }
}

void merge_sort(int arr[],int l,int r){
    int mid;
    if(l<r)
    {
        int mid=(l+(r-1))/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
    else
    {
        return;
    }
}


int partition(int arr[],int l, int h){
    int pivot=arr[h];
    int i=l-1;
    for(int j=l;j<h;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return (i+1);
}
void quick_sort(int arr[], int l,int h){
    if(l<h)
    {
        int pi=partition(arr,l,h);
        quick_sort(arr,l,pi-1);
        quick_sort(arr,pi+1,h);
    }
}

void display(int arr[],int size){
    printf("\nThe array is : ");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}

int main(){
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    
    int ch,again;
    do
    {

        printf("\n\t\tSorting\t\t\n");
        printf("\n0. Display\n");
        
        printf("\n1. Merge Sort\n");
        printf("\n2. Quick Sort\n");
        printf("\n3. Exit\n");
        printf("\nEnter Your Choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 0:
            display(arr,n);
            break;
        
        case 1:
            merge_sort(arr,0,n-1);
            printf("\nAfter Sorting\n");
            display(arr,n);
            break;
        case 2:
            quick_sort(arr,0,n-1);
            printf("\nAfter Sorting\n");
            display(arr,n);
            break;
        case 3:
            exit(1);
            break;
        default:
            printf("\nIncorrect Entry! Try Again.\n");
            break;
        }
		printf("\nTry Another Method? (Press 1 for Yes / Press 0 for No :)\t");
		scanf("%d", &again);
    } while (again==1);

}