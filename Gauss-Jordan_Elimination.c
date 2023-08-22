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
        if (a[i][i] == 0)
        {
            printf("Pivot element is zero. Cannot proceed with Gauss-Jordan elimination.");
            return 1; 
        }

        printf("\n--- Step %d ---\n\n", i + 1);

        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                c = a[j][i] / a[i][i];

                printf("For i=%d and j=%d:\n", i + 1, j + 1);
                printf("c = %.2f\n", c);

                for (int k = 0; k <= n; k++) 
                {
                    a[j][k] = a[j][k] - c * a[i][k];
                }

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
    }

    for (int i = 0; i < n; i++)
    {
        x[i] = a[i][n] / a[i][i]; 
    }

    printf("\nThe solution is : \n\n");
    for (int i = 0; i < n; i++) 
    {
        printf("\nx%d = %f\t", i + 1, x[i]);
    }

    return 0;
}
