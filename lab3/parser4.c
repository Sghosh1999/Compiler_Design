#include<stdio.h>
// S -> ABCD
// A -> aA|b
// B -> bB|c
// C -> cC|d
// D -> dD|a



int i=0;
char arr[1000];

int A()
{
    if(arr[i] == 'a')
    {
        i++;
        A();
    }
    else if(arr[i] == 'b')
    {
        i++;
        return 1;
    }
    else
        return 0;
}

int B()
{
    if(arr[i] == 'c')
    {
        i++;
        B();
    }
    else if(arr[i] == 'd')
    {
        i++;
        return 1;
    }
    else
        return 0;
}


int C()
{
    if(arr[i] == 'e')
    {
        i++;
        C();
    }
    else if(arr[i] == 'f')
    {
        i++;
        return 1;
    }
    else
        return 0;
}



int D()
{
    if(arr[i] == 'g')
    {
        i++;
        D();
    }
    else if(arr[i] == 'h')
    {
        i++;
        return 1;
    }
    else
        return 0;
}



int S()
{
    if(arr[i] == 'a'||arr[i] == 'b')
    {
        int output =  A() * B();
        if(arr[i] != '\0')
            return 0;
        else
            return output;
    }
    else if(arr[i] == 'e'||arr[i] == 'f')
    {
        int output =  C() * D();
        if(arr[i] != '\0')
            return 0;
        else
            return output;
    }
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