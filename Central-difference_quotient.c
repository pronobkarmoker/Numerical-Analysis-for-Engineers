#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * x + 1;
}

double central_difference_quotient(double (*func)(double), double x, double h) {
    return (func(x + h) - func(x - h)) / (2 * h);
}

int main() {
    double a, b;
    int n;
    
    printf("Enter the interval [a, b]: ");
    scanf("%lf %lf", &a, &b);
    
    printf("Enter the number of intervals (n): ");
    scanf("%d", &n);

    double h = (b - a) / n;
    double xi = a;
    
    printf("--------------------------------------------------------------\n");
    printf("  i\t x\t\t f(x)\t\t f(x+h)\t         derivative\n");
    printf("---------------------------------------------------------------\n");
    
    for (int i = 0; i <= n; i++) {
        double fx = f(xi);
        double fx_plus_h = f(xi + h);
        double derivative = central_difference_quotient(f, xi, h);
        
        printf("%3d\t %.6lf\t %.6lf\t %.6lf\t %.6lf\n", i, xi, fx, fx_plus_h, derivative);
        
        xi += h;
    }
    
    printf("-------------------------------------------------------\n");
    
    return 0;
}

