#include <stdio.h>
#include <omp.h>

int main()
{
    long total = 100000000;
    double step = 1.0 / (double)total;
    double sum = 0.0, pi = 0.0;
    double start = omp_get_wtime();
#pragma omp parallel
    {
        double x;
        double local_sum = 0.0;
#pragma omp for
        for (long i = 0; i < total; i++)
        {
            x = (i + 0.5) * step;
            local_sum += 4.0 / (1.0 + x * x);
        }
#pragma omp atomic
        sum += local_sum;
    }
    pi = step * sum;
    double end = omp_get_wtime();
    printf("Calculated value of Pi: %.15f\n", pi);
    printf("Time taken: %f seconds\n", end - start);
    return 0;
}
