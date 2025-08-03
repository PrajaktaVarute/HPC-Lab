#include <stdio.h>
#include <omp.h>

#define SIZE 200
float a[SIZE], b[SIZE];

void vector_add_static(int chunk)
{
#pragma omp parallel for schedule(static, chunk)
    for (int i = 0; i < SIZE; i++)
    {
        b[i] = a[i] + 10;
    }
}

void vector_add_dynamic(int chunk)
{
#pragma omp parallel for schedule(dynamic, chunk)
    for (int i = 0; i < SIZE; i++)
    {
        b[i] = a[i] + 10;
    }
}

void vector_add_nowait()
{
#pragma omp parallel
    {
#pragma omp for nowait
        for (int i = 0; i < SIZE / 2; i++)
        {
            b[i] = a[i] + 5;
        }

#pragma omp for
        for (int i = SIZE / 2; i < SIZE; i++)
        {
            b[i] = a[i] + 5;
        }
    }
}

int main()
{
    for (int i = 0; i < SIZE; i++)
        a[i] = i;

    printf("Static schedule (chunk=10):\n");
    vector_add_static(10);

    printf("Dynamic schedule (chunk=10):\n");
    vector_add_dynamic(10);

    printf("Nowait example:\n");
    vector_add_nowait();

    return 0;
}
