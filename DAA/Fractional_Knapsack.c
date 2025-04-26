#include <stdio.h>

void swap(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

void swapInt(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

double fractionalKnapsack(int W, int value[], int weight[], int n)
{
    double ratio[n];

    // Calculate value/weight ratio
    for (int i = 0; i < n; i++)
    {
        ratio[i] = (double)value[i] / weight[i];
    }

    // Sort items by ratio in descending order (Simple bubble sort)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                swap(&ratio[j], &ratio[j + 1]);
                swapInt(&value[j], &value[j + 1]);
                swapInt(&weight[j], &weight[j + 1]);
            }
        }
    }

    double totalValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (W >= weight[i])
        {
            // Take full item
            W -= weight[i];
            totalValue += value[i];
        }
        else
        {
            // Take fractional part
            totalValue += (double)value[i] * ((double)W / weight[i]);
            break;
        }
    }

    return totalValue;
}

int main()
{
    printf("Enter the number of items: ");
    int n, W;
    scanf("%d", &n);
    int value[n], weight[n];
    printf("Enter the maximum weight capacity: ");
    scanf("%d", &W);
    printf("Now enter the available weights and their values\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the weight and respective value of item %d:", i + 1);
        scanf("%d %d", &weight[i], &value[i]);
    }
    printf("Maximum value we can obtain = %.2f\n", fractionalKnapsack(W, value, weight, n));
    return 0;
}
