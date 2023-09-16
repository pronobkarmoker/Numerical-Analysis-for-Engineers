#include <stdio.h>

#define MAX_SIZE 100

void multiplyMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int m, int n, int p)
{
    if (n != p)
    {
        printf("Matrices are not compatible for multiplication.\n");
        return;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int m, n, p;

    printf("Enter the number of rows (m) for matrix A: ");
    scanf("%d", &m);
    printf("Enter the number of columns (n) for matrix A: ");
    scanf("%d", &n);

    int matrixA[MAX_SIZE][MAX_SIZE];
    printf("Enter the elements of matrix A:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("Enter the number of columns (p) for matrix B: ");
    scanf("%d", &p);

    int matrixB[MAX_SIZE][MAX_SIZE];
    printf("Enter the elements of matrix B:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            scanf("%d", &matrixB[i][j]);
        }
    }

    int resultMatrix[MAX_SIZE][MAX_SIZE];
    multiplyMatrices(matrixA, matrixB, resultMatrix, m, n, p);

    if (n == p)
    {
        printf("Result Matrix (A x B):\n");
        printMatrix(resultMatrix, m, p);
    }

    return 0;
}
