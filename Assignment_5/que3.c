#include <stdio.h>
#include <omp.h>

int main()
{
    int m, n;
    printf("Enter rows and columns of matrix: ");
    scanf("%d %d", &m, &n);

    int A[m][n], x[n], result[m];

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of the vector (size %d):\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &x[i]);

    // Initialize result vector
    for (int i = 0; i < m; i++)
        result[i] = 0;

// Parallel matrix-vector multiplication
#pragma omp parallel for
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i] += A[i][j] * x[j];
        }
    }

    printf("Resultant Vector:\n");
    for (int i = 0; i < m; i++)
        printf("%d\n", result[i]);

    return 0;
}
