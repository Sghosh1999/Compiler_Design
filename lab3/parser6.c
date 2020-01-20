#include<stdio.h>
char arr[1000];
int i = 0;
int A();
int A_dash(){
    if(arr[i]== '\0')
        return 1;
    else if(arr[i] == 'b' || arr[i] == 'a')
    {
        i++;
        int output = 0;
        if(arr[i] == 'b')
             output = A();
        if(arr[i] != 'a')
            return 0;
        else
        {
            i++;
            return A_dash();
        }
    }
}

int A(){
    if(arr[i] == 'b')
    {
        i++;
        return A_dash();
    }
}


int main(){
    printf("enter a string :");
    scanf("%s",arr);
    if(A())
        printf("String is valid\n");
    else
        printf("String is invalid\n");
    return 0;
}