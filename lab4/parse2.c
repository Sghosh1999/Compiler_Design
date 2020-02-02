#include <stdio.h>
int S();
int A();
int A_();
int B();
int B_();
int C();
int C_();
int D();
int D_();
char arr[1000];
int i = 0;

//S

int S()
{
    if (arr[i] == 'b')
        return A() * B();
    else if (arr[i] == 'e')
        return C() * D();
    else
        return 0;
}

//A

int A()
{
    if (arr[i] == 'b')
    {
        i++;
        return A_();
    }
    else
        return 0;
}

int A_()
{
    if (arr[i] == 'a')
    {
        i++;
        return A_();
    }
    if (arr[i] == 'c')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//B

int B()
{
    if (arr[i] == 'c')
    {
        i++;
        return B_();
    }
    else
        return 0;
}

int B_()
{
    if (arr[i] == 'b')
    {
        i++;
        return B_();
    }
    if (arr[i] == '\0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//C

int C()
{
    if (arr[i] == 'e')
    {
        i++;
        return C_();
    }
    else
        return 0;
}

int C_()
{
    if (arr[i] == 'g')
        return 1;
    else if (arr[i] == 'e')
    {
        int p = C();
        if (arr[i] == 'd')
        {
            i++;
            return p * C_();
        }
    }
    else if (arr[i] == 'd')
    {
        return 1;
    }
}

//D

int D()
{
    if (arr[i] == 'g')
    {
        i++;
        return D_();
    }
    else
        return 0;
}

int D_()
{
    if (arr[i] == 'f')
    {
        i++;
        return D_();
    }
    if (arr[i] == '\0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    printf("enter a string::");
    scanf("%s", arr);
    if (S())
        printf("The string is valid");
    else
        printf("The string is invalid");
    return 0;
}