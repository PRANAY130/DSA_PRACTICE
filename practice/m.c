#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int low, int mid, int high)
{
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int l[n1], r[n2];

    for (i = 0; i < n1; i++)
    {
        l[i] = arr[low + i];
    }
    for (j = 0; j < n2; j++)
    {
        r[j] = arr[mid + j + 1];
    }

    i = 0;
    j = 0;
    k = low;

    while (i < n1 && j < n2)
    {
        if (l[i] <= r[j])
        {
            arr[k] = l[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = r[j];
            j++;
            k++;
        }
    }

    while (i < n1)
    {
        arr[k] = l[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        arr[k] = r[j];
        k++;
        j++;
    }
}


int mergeSort(int arr[],int low,int high){
    if (low<high){
        int mid=(low+high)/2;

        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);

        merge(arr,low,mid,high);
    }
}


void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// Driver code
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
