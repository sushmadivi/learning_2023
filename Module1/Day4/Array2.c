#include<stdio.h>

void minAndMaxOfTheArray(int arr[],int length,int *min,int *max){
    *min = *max = arr[0];
    for(int i = 0; i < length ; i++){
        if(arr[i] < *min){
            *min = arr[i];
        }
        if(arr[i] > *max){
            *max = arr[i];
        }
    }
    printf("The minimum element in the array is %d, and the maximum element in the array is %d",*min,*max);
}



int main(){
    int n,max,min;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int arr[n];
    for(int i = 0 ; i < n; i++){
        printf("Enter the elements of the array arr[%d]:",i+1);
        scanf("%d",&arr[i]);
    }
    minAndMaxOfTheArray(arr,n,&min,&max);
    
    return 0;
}