#include<stdio.h>



int diffOfEvenAndOddElements(int arr[],int n){
    int evenSum=0,oddSum=0;
    
    for(int i = 0; i < n; i++){
        if(arr[i]%2==0){
            evenSum+=arr[i];
        }
        else{
            oddSum+=arr[i];   
        }
    }
  
    return evenSum - oddSum;
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
    
    int result = diffOfEvenAndOddElements(arr,n);
    
    printf("The difference between even and odd elements is %d",result);
    
    return 0;
}