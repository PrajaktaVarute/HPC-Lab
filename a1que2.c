#include <stdio.h>
#include <omp.h>

int main()
{
    int n;

    printf("Enter number of threads: ");
    scanf("%d", &n);

    printf("\nSequential:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Hello from thread %d (sequential)\n", i);
    }

    printf("\nParallel:\n");
    omp_set_num_threads(n);
#pragma omp parallel
    {
        printf("Hello from thread %d (parallel)\n", omp_get_thread_num());
    }

    return 0;
}
