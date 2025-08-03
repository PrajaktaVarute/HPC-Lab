#include <stdio.h>
#include <omp.h>

int main()
{
    int n = 1000;
    float scalar = 2.5;
    float a[n], result[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = i * 1.0;
    }
    double start = omp_get_wtime();
#pragma omp parallel for
    for (int i = 0; i < n; i++)
    {
        result[i] = scalar * a[i];
    }
    double end = omp_get_wtime();

    printf("Vector Scalar Multiplication done. Time taken: %f seconds\n", end - start);
    for(int i=0;i<n;i++) {
        printf("Result[%d] is %f \n",i,result[i]);
    }

    return 0;
}
