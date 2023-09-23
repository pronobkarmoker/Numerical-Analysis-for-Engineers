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

void identityMatrix(double I[MAX_SIZE][MAX_SIZE], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                I[i][j] = 1.0;
            }
            else
            {
                I[i][j] = 0.0;
            }
        }
    }
}

void matrixMultiplication(double A[MAX_SIZE][MAX_SIZE], double B[MAX_SIZE][MAX_SIZE], double C[MAX_SIZE][MAX_SIZE], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0.0;
            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int inverseMatrix(double A[MAX_SIZE][MAX_SIZE], double inverse[MAX_SIZE][MAX_SIZE], int n)
{
    double L[MAX_SIZE][MAX_SIZE] = {0};
    double U[MAX_SIZE][MAX_SIZE] = {0};
    double I[MAX_SIZE][MAX_SIZE] = {0}; // Identity matrix

    if (!luDecomposition(A, L, U, n))
    {
        printf("LU decomposition failed. The matrix may be singular.\n");
        return 0; // Failure
    }

    identityMatrix(I, n); // Create an identity matrix

    double Y[MAX_SIZE][MAX_SIZE] = {0}; // Initialize Y matrix
    double X[MAX_SIZE][MAX_SIZE] = {0}; // Initialize X matrix

    // Solve for the inverse
    for (int i = 0; i < n; i++)
    {
        double B[MAX_SIZE][MAX_SIZE] = {0};
        for (int j = 0; j < n; j++)
        {
            B[j][0] = I[j][i];
        }

        double Y[MAX_SIZE][MAX_SIZE] = {0}; // Initialize Y matrix

        // Forward substitution for Ly = b
        for (int j = 0; j < n; j++)
        {
            Y[j][0] = B[j][0];
            for (int k = 0; k < j; k++)
            {
                Y[j][0] -= L[j][k] * Y[k][0];
            }
            Y[j][0] /= L[j][j];
        }

        // Backward substitution for Ux = y
        for (int j = n - 1; j >= 0; j--)
        {
            X[j][i] = Y[j][0];
            for (int k = j + 1; k < n; k++)
            {
                X[j][i] -= U[j][k] * X[k][i];
            }
            X[j][i] /= U[j][j];
        }
    }

    // The inverse matrix is stored in X
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            inverse[i][j] = X[i][j];
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
    double inverse[MAX_SIZE][MAX_SIZE];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &matrix[i][j]);
        }
    }

    if (inverseMatrix(matrix, inverse, n))
    {
        printf("Inverse Matrix:\n");
        printMatrix(inverse, n);
    }

    return 0;
}
