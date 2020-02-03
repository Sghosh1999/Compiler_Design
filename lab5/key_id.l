%{
    #include<stdio.h>
    #include<string.h>
    int count_identifiers = 0;
    int count_keywords = 0;
%}

%%
auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while {printf("keyword:%s",yytext);count_keywords++;}
^[a-zA-Z_][a-zA-Z0-9]* {printf("identifier::%s",yytext);count_identifiers++;}
%%

int main(){
    char s[100];
    printf("enter string::");
    fgets(s,sizeof(s),stdin);
    yy_scan_string(s);
    yylex();
    return 0;
}