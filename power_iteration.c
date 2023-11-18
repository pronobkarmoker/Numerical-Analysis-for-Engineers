#include <stdio.h>
#include <math.h>

#define EPS 1.0e-4

double eVector[3][1];

void matrix_multiplication(double A[][3], double x[][1])
{

    for (int i = 0; i < 3; i++)
    {
        eVector[i][0] = 0.0;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                eVector[i][j] += A[i][k] * x[k][j];
            }
        }
    }
}

double findMax()
{
    double mx = eVector[0][0];
    for (int i = 1; i < 3; i++)
    {
        if (eVector[i][0] > mx)
        {
            mx = eVector[i][0];
        }
    }
    return mx;
}

int main()
{

    double A[3][3] = {{2, -1, 0}, {-1, 2, -1}, {0, -1, 2}};
    double x[3][1] = {{1}, {0}, {0}};

    int i = 0;

    double eValue, preEvalue = 0.0;

    printf("--------------------------------------------------------------------\n");
    printf(" Iter  |       x1               x2          x3            |   Lambda\n");
    printf("--------------------------------------------------------------------\n");
    printf("  %d    |     %lf      %lf     %lf          |            \n", i, x[0][0], x[1][0], x[2][0]);

    i++;
    do
    {

        matrix_multiplication(A, x);

        eValue = findMax();

        for (int j = 0; j < 3; j++)
        {
            eVector[j][0] = eVector[j][0] / eValue;
            x[j][0] = eVector[j][0];
        }

        printf("  %d    |     %lf      %lf     %lf        | %lf\n", i, eVector[0][0], eVector[1][0], eVector[2][0], eValue);

        i++;

        if (fabs(eValue - preEvalue) < EPS || i >= 50)
        {
            break;
        }

        preEvalue = eValue;

    } while (1);

    printf("--------------------------------------------------------------------\n");
    printf("Approx EigenValue: %lf\n", eValue);
    printf("Corresponding EigenVector: %lf\t%lf\t%lf", eVector[0][0], eVector[1][0], eVector[2][0]);

    printf("\n\n");

    return 0;
}