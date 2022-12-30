//Q3. WAP to find the Trace(sum of the diagonal element) of a given mxn matrix using function
#include <stdio.h>
#include <stdlib.h>

int findTrace( int d, int** M){
    int trace = 0;
    for( int i = 0; i < d; i++ )
        trace += M[i][i];
    
    return trace;
}

int main(){
    
    int d;
    printf("Enter row/col count of matrix: ");
    scanf("%d", &d);

    
    int **M = (int **)malloc(d * sizeof(int *));
 
    
    for (int i = 0; i < d; i++) {
        M[i] = (int *)malloc(d * sizeof(int));
    }

    // Input
    printf("Enter the matrix: \n");
    for( int i = 0; i < d; i++ ){
        printf("Row %d: ", i+1);
        for( int j = 0; j < d; j++ )
            scanf("%d", &M[i][j]);
    }

    printf("Trace value of matrix is %d.\n", findTrace(d, M));
        

    
    return 0;
}
