#include <stdio.h>
#include <limits.h>

int matrixChainRec(int arr[], int i, int j) {
    if (i == j)
        return 0; // Only one matrix, no multiplication needed.

    int min = INT_MAX;

    // Place parenthesis at different positions between i and j
    for (int k = i; k < j; k++) {
        int cost = matrixChainRec(arr, i, k)
                 + matrixChainRec(arr, k+1, j)
                 + arr[i-1] * arr[k] * arr[j];

        if (cost < min)
            min = cost;
    }

    return min;
}

int main() {
    int arr[] = {10, 30, 5, 60};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Minimum number of multiplications is %d\n", matrixChainRec(arr, 1, n-1));
    return 0;
}
