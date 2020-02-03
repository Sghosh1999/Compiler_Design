%{
    #include<stdio.h>
    #include<string.h>
    int count = 0;
    int char_=0;
%}
%%
[aeiouAEIOU] {printf("vowel:%s\n",yytext);char_+=yyleng;}
[0-9] {printf("number:%s\n",yytext);char_+=yyleng;}
[a-zA-Z] {printf("not vowel:%s\n",yytext);char_+=yyleng;}
[" "\n] {count++;char_+=yyleng;} 
%%


int yywrap(void);
int main(){
    char str[100];
    printf("Enter string::");
    fgets(str,sizeof(str),stdin);
    yy_scan_string(str);
    yylex();
    printf("The no. of words are:%d\n",count);
    printf("The no. of characters are:%d\n",char_);
    return 0;
}