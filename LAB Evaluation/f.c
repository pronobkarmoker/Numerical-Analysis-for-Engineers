#include <stdio.h>

void displayMatrix(double matrix[3][6]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void inverseMatrix(double matrix[3][6]) {
    // Perform Gauss-Jordan elimination
    for (int i = 0; i < 3; i++) {
        double pivot = matrix[i][i];

        // Scale the current row to make the diagonal element 1
        for (int j = 0; j < 6; j++) {
            matrix[i][j] /= pivot;
        }

        // Make the other rows zero in the current column
        for (int k = 0; k < 3; k++) {
            if (k != i) {
                double factor = matrix[k][i];
                for (int j = 0; j < 6; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
    }

    // Display the inverse matrix
    printf("Inverse Matrix:\n");
    displayMatrix(matrix);
}

int main() {
    double matrix[3][6];

    // Input the matrix elements
    printf("Enter the elements of the 3x3 matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &matrix[i][j]);
            // Initialize the augmented matrix with the identity matrix
            matrix[i][j + 3] = (i == j) ? 1.0 : 0.0;
        }
    }

    // Find the inverse of the matrix
    inverseMatrix(matrix);

    return 0;
}
