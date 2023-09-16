#include <stdio.h>

#define MAX_SIZE 100

void convertToUpperTriangular(double matrix[MAX_SIZE][MAX_SIZE], int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = k + 1; i < n; i++)
        {
            double factor = matrix[i][k] / matrix[k][k];
            for (int j = k; j < n; j++)
            {
                matrix[i][j] -= factor * matrix[k][j];
            }
        }
    }
}

void convertToLowerTriangular(double matrix[MAX_SIZE][MAX_SIZE], int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = k + 1; i < n; i++)
        {
            double factor = matrix[i][k] / matrix[k][k];
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] -= factor * matrix[k][j];
            }
        }
    }
}

void printMatrix(double matrix[MAX_SIZE][MAX_SIZE], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
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

    printf("Original Matrix:\n");
    printMatrix(matrix, n);

    convertToUpperTriangular(matrix, n);
    printf("\nUpper Triangular Matrix:\n");
    printMatrix(matrix, n);

    convertToLowerTriangular(matrix, n);
    printf("\nLower Triangular Matrix:\n");
    printMatrix(matrix, n);

    return 0;
}
