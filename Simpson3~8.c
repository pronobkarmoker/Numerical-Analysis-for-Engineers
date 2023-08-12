#include <stdio.h>
#include <math.h>

float func(float x)
{
    return x * x + 1;
}

int main()
{
    float a, b, h, n, sum = 0, x;

    printf("enter  the lower bound: ");
    scanf("%f", &a);
    printf("enter  the upper bound: ");
    scanf("%f", &b);
    printf("enter  the number of sub internval: ");
    scanf("%f", &n);

    h = (b - a) / n;

    for (int i = 1; i < n; i++)
    {
        x = a + i * h;
        if (i % 3 == 0)
        {
            sum = sum + 2 * func(x);
        }

        else
        {
            sum = sum + 3 * func(x);
        }
    }
    sum = ((3 * h / 8) * (func(a) + func(b) + sum));

    printf("Simpson 3/8 Rule - - - - - - - - - -\n");
    printf("Integral value = %.6lf\n", sum);
    printf("- - - - - - - - - - - - - - - - - - -\n");

    return 0;
}