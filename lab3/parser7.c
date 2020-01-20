#include<stdio.h>
char arr[1000];
int i = 0;

int A()
{
    if(arr[i] == 'a')
    {
        i++;
        return A();
    }
    else if(arr[i] == '\0')
        return 1;
    else
        return 0;
}

int main(){
    printf("Enter a string: ");
    scanf("%s",arr);
    if(A())
        printf("String is valid\n");
    else
        printf("String is invalid\n");        
    return 0;
}