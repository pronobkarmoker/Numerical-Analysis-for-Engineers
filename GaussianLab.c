#include <stdio.h>

int main()
{
    float mat[4][5] = {
        {1, -1, 2, -1, -8},
        {2, -2, 3, -3, -20},
        {1, 1, 1, 0, -2},
        {1, -1, 4, 3, 4}};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%.2f\t", mat[i][j]);
        }
        printf("\n");
    }

    float arr[4];

    for (int i = 1; i < 4; i++)
    {
        arr[i] = mat[i][0];
        printf("%.2f ", mat[i][0]);
    }

    printf("\n\n");

    for (int i = 1; i < 4; i++)
    {
        for (int j = i; j < 4; j++)
        {
            if (i == j && mat[i][j] == 0)
            {
                for (int k = 0; k < 5; k++)
                {
                    float temp = mat[i + 1][k];
                    mat[i + 1][k] = mat[i][k];
                    mat[i][k] = temp;
                }
            }

            for (int k = i - 1; k < 5; k++)
            {
                mat[j][k] = (mat[i - 1][i - 1] / mat[j][i - 1]) - mat[j][k];
            }
        }

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                printf("%.2f\t", mat[i][j]);
            }
            printf("\n");
        }

        printf("\n\n");
    }

    return 0;
}
