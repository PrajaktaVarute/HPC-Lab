#include <stdio.h>
#include <omp.h>

#define N 10
int fib[N];

int main()
{
    fib[0] = 0;
    fib[1] = 1;
#pragma omp parallel for ordered
    for (int i = 2; i < N; i++)
    {
#pragma omp ordered
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    printf("Fibonacci Series:\n");
    for (int i = 0; i < N; i++)
        printf("%d ", fib[i]);
    return 0;
}
