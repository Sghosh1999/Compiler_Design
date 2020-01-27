#include<stdio.h>
#include<string.h>
char a[1000];
int i = 0;
int _B(){
    printf("char at _B:%c\n",a[i]);
    if(a[i] == 'x' && a[i+1] == 'x')
    {
        i+=2;
        return _B();
    }
    else if(a[i] == '\0')
    {
        i++;
        return 1;
    }
    else
    {
        return 1;
    }
}

int B(){
    printf("char at B:%c\n",a[i]);
    if(a[i] == '\0')
    {
        i++;
        return 1;
    }
    else if(a[i] == 'y'||(a[i] == 'x' && a[i] =='x'))
    {   
        if(a[i] == 'y')
            i++;
        else
            i+=2;
        return B() * _B();
    }
    else{
        i++;
        return 0;
    }    
}

int _A()
{
    printf("char at _A:%c\n",a[i]);
    if(a[i] == 'x')
    {
        i++;
        return _B();   
    }
    else if(a[i] == '\0')
    {
        i++;
        return 1;
    }
    else if(a[i] == 'z' && a[i+1] =='z')
    {
        i+=2;
        return _A();
    }
    else
    {
        i++;
        return 0;
    }
}

int A(){
    printf("char at A:%c\n",a[i]);
    if(a[i]=='x')
    {
        i++;
        return _A()*A();
    }
    else if(a[i] == 'y')
    {
        i++;
        return _B();
    }
    else if(a[i] == 'z' && a[i+1] == 'z')
    {
        i+=2;
        return A();
    }
    else if(a[i] == '\0')
    {
        i++;
        return 1;
    }
    else{
        i++;
        return 0;
    }
}

int __S(){
    printf("char at __S:%c\n",a[i]);
    if(a[i] == 'y' && a[i+1] == 'y')
    {
        i+=2;
        return 1;
    }
    if(a[i] == '\0')
    {
        i++;
        return 1;
    }
    else{
        return 1;
    }
}

int _S()
{
    printf("char at _S:%c\n",a[i]);
    
    if(a[i] == 'x')
    {
        return _B();
    }
    else if(a[i] == '\0')
    {
        i+=1;
        return __S();
    }
    else{
        return 1;
    }
}

int S(){
    printf("char at S:%c\n",a[i]);
    if(a[i] =='y')
    {
        i+=1;
        return _S()*S();
    }
    if(a[i] == 'z' && a[i+1] =='z')
    {
        i+=2;
        return __S()*S();
    }
    if(a[i] == 'x')
    {
        i+=1;
        return _A()*S();
    }
    if(a[i] == '\0')
    {
        i++;
        return 1;
    }
    else{
        i+=1;
        return 1; 
    }
}



int main(){
    printf("Enter a string::");
    scanf("%s",a);
    if(S() == 1)
    {
        printf("The String is valid\n");
    }
    else{
        printf("The String is invalid\n");
    }
    return 0;
}

