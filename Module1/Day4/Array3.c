#include<stdio.h>


void reverseArray(int arr[],int n){
    printf("Reversed array \n");
    for(int i = n-1; i >=0; i--){
        printf("%d ",arr[i]);
    }
}
int main(){
    int n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i < n ; i++){
        printf("Enter the elements of array arr[%d]:",i+1);
        scanf("%d",&arr[i]);
    }
    
    printf("Original Array\n");
    
    for(int i = 0; i < n ; i++){
        printf("%d ",arr[i]);
    }
    
    printf("\n");
    reverseArray(arr,n);
    
    
    return 0;
}