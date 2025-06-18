#include <stdio.h>

int main(){
    int arr1[]={3,5,1,6,2,7};
    int i;
    int j;

    for (int i=0;i<6;i++){
        for (int j=i;j<6;j++){
            if (arr1[i]>arr1[j]){
                int temp=arr1[i];
                arr1[i]=arr1[j];
                arr1[j]=temp;

            }
        }
    }
    for (int i=0;i<6;i++){
        printf("%d\t",arr1[i]);
    }

}