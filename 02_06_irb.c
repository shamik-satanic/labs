#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int calculator(double *result, double x, int n, ...)
{
    if (result == NULL)
    {
        return 1;
    }

    va_list args;
    va_start(args, n);
    double res = 0.0, coef;
    int i;

    for (i = 0; i <= n; ++i)
    {
        coef = va_arg(args, double);
        res = res * x + coef;
    }

    va_end(args);
    *result = res;
    return 0;
}

int main()
{
    double result;
    switch (calculator(&result, 3.0, 3, 2.0, 4.5, -1.0, -1.5))
    {
        case 0:
            printf("%.2f\n", result);

            break;

        case 1:
            printf("Invalid result placement!\n");

            break;

        default:
            printf("Undefined behavior! 000___ooo\n");

            break;
    }
    return EXIT_SUCCESS;
}