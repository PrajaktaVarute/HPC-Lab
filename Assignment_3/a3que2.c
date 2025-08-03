#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void add_matrices(int size, int threads)
{
    int i, j;
    double start, end;
    float **A = malloc(size * sizeof(float *));
    float **B = malloc(size * sizeof(float *));
    float **C = malloc(size * sizeof(float *));
    for (i = 0; i < size; i++)
    {
        A[i] = malloc(size * sizeof(float));
        B[i] = malloc(size * sizeof(float));
        C[i] = malloc(size * sizeof(float));
        for (j = 0; j < size; j++)
        {
            A[i][j] = i + j;
            B[i][j] = i - j;
        }
    }

    omp_set_num_threads(threads);
    start = omp_get_wtime();

#pragma omp parallel for collapse(2)
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    end = omp_get_wtime();
    printf("Size: %d, Threads: %d, Time: %f sec\n", size, threads, end - start);

    for (i = 0; i < size; i++)
    {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);
}

int main()
{
    int sizes[] = {250, 500, 750, 1000, 2000};
    int threads[] = {2, 4, 8};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            add_matrices(sizes[i], threads[j]);
        }
    }
    return 0;
}
