#include <stdio.h>

int matrixInput(int N, int M, int (*Pmatrix)[M]) //Function that inputs numbers into the matrix
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            printf("Please enter value : ");
            scanf("%d", &Pmatrix[i][j]);
        }
    }
    return 0;
}

int matrixPrint(int N, int M, int (*Pmatrix)[M]) //Function that prints the numbers from the matrix
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            printf("%d ", Pmatrix[i][j]);
        }
        printf("\n");
    }
}

int matrixDiagonalPrint(int N, int M, int (*Pmatrix)[M]) //Function that finds the main diagonal
{
    printf("Main Diagonal: ");
    for(int i = 0; i< N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(i==j) //The number of the row should be equal to the number of the column
            {
                printf("%d ", Pmatrix[i][j]);
            }
        }
    }
    return 0;
}

int matrixReverseDiagonalPrint(int N, int M, int (*Pmatrix)[M]) //Function that finds the reverse diagonal
{
    printf("Reverse Diagonal: ");
    for(int i = 0; i< N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            if(i + j == N - 1 ||i + j == M - 1) //The difference should be equal to the size of the matrix
            {
                printf("%d ", Pmatrix[i][j]);
            }
        }
    }
    return 0;
}

int matrixOverDiagonalPrint(int N, int M, int (*Pmatrix)[M]) //Prints the numbers over the diagonal of the matrix
{
    printf("Elements above Main Diagonal: ");
    for(int i = 0; i<N; i++)
    {
        for(int j = i + 1; j<M; j++) //The idea here is that you start from the second column and go over the diag
        {
            printf("%d ", Pmatrix[i][j]);
        }
    }
    return 0;
}

int matrixUnderDiagonalPrint(int N, int M, int (*Pmatrix)[M]) //Prints the numbers under the diagonal of the matrix
{
    printf("Elements under Main Diagonal: ");
    for(int i = 1; i<N; i++) // Starts from the second row
    {
        for(int j = 0; j < i; j++) // Goes beyond the diagonal
        {
            printf("%d ", Pmatrix[i][j]);
        }
    }
    return 0;
}
int main() {
    //Initialization
    int N = 3, M = 3;
    int array[N][M];
    matrixInput(N, M, array);
    matrixPrint(N, M, array);
    printf("\n");
    matrixDiagonalPrint(N, M, array);
    printf("\n");
    matrixReverseDiagonalPrint(N, M, array);
    printf("\n");
    matrixOverDiagonalPrint(N, M, array);
    printf("\n");
    matrixUnderDiagonalPrint(N, M, array);
    return 0;
}
