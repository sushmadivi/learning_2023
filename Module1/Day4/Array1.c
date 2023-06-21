#include<stdio.h>

void sumAndAverageOfArray(int arr[],int length,int *sum,int *average){
    for(int i = 0; i < length; i++){
        *sum+=arr[i]; 
    }
    *average = *sum / length;
    printf("The sum of the array is %d and the average of the array is %d",*sum,*average);
}

int main(){
    int n,sum=0,average=0;
    
    printf("Enter the length of the array:");
    scanf("%d",&n);
    
    int arr[n];
    
    for(int i = 0; i < n; i++){
        printf("Enter the elements of array arr[%d]:",i+1);
        scanf("%d",&arr[i]);
    }
    
    
    sumAndAverageOfArray(arr,n,&sum,&average);
    
       
    return 0;
    
}