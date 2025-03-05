#include<stdio.h>

void insertion_sort(int arr[],int max){
    int i, j, key;
    for (i=0;i<max;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

int main(){
    int i;
    int max;
    printf("Enter the size of array");
    scanf("%d",&max);
    int arr[max];
    printf("Enter the elements of the array\n");
    for (i=0;i<=max-1;i++){
        scanf("%d",&arr[i]);
    }
    insertion_sort(arr,max);
    for (i=0;i<=max-1;i++){
        printf("%d\t",arr[i]);
    }
}