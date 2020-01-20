#include<stdio.h>
// S -> ABCD
// A -> aA|b
// B -> bB|c
// C -> cC|d
// D -> dD|a

int i=0;
char arr[1000];


int D()
{
    if(arr[i] == 'd')
    {
        i++;
        return D();
    }
    else if(arr[i] == 'e')
    {
        i++;
        return 1;
    }
    else
        return 0;
}

int C()
{
    if(arr[i] == 'c')
    {
        i++;
        return C();
    }
    else if(arr[i] == 'd')
    {
        return D();
    }
    else
        return 0;
}

int B()
{
    if(arr[i] == 'b')
    {
        i++;
        return B();
    }
    else if(arr[i] == 'c'|| arr[i] == 'd')
    {
        return C();
    }
    else
        return 0;
}





int A()
{
    if(arr[i] == 'a')
    {
        i++;
        return A();
    }
    else if(arr[i] == 'b' || arr[i] == 'c' || arr[i] == 'd')
    {
        return B();
    }
    else
        return 0;
}









int S()
{
    if(A() == 1 && arr[i] == '\0')
        return 1;
    else
        return 0;
}       


int main(){
    printf("enter a string :");
    scanf("%s",arr);
    if(S())
        printf("The String is valid\n");
    else
        printf("The String is invalid\n");
    return 0;
}