#include <stdio.h>
#include <math.h>

float func(float x)
{
    return x * x + 1;
}

int main()
{
    float a, b, h, n, sum = 0, x ,  s =0;

    a = 0 ;
    b = 2;
    n = 10 ;

    h = (b - a) / n;
    
    for (int i = 1; i < n; i++)
    {
        x = a + i * h;
        sum = sum + func(x);
    }
    
    sum = h / 2 * (func(a) + func(b) + 2 * sum);
    
    printf("Trapezoidal Rule - - - - - - - - - -\n");
    printf("Integral value = %.6lf\n", sum);
    printf("- - - - - - - - - - - - - - - - - - -\n");
    
    
    for (int j = 1; j < n; j++)
    {
        x = a + j * h;
        if (j%2 == 0)
        {
            s = s+2*func(x);
        }

        else
        {
            s = s + 4*func(x);
        }
        
    }
    s = h / 3 * (func(a) + func(b) +  s);

    printf("Simpson 1/3 Rule - - - - - - - - - -\n");
    printf("Integral value = %.6lf\n", s);
    printf("- - - - - - - - - - - - - - - - - - -\n");


    return 0;
}

