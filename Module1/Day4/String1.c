#include<stdio.h>
#include<ctype.h>
#include<string.h>

void printToggleCase(char *str){
    while(*str != '\0'){
        if(isupper(*str)){
            *str = tolower(*str);
        }
        else if(islower(*str)){
            *str = toupper(*str);
        }
        str++;
    }
}


int main(){
    char str[100];
    printf("Enter the string:");
    fgets(str,sizeof(str),stdin);
    
    
    str[strcspn(str, "\n")] = '\0';                  //used to remove the newline and terminate the string at that position
    
    printToggleCase(str);
    printf("The Toggled string is: %s\n",str);
    
    return 0;
}