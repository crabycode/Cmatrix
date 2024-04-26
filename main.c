#include <stdio.h>
#include <stdbool.h>

void matrixInput(int N, int M, int (*Pmatrix)[M]) //Function that inputs numbers into the matrix
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            printf("Please enter value : ");
            scanf("%d", &Pmatrix[i][j]);
        }
    }
    printf("\n");
}

void matrixPrint(int N, int M, int (*Pmatrix)[M]) //Function that prints the numbers from the matrix
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            printf("%d ", Pmatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void matrixDiagonalPrint(int N, int M, int (*Pmatrix)[M]) //Function that finds the main diagonal
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
    printf("\n");
}

void matrixReverseDiagonalPrint(int N, int M, int (*Pmatrix)[M]) //Function that finds the reverse diagonal
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
    printf("\n");
}

void matrixOverDiagonalPrint(int N, int M, int (*Pmatrix)[M]) //Prints the numbers over the diagonal of the matrix
{
    printf("Elements above Main Diagonal: ");
    for(int i = 0; i<N; i++)
    {
        for(int j = i + 1; j<M; j++) //The idea here is that you start from the second column and go over the diag
        {
            printf("%d ", Pmatrix[i][j]);
        }
    }
    printf("\n");
}

void matrixUnderDiagonalPrint(int N, int M, int (*Pmatrix)[M]) //Prints the numbers under the diagonal of the matrix
{
    printf("Elements under Main Diagonal: ");
    for(int i = 1; i<N; i++) // Starts from the second row
    {
        for(int j = 0; j < i; j++) // Goes beyond the diagonal
        {
            printf("%d ", Pmatrix[i][j]);
        }
    }
    printf("\n");
}

bool isMagical(int N, int (*Pmatrix)[N])
{
    int sum = 0, tempSum = 0;
    for (int j = 0; j < N; j++) // Calculate the sum of the first row
    {
        sum += Pmatrix[0][j];
    }

    for (int i = 1; i < N; i++) // Check sums of all rows
    {
        tempSum = 0;
        for (int j = 0; j < N; j++)
        {
            tempSum += Pmatrix[i][j];
        }
        if (tempSum != sum)
        {
            return false;
        }
    }

    for (int j = 0; j < N; j++) // Check sums of all columns
    {
        tempSum = 0;
        for (int i = 0; i < N; i++)
        {
            tempSum += Pmatrix[i][j];
        }
        if (tempSum != sum)
        {
            return false;
        }
    }

    tempSum = 0;
    for (int i = 0; i < N; i++) // Check sum of main diagonal
    {
        tempSum += Pmatrix[i][i];
    }
    if (tempSum != sum)
    {
        return false;
    }

    tempSum = 0;
    for (int i = 0; i < N; i++) // Check sum of secondary diagonal
    {
        tempSum += Pmatrix[i][N-1-i];
    }
    if (tempSum != sum)
    {
        return false;
    }

    return true;
}
int main() {
    //Initialization
    int N, M;
    printf("Please enter dimension N: ");
    scanf("%d", &N);
    printf("Please enter dimension M: ");
    scanf("%d", &M);
    int array[N][M];
    matrixInput(N, M, array);
    matrixPrint(N, M, array);
    matrixDiagonalPrint(N, M, array);
    matrixReverseDiagonalPrint(N, M, array);
    matrixOverDiagonalPrint(N, M, array);
    matrixUnderDiagonalPrint(N, M, array);
    if (isMagical(N, array))
    {
        printf("The matrix is magical.\n");
    }
    else
    {
        printf("The matrix is not magical.\n");
    }
    return 0;
}
