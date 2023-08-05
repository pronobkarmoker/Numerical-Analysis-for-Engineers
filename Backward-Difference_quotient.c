#include <stdio.h>
#include <math.h>
#define F(x) ((x * x) + 1)
#define EPS 10.0e-6

int main()
{
    double a = 0.0;
    double b = 2.0;
    double n = 10;

    double h = (b - a) / n;

    double x = a;

    printf("--------------------------------------------------------------------------\n");
    printf("iter  	 x           F(x)          F(x+h)        derivative\n");
    printf("--------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        double fx = F(x);
        double fx2 = F(x - h);
        double derivative = (F(x) - F(x + h)) / h;

        printf("%3d %10.6lf %10.6lf %10.6lf %10.6lf\n", i, x, fx, fx2, derivative);

        x += h;
    }
}