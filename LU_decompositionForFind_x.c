#include <stdio.h>

#define MAX_SIZE 3

void printVector(double vector[MAX_SIZE], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%.6lf\n", vector[i]);
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

void forwardSubstitution(double L[MAX_SIZE][MAX_SIZE], double b[MAX_SIZE], double y[MAX_SIZE], int n)
{
    for (int i = 0; i < n; i++)
    {
        y[i] = b[i];
        for (int j = 0; j < i; j++)
        {
            y[i] -= L[i][j] * y[j];
        }
        y[i] /= L[i][i];
    }
}

void backwardSubstitution(double U[MAX_SIZE][MAX_SIZE], double y[MAX_SIZE], double x[MAX_SIZE], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        x[i] = y[i];
        for (int j = i + 1; j < n; j++)
        {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
    }
}

int main()
{
    int n = 3; // Size of the system of equations

    double A[MAX_SIZE][MAX_SIZE]; // Coefficient matrix
    double b[MAX_SIZE];           // Right-hand side vector

    printf("Enter the coefficient matrix A (3x3):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("Enter the right-hand side vector b (3x1):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &b[i]);
    }

    double L[MAX_SIZE][MAX_SIZE] = {0}; // Initialize L matrix
    double U[MAX_SIZE][MAX_SIZE] = {0}; // Initialize U matrix
    double y[MAX_SIZE] = {0};           // Initialize y vector
    double x[MAX_SIZE] = {0};           // Initialize x vector

    if (luDecomposition(A, L, U, n))
    {
        forwardSubstitution(L, b, y, n);
        backwardSubstitution(U, y, x, n);

        printf("Solution (x) Vector:\n");
        printVector(x, n);
    }
    else
    {
        printf("LU decomposition failed. The system may not have a unique solution.\n");
    }

    return 0;
}
