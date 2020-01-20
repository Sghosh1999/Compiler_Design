#include<stdio.h>

int main(){
    FILE *f;
    f = fopen("example.c","r");
    char c = '\'';
    int flag = 0;
    while(c!=EOF)
    {
        c = fgetc(f);
        if(c == '/' && flag == 0)
        {
            flag = 1;
        }
        else if(c == '/' && flag == 1)
        {
            while(c!='\n')
            {
                c = fgetc(f);
                if(c == EOF)
                    break;
            }
            flag=0;
        }
        else if(c == '*' && flag == 1)
        {
            int flag2 = 0;
            while(1)
            {
                c = fgetc(f);
                if(c == EOF)
                    break;
                if(c == '*' && flag2 == 0)
                    flag2 = 1;
                if( c == '/' && flag2 == 1 )
                    break;
            }
            flag= 0;
        }
        else if(c == EOF)
            break;
        else
        {
            flag = 0;
            printf("%c",c);
        }
    }
    return 0;
}