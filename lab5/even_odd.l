%{
    #include<stdio.h>
    #include<string.h>
%}

%%
^[0-9]*[24680] {printf("the number is even\n");}
^[0-9]*[13579] {printf("the number is odd\n");}
[a-zA-Z] {}
.|"\n" {}
%%
int main()
{
    char s[100];
    printf("Enter a number:");
    scanf("%s",s);
    yy_scan_string(s);
    yylex();
    return 0;
}