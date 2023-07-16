#include <stdio.h>
#include <math.h>

int main() {
    double a = 0;
    double b = 2 * 3.1416;
    double m = 100;
    double h = (b - a) / m;

    FILE* fp = fopen("sin_curve_data.csv", "w"); // Open the file in write mode

    if (fp == NULL) {
        printf("Error opening the file.");
        return 1;
    }

    fprintf(fp, "\"x\", \"sin(x)\"\n"); // Print the header to the file

    double x = a;
    for (int i = 0; i <= m; i++) {
        x += h;
        fprintf(fp, "%lf, %lf\n", x, sin(x)); // Print data to the file
    }

    fclose(fp); // Close the file
    return 0;
}
