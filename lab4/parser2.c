#include<stdio.h>
#include<string.h>
char s[1000];
int i=0;
int D_t()
{
    if(s[i] == 'f')
    {
        i++;
        return D_t();
    }
    else{
        return 1;
    }
}

int D(){
    if(s[i] == 'g')
    {
        i++;
        return D_t();
    }
    else{
        i++;
        return 0;
    }
}


int C_t();

int main(){
    
}