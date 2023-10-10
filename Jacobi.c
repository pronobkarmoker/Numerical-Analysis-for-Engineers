#include <stdio.h>
#include <math.h>

#define N 3 // Number of equations

int main()
{
    // Define the coefficient matrix A and the right-hand side vector b
    double A[N][N] = {
        {27, 6, -1},
        {6, 15, 2},
        {1, 1, 54}};
    double b[N] = {85, 72, 110};

    // Initialize the solution vector x with zeros
    double x[N] = {0};

    // Define the maximum number of iterations and the tolerance
    int max_iterations = 100;
    double tolerance = 1e-6;

    printf("Iteration\t");
    for (int i = 0; i < N; i++)
    {
        printf("x%d\t\t", i + 1);
    }
    printf("\n");

    // Jacobi iterative method
    for (int iteration = 1; iteration <= max_iterations; iteration++)
    {
        printf("%d\t\t", iteration);

        double x_new[N] = {0};

        // Calculate the new values of x
        for (int i = 0; i < N; i++)
        {
            x_new[i] = b[i];
            for (int j = 0; j < N; j++)
            {
                if (j != i)
                {
                    x_new[i] -= A[i][j] * x[j];
                }
            }
            x_new[i] /= A[i][i];
        }

        // Print the values of x for this iteration
        for (int i = 0; i < N; i++)
        {
            printf("%0.6lf\t", x_new[i]);
        }
        printf("\n");

        // Check for convergence
        int converged = 1;
        for (int i = 0; i < N; i++)
        {
            if (fabs(x_new[i] - x[i]) > tolerance)
            {
                converged = 0;
                break;
            }
        }

        // Update x with the new values
        for (int i = 0; i < N; i++)
        {
            x[i] = x_new[i];
        }

        // If converged, exit the loop
        if (converged)
        {
            printf("Converged\n");
            break;
        }
    }

    return 0;
}
