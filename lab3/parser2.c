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
    if(arr[i] == 'b')
    {
        i++;
        B();
    }
    else if(arr[i] == 'c')
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
        C();
    }
    else if(arr[i] == 'd')
    {
        i++;
        return 1;
    }
    else
        return 0;
}



int D()
{
    if(arr[i] == 'd')
    {
        i++;
        D();
    }
    else if(arr[i] == 'a')
    {
        i++;
        return 1;
    }
    else
        return 0;
}



int S()
{
    int output = 0;
    output = A();
    if(output)
    {
        output = B();
        if(output)
        {
            output = C();
            if(output)
            {
                output = D();
                if(output == 0)
                    return 0;
                if(arr[i] == '\0')
                    return 1;
                else
                    return 0;
            }
            return output;
        }
        return output;
    }
    return output;
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