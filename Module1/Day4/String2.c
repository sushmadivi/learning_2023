#include<stdio.h>
#include<string.h>

int convertStringToInteger(char str[]){
    int result = 0;
    for(int i = 0; str[i] != '\0'; i++){
        result = result*10+(str[i] - '0');
    }
    
    return result;
}
 
int main(){
    
    char str[100];
    
    printf("Enter the string to get converted into an integer:");
    fgets(str,sizeof(str),stdin);
    
    str[strcspn(str, "\n")] = '\0';      
    
    int result = convertStringToInteger(str);
    
    printf("%d\n",result);
    
    return 0;
}