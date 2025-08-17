    #include <stdio.h>
    #include <omp.h>

    int main()
    {
        int m, n, scalar;
        printf("Enter rows and columns of matrix: ");
        scanf("%d %d", &m, &n);

        int A[m][n], B[m][n];

        printf("Enter elements of the matrix:\n");
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &A[i][j]);

        printf("Enter the scalar value: ");
        scanf("%d", &scalar);

    // Parallel scalar multiplication
    #pragma omp parallel for collapse(2)
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                B[i][j] = A[i][j] * scalar;
            }
        }

        printf("Resultant Matrix:\n");
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                printf("%d ", B[i][j]);
            printf("\n");
        }

        return 0;
    }
