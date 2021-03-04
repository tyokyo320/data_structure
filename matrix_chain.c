#include <stdio.h>
#include <limits.h>

int recursiveMatrixChain(int p[], int i, int j);

int main(int argc, char const *argv[])
{
    int arr[] = {12, 10, 6, 2, 4, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Minimum number of multiplications is %d \n",
           recursiveMatrixChain(arr, 1, n - 1));

    return 0;
}

int recursiveMatrixChain(int p[], int i, int j)
{
    int min = INT_MAX;
    int count;

    if (i == j)
        return 0;

    for (int k = i; k < j; k++)
    {
        count = recursiveMatrixChain(p, i, k) + recursiveMatrixChain(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        if (count < min)
            min = count;
    }

    return min;
}
