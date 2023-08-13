#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPS 10.0e-6

double f(double x) {
    return sqrt(x);
}

double g(double x) {
    return x * x;
}

double find_intersection() {
    double a = 0.5, b = 1.25;
    double c;

    while (fabs(b - a) > EPS) {
        c = (a + b) / 2.0;
        double fc = f(c) - g(c);

        if (fc == 0 || fabs(b - a) / 2.0 < EPS)
            return c;

        if (fc * (f(a) - g(a)) < 0)
            b = c;
        else
            a = c;
    }

    return c;
}

double simpsons(double (*func)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = func(a) + func(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0)
            sum += 2 * func(x);
        else
            sum += 4 * func(x);
    }

    return h / 3.0 * sum;
}

int main(void) {
    double intersection = find_intersection();
    double area = simpsons(f, 0.0, intersection, 10000) - simpsons(g, 0.0, intersection, 10000);

    printf("Intersection point: %lf\n", intersection);
    printf("Area  : %lf\n", area);

    return 0;
}
