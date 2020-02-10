%{
    #include<stdio.h>
    #include<string.h>
    int sum = 0;
    int num = 0;
    int count = 0;
%}

%%
[0-9] { num = num*10 + atoi(yytext);}
.|'\n' { sum+=num;num=0;count+=1; }
%%

int main()
{
    char str[100];
    fgets(str,100,stdin);
    yy_scan_string(str);
    yylex();
    sum+=num;
    printf("%f",(float)sum/(float)count);
    return 0;
}