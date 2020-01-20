#include<stdio.h>
// E -> TE`
// E` -> +TE` | epsilon
// T -> FT`
// T` -> *FT` | epsilon
// F -> (E) | a

char arr[1000];
int i = 0;
int E();
int F(){
    if(arr[i] == '(')
    {
        i++;
        int output = E();
        if(arr[i] == ')')
            return output * 1;
        else
            return 0;
    }
    else if(arr[i] == 'a')
    {
        i++;
        return 1;
    }
    else
        return 0;
}   




int T_dash(){
    if(arr[i] == '*')
    {
        i++;
        return F()*T_dash();
    }
    else if( arr[i] == 'a'|| arr[i] == '('|| arr[i] == ')' || arr[i] == '+' || arr[i] == '\0')
        return 1;
    else
        return 0;
}

int T(){
    
    return F()*T_dash();
}


int E_dash()
{
    
    if(arr[i] == '+')
    {
        i++;
        return T()*E_dash();
    }
    else if(arr[i] == 'a'|| arr[i] == '(' || arr[i] == ')' || arr[i] == '\0')
        return 1;
    else
        return 0;
}

int E(){
   
    int output =  T()*E_dash();
    if((output == 1 && arr[i] == ')')||(output == 1 && arr[i] == '\0'))
        return 1;
    else
        return 0;
}

int main(){
    printf("Enter a string :");
    scanf("%s",arr);
    if(E())
        printf("The string is valid\n");
    else
        printf("The String is invalid\n");
}