#include<stdio.h>
//to parse S -> aS | b

int S(char *arr,int i){
    if(arr[i] == 'a')
    {
        S(arr,i+1);
    }
    else if(arr[i] == 'b')
    {
        if(arr[i+1] == '\0')
            return 1;
        else
            return 0;
    }
    else
        return 0;
}



int main(){
    char arr[100];
    printf("Enter a string :");
    scanf("%s",arr);
    int result = S(arr,0);
    if(result == 1)
        printf("String is correct\n");
    else
        printf("String is not correct\n");
    return 0;
}