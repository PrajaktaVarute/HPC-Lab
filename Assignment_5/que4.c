#include <stdio.h>
#include <omp.h>

int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n], prefix[n];

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Serial prefix sum (baseline for correctness)
    prefix[0] = arr[0];

// Parallel prefix sum
#pragma omp parallel for
    for (int i = 1; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j <= i; j++)
        {
            sum += arr[j];
        }
        prefix[i] = sum;
    }

    printf("Prefix Sum Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", prefix[i]);
    printf("\n");

    return 0;
}
