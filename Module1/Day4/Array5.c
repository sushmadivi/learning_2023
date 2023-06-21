#include<stdio.h>



int diffOfEvenAndOddIndexedElements(int arr[],int n){
    int evenIndexSum=0,oddIndexSum=0;
    
    for(int i = 0; i < n; i+=2){
        evenIndexSum+=arr[i];
        if(i+1 < n){
            oddIndexSum+=arr[i+1];   
        }
    }
    return evenIndexSum - oddIndexSum;
}
int main(){
    int n;
    printf("Enter the length of the array:");
    scanf("%d",&n);
    
    int arr[n];
    
    for(int i = 0; i < n; i++){
        printf("Enter the array elements arr[%d]:",i+1);
        scanf("%d",&arr[i]);
    }
    
    int result = diffOfEvenAndOddIndexedElements(arr,n);
    
    printf("The difference between even and odd indexed elements is %d",result);
    
    return 0;
}