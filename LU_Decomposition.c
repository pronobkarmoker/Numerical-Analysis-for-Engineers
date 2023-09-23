#include <stdio.h>

#define MAX_SIZE 100

void printMatrix(double matrix[MAX_SIZE][MAX_SIZE], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%.6lf\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int luDecomposition(double A[MAX_SIZE][MAX_SIZE], double L[MAX_SIZE][MAX_SIZE], double U[MAX_SIZE][MAX_SIZE], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int k = i; k < n; k++)
        {
            double sum = 0.0;
            for (int j = 0; j < i; j++)
            {
                sum += L[i][j] * U[j][k];
            }
            U[i][k] = A[i][k] - sum;
        }

        for (int k = i; k < n; k++)
        {
            if (i == k)
            {
                L[i][i] = 1.0;
            }
            else
            {
                double sum = 0.0;
                for (int j = 0; j < i; j++)
                {
                    sum += L[k][j] * U[j][i];
                }
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }

    return 1; // Success
}

int main()
{
    int n;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    double matrix[MAX_SIZE][MAX_SIZE];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &matrix[i][j]);
        }
    }

    double L[MAX_SIZE][MAX_SIZE] = {0}; // Initialize L matrix
    double U[MAX_SIZE][MAX_SIZE] = {0}; // Initialize U matrix

    if (luDecomposition(matrix, L, U, n))
    {
        printf("Lower Triangular (L) Matrix:\n");
        printMatrix(L, n);

        printf("Upper Triangular (U) Matrix:\n");
        printMatrix(U, n);
    }

    return 0;
}
