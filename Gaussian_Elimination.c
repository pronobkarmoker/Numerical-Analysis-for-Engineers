#include <stdio.h>
int main()
{
    float a[10][10], c, x[10], sum = 0;
    int n;
    printf("Enter the order of the matrix \n");
    scanf("%d", &n);
    printf("\nEnter the augmented matrix row wise : \n\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("A[%d][%d] : ", i + 1, j + 1);
            scanf("%f", &a[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j && a[j][j] != 0)
            {
                c = a[i][j] / a[j][j];

                for (int k = 0; k <= n; k++)
                {
                    a[i][k] = a[i][k] - c * a[j][k];
                }
            }

            printf("\n");
            printf("for i=%d and j=%d", i, j);
            printf("\n\n");

            for (int x = 0; x < n; x++)
            {
                for (int y = 0; y <= n; y++)
                {
                    printf("%f\t", a[x][y]);
                }

                printf("\n");
            }
        }
    }

    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        sum = 0;
        for (int j = i + 1; j < n; j++)
        {
            sum = sum + a[i][j] * x[j];
        }

        if (a[i][i] != 0)
        {
            x[i] = (a[i][n] - sum) / a[i][i];
        }
        else
        {
            printf("Division by zero encountered. Unable to solve.");
            return 1;
        }
    }
    
    printf("\nThe solution is : \n\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nx%d = %f\t", i + 1, x[i]);
    }

    return 0;
}
